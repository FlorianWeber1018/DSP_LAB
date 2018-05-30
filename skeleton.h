#ifndef SKELETON_H
#define SKELETON_H


extern void process_ping_SWI(void);
extern void process_pong_SWI(void);
extern void EDMA_interrupt_service(void);
extern void config_EDMA(void);
extern void config_interrupts(void);
extern void SWI_LEDToggle(void);
extern void tsk_led_toggle(void);
void process(
	short* BufferIn,
	short* BufferOut
);
void initBuffers();

#endif /*SKELETON_H*/
