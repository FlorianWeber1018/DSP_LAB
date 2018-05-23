#ifndef SKELETON_H
#define SKELETON_H

//double lut(unsigned int *iterator, double *lut, unsigned int lut_len);


typedef struct{
	float real;
	float imag;
} ComplexFloat;

//void fir4khzringbuffer_push(complex_double value);
//complex_double fir4khzringbuffer_arr(unsigned int iter);
//complex_double fir4khz_filter(complex_double value);

extern void process_ping_SWI(void);
extern void process_pong_SWI(void);
extern void EDMA_interrupt_service(void);
extern void config_EDMA(void);
extern void config_interrupts(void);
extern void SWI_LEDToggle(void);
extern void tsk_led_toggle(void);

void process(short* BufferIn, short* BufferOut);

void initBuffers();
#endif /*SKELETON_H*/
