#include "skeleton.h"
#include "fastFolding.h"
#include <DSPF_sp_cfftr2_dit.h>
#include <DSPF_sp_icfftr2_dif.h>
#include "bit_rev.h"




void convertShortBufferToComplexFloatAndInsulateFirstChannel(
    short* input,
	ComplexFloat* output,
	short N
)
{
  short i=0;
  for(i=0;i<N;i++){
	output[i].real=(float)input[2*i];
    output[i].imag=0;
  }
}
void convertComplexFloatBufferToShort(
      ComplexFloat* input,
	  short* output,
	  short N
 )
{
	int i;
	for(i=0;i<N;i++){
		output[2*i]=input[i].real;
	}
}
void processFastFolding(
  ComplexFloat* input,
  ComplexFloat* twiddle,
  ComplexFloat* impuleResponseSpecFilter,
  ComplexFloat* output,
  short N
){
  short i=0;/*
  for(i=0;i<N;i++){
    	  input[i].real /= 32767.f;
    }*/
  DSPF_sp_cfftr2_dit((float*)input, (float*)twiddle, N);

  for(i=0;i<N;i++){
    output[i].real = (input[i].real * impuleResponseSpecFilter[i].real ) - (input[i].imag * impuleResponseSpecFilter[i].imag );
    output[i].imag = (input[i].real * impuleResponseSpecFilter[i].imag ) + (input[i].imag * impuleResponseSpecFilter[i].real );
  }

  DSPF_sp_icfftr2_dif((float*)output, (float*)twiddle, N);

  for(i=0;i<N;i++){
  	  output[i].real /= (float)N;
  }
  for(i=0;i<N;i++){
    output[i].imag=0;
  }
}
void generateSpectrumOnes(
  float* input,
  ComplexFloat* twiddle,
  ComplexFloat* output,
  short Nin,
  short Nout
){
  short i=0;
  for(i=0;i<Nout;i++){
    if(i>=Nin){
      output[i].real=0;
    }else{
      output[i].real=1;
    }
    output[i].imag=0;
  }

  DSPF_sp_cfftr2_dit((float*)output, (float*)twiddle, Nout);

}
