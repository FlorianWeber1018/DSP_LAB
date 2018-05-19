#include "skeleton.h"
#include "fastFolding.h"
#include <DSPF_sp_cfftr2_dit.h>
#include <DSPF_sp_icfftr2_dif.h>
#include "bit_rev.h"



/*
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
  short i=0;
  for(i=0;i<N;i++){
    	  input[i].real /= 32767.f;
    }
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
*/
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
void fastConvolutionOverlapAdd(
	short* input,
	short* output,
	ComplexFloat* specImpuleResponse,
	ComplexFloat* carryBuffer,
	ComplexFloat* twiddle,
	ComplexFloat* tempBuffer0,
	ComplexFloat* tempBuffer1,
	short nIO,
	short nFFT,
	short nCarry
){
	int i=0;
	for(i=0; i < nIO; i++){						//convert and copy input
		tempBuffer0[i].real = (float)input[2*i]/32767;
		tempBuffer0[i].imag = 0;
	}
	for(i=nIO; i < nFFT; i++){					//zero padding to the size of the needed FFT (nFFT)
		tempBuffer0[i].real = 0;
		tempBuffer0[i].imag = 0;
	}
	DSPF_sp_cfftr2_dit((float*)tempBuffer0, (float*)twiddle, nFFT);	//perform the FFT; remember: after this operation we are in time and the values are in bitreversed order

	for(i=0; i < nFFT; i++){											//multiply with the spectrum of the filter
	    tempBuffer1[i].real = (tempBuffer0[i].real * specImpuleResponse[i].real ) - (tempBuffer0[i].imag * specImpuleResponse[i].imag );
	    tempBuffer1[i].imag = (tempBuffer0[i].real * specImpuleResponse[i].imag ) + (tempBuffer0[i].imag * specImpuleResponse[i].real );
	}

	DSPF_sp_icfftr2_dif((float*)tempBuffer1, (float*)twiddle, nFFT);		//perform the inverse FFT
	for(i = 0; i < nCarry; i++){		//add the last carryBuffer to the signal and store the last [nCarry] values of the time signal in tempBuffer1 to the CarryBuffer
		tempBuffer1[i].real += carryBuffer[i].real;
		carryBuffer[i].real = tempBuffer1[nFFT- nCarry + i].real;
	}
	for(i = 0; i < nIO; i++){					//put the output data to the output Buffer
		output[2 * i] = (short)(tempBuffer1[i].real * 32767 / (2*nFFT));
		output[2*i + 1] = 0;
	}
}
int abs(int in){
	if(in >= 0){
		return in;
	}else{
		return in;
	}
}
