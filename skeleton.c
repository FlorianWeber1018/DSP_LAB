/***********************************************************
*  skeleton.c
*  Example for ping-pong processing
*  Caution: It is intended, that this file ist not runnable.
*  The file contains mistakes and omissions, which shall be
*  corrected and completed by the students.
*
*   F. Quint, HsKA
************************************************************/
#include "skeleton.h"

#include "BIOS_configcfg.h"

#include <csl.h>
#include <csl_mcbsp.h>
#include <csl_irq.h>
#include <csl_edma.h>

//include AIC23 settings
#include "config_AIC23.h"

//#include <dsk6713.h>
#include <dsk6713_led.h>
#include <dsk6713_dip.h>

//SECTION SIN/COS LOOKUP-TABLES BEGIN




/**
 * Buffer for filters in external file
 */
#define BUFFER_LEN 512
#define N ( BUFFER_LEN / 2 )
//SECTION IN/OUT BUFFER BEGIN

/* Ping-Pong buffers. Place them in the compiler section .datenpuffer */
/* How do you place the compiler section in the memory?     */
#pragma DATA_SECTION(Buffer_in_ping, ".datenpuffer");
short Buffer_in_ping[BUFFER_LEN];
#pragma DATA_SECTION(Buffer_in_pong, ".datenpuffer");
short Buffer_in_pong[BUFFER_LEN];
#pragma DATA_SECTION(Buffer_out_ping, ".datenpuffer");
short Buffer_out_ping[BUFFER_LEN];
#pragma DATA_SECTION(Buffer_out_pong, ".datenpuffer");
short Buffer_out_pong[BUFFER_LEN];
//SECTION IN/OUT BUFFER END

//Configuration for McBSP1 (data-interface)		---- pdf: csl_spru401j
MCBSP_Config datainterface_config = {
		/* McBSP Control Register */
        MCBSP_FMKS(SPCR, FREE, NO)              |	// Freilauf
        MCBSP_FMKS(SPCR, SOFT, YES)	            |	// 	(yes/NO)?? yes zu ende f�hren des serial port			*******--serial port clock stops after completion of current transmission.????????
													//
        MCBSP_FMKS(SPCR, FRST, YES)             |	// Framesync ist ein
        MCBSP_FMKS(SPCR, GRST, YES)             |	// Reset aus, damit l�uft der Samplerate- Generator
        MCBSP_FMKS(SPCR, XINTM, XRDY)           |	// 				*******-- XINT is generated on every serial element by tracking the XRDY bits in SPCR (Interrupt in EDMA)
																	//*****xrdy interrupt flag nach einem word
        MCBSP_FMKS(SPCR, XSYNCERR, NO)          |	// empf�ngerseitig keine �berwachung der Synchronisation
        MCBSP_FMKS(SPCR, XRST, YES)             |	// Sender l�uft (kein Reset- Status)
        MCBSP_FMKS(SPCR, DLB, OFF)              |	// Loopback (Kurschluss) nicht aktiv
        MCBSP_FMKS(SPCR, RJUST, RZF)            |	// rechtsb�ndige Ausrichtung der Daten im Puffer
        MCBSP_FMKS(SPCR, CLKSTP, DISABLE)       |	// Clock startet ohne Verz�gerung auf fallenden Flanke (siehe auch PCR-Register)
        MCBSP_FMKS(SPCR, DXENA, OFF)            |	// DX- Enabler wird nicht verwendet
        MCBSP_FMKS(SPCR, RINTM, RRDY)           |	// Sender Interrupt wird durch "RRDY-Bit" ausgel�st
        MCBSP_FMKS(SPCR, RSYNCERR, NO)          |	// senderseitig keine �berwachung der Synchronisation
        MCBSP_FMKS(SPCR, RRST, YES),			// Empf�nger l�uft (kein Reset- Status)
		/* Empfangs-Control Register */
        MCBSP_FMKS(RCR, RPHASE, SINGLE)         |	// Nur eine Phase pro Frame
        MCBSP_FMKS(RCR, RFRLEN2, DEFAULT)       |	// L�nge in Phase 2, unrelevant
        MCBSP_FMKS(RCR, RWDLEN2, DEFAULT)       |	// Wortl�nge in Phase 2, unrelevant
        MCBSP_FMKS(RCR, RCOMPAND, MSB)          |	// kein Compandierung der Daten (MSB first)
        MCBSP_FMKS(RCR, RFIG, NO)               |	// Rahmensynchronisationspulse (nach dem ersten Puls)) startet die �bertragung neu
        MCBSP_FMKS(RCR, RDATDLY, 0BIT)          |	// keine Verz�gerung (delay) der Daten
        MCBSP_FMKS(RCR, RFRLEN1, OF(1))         |	// L�nge der Phase 1 --> 1 Wort
        MCBSP_FMKS(RCR, RWDLEN1, 16BIT)         |	// 				*******-- Receive word length is 16 bits.
        MCBSP_FMKS(RCR, RWDREVRS, DISABLE),		// 32-bit Reversal nicht genutzt
		/* Sende-Control Register */
        MCBSP_FMKS(XCR, XPHASE, SINGLE)         |	// -- Single-phase frame
        MCBSP_FMKS(XCR, XFRLEN2, DEFAULT)       |	// L�nge in Phase 2, unrelevant
        MCBSP_FMKS(XCR, XWDLEN2, DEFAULT)       |	// Wortl�nge in Phase 2, unrelevant
        MCBSP_FMKS(XCR, XCOMPAND, MSB)          |	// kein Compandierung der Daten (MSB first)
        MCBSP_FMKS(XCR, XFIG, NO)               |	// Rahmensynchronisationspulse (nach dem ersten Puls)) startet die �bertragung neu
        MCBSP_FMKS(XCR, XDATDLY, 0BIT)          |	// keine Verz�gerung (delay) der Daten
        MCBSP_FMKS(XCR, XFRLEN1, OF(1))         |	// L�nge der Phase 1 --> 1 Wort
        MCBSP_FMKS(XCR, XWDLEN1, 16BIT)         |	// Wortl�nge in Phase 1 --> 16 bit
        MCBSP_FMKS(XCR, XWDREVRS, DISABLE),		// 32-bit Reversal nicht genutzt
		/* Sample Rate Generator Register */
        MCBSP_FMKS(SRGR, GSYNC, DEFAULT)        |	// Einstellungen nicht relevant da
        MCBSP_FMKS(SRGR, CLKSP, DEFAULT)        |	// der McBSP1 als Slave l�uft
        MCBSP_FMKS(SRGR, CLKSM, DEFAULT)        |	// und den Takt von aussen
        MCBSP_FMKS(SRGR, FSGM, DXR2XSR)         |	// vorgegeben bekommt. -- Transmit frame-sync signal (FSX) due to DXR-to-XSR copy.When FSGM = 0, FWID bit and FPER bit are ignored.
        MCBSP_FMKS(SRGR, FPER, DEFAULT)         |	// --
        MCBSP_FMKS(SRGR, FWID, DEFAULT)         |	// --
        MCBSP_FMKS(SRGR, CLKGDV, DEFAULT),		// --
		/* Mehrkanal */
        MCBSP_MCR_DEFAULT,				// Mehrkanal wird nicht verwendet
        MCBSP_RCER_DEFAULT,				// dito
        MCBSP_XCER_DEFAULT,				// dito
		/* Pinout Control Register */
        MCBSP_FMKS(PCR, XIOEN, SP)              |	// Pin wird f�r serielle Schnittstelle verwendet (alternativ GPIO)
        MCBSP_FMKS(PCR, RIOEN, SP)              |	// Pin wird f�r serielle Schnittstelle verwendet (alternativ GPIO)
        MCBSP_FMKS(PCR, FSXM, EXTERNAL)         |	// Framesync- Signal f�r Sender kommt von extern (Slave)
        MCBSP_FMKS(PCR, FSRM, EXTERNAL)         |	// Framesync- Signal f�r Empf�nger kommt von extern (Slave)
        MCBSP_FMKS(PCR, CLKXM, INPUT)           |	// Takt f�r Sender kommt von extern (Slave)
        MCBSP_FMKS(PCR, CLKRM, INPUT)           |	// Takt f�r Empf�nger kommt von extern (Slave)
        MCBSP_FMKS(PCR, CLKSSTAT, DEFAULT)      |	// unrelevant da PINS keine GPIOs
        MCBSP_FMKS(PCR, DXSTAT, DEFAULT)        |	// unrelevant da PINS keine GPIOs
        MCBSP_FMKS(PCR, FSXP, ACTIVEHIGH)       |	// Framesync senderseitig ist "activehigh"
        MCBSP_FMKS(PCR, FSRP, ACTIVEHIGH)       |	// Framesync empf�ngerseitig ist "activehigh"
        MCBSP_FMKS(PCR, CLKXP, FALLING)         |	// Datum wird bei fallender Flanke gesendet
        MCBSP_FMKS(PCR, CLKRP, RISING)			// Datum wird bei steigender Flanke �bernommen
};

/* template for a EDMA configuration */
EDMA_Config configEDMARcv = {
    EDMA_FMKS(OPT, PRI, LOW)           |  // auf beide Queues verteilen
    EDMA_FMKS(OPT, ESIZE, 16BIT)       |  // Element size 				******--aus skript
    EDMA_FMKS(OPT, 2DS, NO)            |  // kein 2D-Transfer
    EDMA_FMKS(OPT, SUM, NONE)          |  // Quell-update mode -> FEST (McBSP)!!!
    EDMA_FMKS(OPT, 2DD, NO)            |  // 2kein 2D-Transfer
    EDMA_FMKS(OPT, DUM, INC)           |  // Ziel-update mode 			*******--  increment
    EDMA_FMKS(OPT, TCINT,YES)          |  // EDMA interrupt erzeugen? 	***********-- ja
    EDMA_FMKS(OPT, TCC, OF(0))         |  // Transfer complete code (TCC)
    EDMA_FMKS(OPT, LINK, YES)          |  // Link Parameter nutzen?
    EDMA_FMKS(OPT, FS, NO),               // Frame Sync nutzen?

    EDMA_FMKS(SRC, SRC, OF(0)),           // Quell-Adresse

    EDMA_FMK (CNT, FRMCNT, NULL)       |  // Anzahl Frames
    EDMA_FMK (CNT, ELECNT, BUFFER_LEN),   // Anzahl Elemente

    (Uint32)Buffer_in_ping,       		    // Ziel-Adresse

    EDMA_FMKS(IDX, FRMIDX, DEFAULT)    |  // Frame index Wert
    EDMA_FMKS(IDX, ELEIDX, DEFAULT),      // Element index Wert

    EDMA_FMK (RLD, ELERLD, NULL)       |  // Reload Element
    EDMA_FMK (RLD, LINK, NULL)            // Reload Link
};

//kopiert von hier.... kopier fehler
EDMA_Config configEDMAXmt = {
EDMA_FMKS(OPT, PRI, LOW)           |  // auf beide Queues verteilen
EDMA_FMKS(OPT, ESIZE, 16BIT)       |  // Element size 				******--aus skript
EDMA_FMKS(OPT, 2DS, NO)            |  // kein 2D-Transfer
EDMA_FMKS(OPT, SUM, INC)           |  // Quell-update mode -> FEST (McBSP)!!! doch nicht fest!!
EDMA_FMKS(OPT, 2DD, NO)            |  // 2kein 2D-Transfer
EDMA_FMKS(OPT, DUM, NONE)          |  // Ziel-update mode 			*******--  increment doch nicht!!!
EDMA_FMKS(OPT, TCINT,YES)          |  // EDMA interrupt erzeugen? 	***********-- ja
EDMA_FMKS(OPT, TCC, OF(0))         |  // Transfer complete code (TCC)
EDMA_FMKS(OPT, LINK, YES)          |  // Link Parameter nutzen?
EDMA_FMKS(OPT, FS, NO),               // Frame Sync nutzen?

EDMA_FMKS(SRC, SRC, OF(0)),           // Quell-Adresse

EDMA_FMK (CNT, FRMCNT, NULL)       |  // Anzahl Frames
EDMA_FMK (CNT, ELECNT, BUFFER_LEN),   // Anzahl Elemente

(Uint32)Buffer_in_ping,       		  // Ziel-Adresse   Zur Laufzeit zur Pong-Adresse �ndern

EDMA_FMKS(IDX, FRMIDX, DEFAULT)    |  // Frame index Wert
EDMA_FMKS(IDX, ELEIDX, DEFAULT),      // Element index Wert

EDMA_FMK (RLD, ELERLD, NULL)       |  // Reload Element
EDMA_FMK (RLD, LINK, NULL)            // Reload Link
};
//bis hier



/* Transfer-Complete-Codes for EDMA-Jobs */
int tccRcvPing; //-lesen pingpong
int tccRcvPong;
int tccXmtPing; //-schreiben pingpong
int tccXmtPong;

/* EDMA-Handles; are these really all? */
EDMA_Handle hEdmaRcv; // lesen edma
EDMA_Handle hEdmaXmt; //schreiben edma
EDMA_Handle hEdmaReloadRcvPing; // f�r freien parameterplatz
EDMA_Handle hEdmaReloadXmtPing; // f�r freien parameterplatz
EDMA_Handle hEdmaReloadRcvPong; // f�r freien parameterplatz
EDMA_Handle hEdmaReloadXmtPong; // f�r freien parameterplatz

MCBSP_Handle hMcbsp;  // erstellen eines McBSP, handle ist eine Struktur

main()
{
	hMcbsp=0;//zuruecksetzen von handle
	//buildSpecsOfFilters();
	//genResultingSpecs();


	int i=0;



	CSL_init();

	/* Configure McBSP0 and AIC23 */ 	//aic23	-->	audio
	Config_DSK6713_AIC23();

	/* Configure McBSP1*/
	hMcbsp = MCBSP_open(MCBSP_DEV1, MCBSP_OPEN_RESET);
    MCBSP_config(hMcbsp, &datainterface_config); //&datainterface_config oben definiert

	/* configure EDMA */
    config_EDMA();

    /* finally the interrupts */
    config_interrupts();


    MCBSP_start(hMcbsp,  MCBSP_RCV_START | MCBSP_XMIT_START | MCBSP_SRGR_START | MCBSP_SRGR_FRAMESYNC, 220); 		//-- siehe script

    MCBSP_write(hMcbsp, 0x0); 	/* one shot */


    /*LED*/
    /* Initialize the board support library, must be first BSL call */
    //DSK6713_init();
    /* Initialize the LED and DIP switch modules of the BSL */
    DSK6713_LED_init();
    DSK6713_DIP_init();


    for(i=0; i<3; i++){
    	DSK6713_LED_off(i);
    }
} /* finished*/

void config_EDMA(void)
{


	/* Konfiguration der EDMA zum Lesen*/
	hEdmaRcv = EDMA_open(EDMA_CHA_REVT1, EDMA_OPEN_RESET);  // EDMA Channel for REVT1
	hEdmaReloadRcvPing = EDMA_allocTable(-1);               // Reload-Parameters  --freier platz mit -1 , er sucht sich selbst den speicherplatz
	hEdmaReloadRcvPong = EDMA_allocTable(-1);               // Reload-Parameters  --freier platz mit -1 , er sucht sich selbst den speicherplatz

	configEDMARcv.src = MCBSP_getRcvAddr(hMcbsp);          //  source addr

	//ping
	tccRcvPing = EDMA_intAlloc(-1);                        // next available TCC
	configEDMARcv.opt |= EDMA_FMK(OPT,TCC,tccRcvPing);     // set it  --verodert freier tcc variable
	configEDMARcv.dst = ((int)Buffer_in_ping);
	/* configure */  /* Erster Transfer und Reload-Ping */
	EDMA_config(hEdmaRcv, &configEDMARcv);				// schreibt die Daten die zuvor festgelegt worden sind
	EDMA_config(hEdmaReloadRcvPing, &configEDMARcv);


	//pong
	tccRcvPong = EDMA_intAlloc(-1);                        // next available TCC
	configEDMARcv.opt |= EDMA_FMK(OPT,TCC,tccRcvPong);     // set it  --verodert freier tcc variable
	configEDMARcv.dst = ((int)Buffer_in_pong);
	/* configure */
	// schreibt die Daten die zuvor festgelegt worden sind
	EDMA_config(hEdmaReloadRcvPong, &configEDMARcv);/* Erster Transfer und Reload-Ping */


	/* link transfers ping -> pong -> ping */
	EDMA_link(hEdmaRcv,hEdmaReloadRcvPong);  /* is that all? */
	EDMA_link(hEdmaReloadRcvPing,hEdmaReloadRcvPong); //Reload die funktion wird neu aufgerufen und ein neuer freier speicher platz im edma gesucht
	EDMA_link(hEdmaReloadRcvPong,hEdmaReloadRcvPing);



	/* Konfiguration der EDMA zum Schreiben*/
	hEdmaXmt = EDMA_open(EDMA_CHA_XEVT1, EDMA_OPEN_RESET);  // EDMA Channel for Xmt1
	hEdmaReloadXmtPing = EDMA_allocTable(-1);               // Reload-Parameters  --freier platz mit -1 , er sucht sich selbst den speicherplatz
	hEdmaReloadXmtPong = EDMA_allocTable(-1);               //	hEdmaReload = EDMA_allocTable(-1);               // Reload-Parameters  --freier platz mit -1 , er sucht sich selbst den speicherplatz


	configEDMAXmt.dst = MCBSP_getXmtAddr(hMcbsp);          //  source addr

	//ping
	tccXmtPing = EDMA_intAlloc(-1);                        // next available TCC
	configEDMAXmt.opt |= EDMA_FMK(OPT,TCC,tccXmtPing);     // set it  --verodert freier tcc variable
	configEDMAXmt.src = ((int)Buffer_out_ping);
	/* configure */
	EDMA_config(hEdmaXmt, &configEDMAXmt);
	EDMA_config(hEdmaReloadXmtPing, &configEDMAXmt);

	//pong
	tccXmtPong = EDMA_intAlloc(-1);                        // next available TCC
	configEDMAXmt.opt |= EDMA_FMK(OPT,TCC,tccXmtPong);     // set it  --verodert freier tcc variable
	configEDMAXmt.src = ((int)Buffer_out_pong);
	/* configure */
	EDMA_config(hEdmaReloadXmtPong, &configEDMAXmt);
	//bis hier

	/* link transfers ping -> pong -> ping */
	EDMA_link(hEdmaXmt,hEdmaReloadXmtPong);  /* is that all? */
	EDMA_link(hEdmaReloadXmtPong,hEdmaReloadXmtPing); //Reload die funktion wird neu aufgerufen und ein neuer freier speicher platz im edma gesucht
	EDMA_link(hEdmaReloadXmtPing,hEdmaReloadXmtPong);

	/* enable EDMA TCC */
	//receive ping
	EDMA_intClear(tccRcvPing);
	EDMA_intEnable(tccRcvPing);
	//receive pong
	EDMA_intClear(tccRcvPong);
	EDMA_intEnable(tccRcvPong);
	//transmit ping
	EDMA_intClear(tccXmtPing);
	EDMA_intEnable(tccXmtPing);
	//transmit pong
	EDMA_intClear(tccXmtPong);
	EDMA_intEnable(tccXmtPong);

	/* which EDMAs */
	EDMA_enableChannel(hEdmaRcv);
	EDMA_enableChannel(hEdmaXmt);
}

void config_interrupts(void)
{
	IRQ_map(IRQ_EVT_EDMAINT, 8);
	IRQ_clear(IRQ_EVT_EDMAINT);
	IRQ_enable(IRQ_EVT_EDMAINT);
	IRQ_globalEnable();
}


void EDMA_interrupt_service(void)
{

	static int rcvPingDone=0;
	static int rcvPongDone=0;
	static int xmtPingDone=0;
	static int xmtPongDone=0;

	if(EDMA_intTest(tccRcvPing))
	{
		EDMA_intClear(tccRcvPing);		/* clear is mandatory */
		rcvPingDone=1;
	}
	else if(EDMA_intTest(tccRcvPong))				// selbe f�r pong
	{
		EDMA_intClear(tccRcvPong);
		rcvPongDone=1;
	}
	if(EDMA_intTest(tccXmtPing))				// selbe f�r xmtping
	{
		EDMA_intClear(tccXmtPing);
		xmtPingDone=1;
	}
	else if(EDMA_intTest(tccXmtPong))				// selbe f�r xmtpong
	{
		EDMA_intClear(tccXmtPong);
		xmtPongDone=1;
	}

	if(rcvPingDone && xmtPingDone) {
		rcvPingDone=0;
		xmtPingDone=0;
		// processing in SWI
		SWI_post(&Ping_SWI);
	}
	else if(rcvPongDone && xmtPongDone) {
		rcvPongDone=0;
		xmtPongDone=0;
		// processing in SWI
		SWI_post(&Pong_SWI);
	}
}

void process_ping_SWI(void)
{
	int i=0;
	for(i=0;i < N; i++){
		((StereoShort*)Buffer_out_ping)[i].left = ((StereoShort*)Buffer_in_ping)[i].left;
		((StereoShort*)Buffer_out_ping)[i].right = ((StereoShort*)Buffer_in_ping)[i].right;
	}
}
/*------------------------------------------------------------------
 * Trennung von PING/PONG
 * -----------------------------------------------------------------*/
void process_pong_SWI(void)
{
	int i = 0;
	for(i = 0;i < N; i++){
		((StereoShort*)Buffer_out_pong)[i].left = ((StereoShort*)Buffer_in_pong)[i].left;
		((StereoShort*)Buffer_out_pong)[i].right = ((StereoShort*)Buffer_in_pong)[i].right;
	}
}

void SWI_LEDToggle(void)
{
	SEM_postBinary(&SEM_LEDToggle); //dspbios datasheet
}

void tsk_led_toggle(void)
{
	/* initializatoin of the task */
	/* nothing to do */

	/* process */
	while(1)
	{
		SEM_pendBinary(&SEM_LEDToggle, SYS_FOREVER);

		DSK6713_LED_toggle(1);
	}
}
