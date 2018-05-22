#include "skeleton.h"
#include "fastFolding.h"
#include <DSPF_sp_cfftr2_dit.h>
#include <DSPF_sp_icfftr2_dif.h>
#include "bit_rev.h"

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
      output[i].real=input[i];
    }
    output[i].imag=0;
  }

  DSPF_sp_cfftr2_dit((float*)output, (float*)twiddle, Nout);

}

void fastConvolutionOverlapAddfftDone(
	ComplexFloat* input,				//FFT of input
	ComplexFloat* output,				//output samples in time
	ComplexFloat* specImpuleResponse,	//spectrum of the Impulse response
	ComplexFloat* carryBuffer,			//CarryBuffer to save the last [nCarry] values of the last Convolution
	ComplexFloat* twiddle,				//Constant TwiddleFactors in bit reversal order for the FFT
	short nIO,
	short nFFT,							//size of the FFT (must be something like k by the power of 2)
	short nCarry						//size of the CarryBuffer in ComplexFloat
){

	dotProductC(input,specImpuleResponse,output,nFFT);										//multiply with the spectrum of the filter
	int i=0;
	DSPF_sp_icfftr2_dif((float*)output, (float*)twiddle, nFFT);		//perform the inverse FFT
	for(i = 0; i < nCarry; i++){		//add the last carryBuffer to the signal and store the last [nCarry] values of the time signal in tempBuffer1 to the CarryBuffer
		output[i].real += carryBuffer[i].real;
		carryBuffer[i].real = output[nIO + i].real;
	}
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

	dotProductC(tempBuffer0,specImpuleResponse,tempBuffer1,nFFT);										//multiply with the spectrum of the filter

	DSPF_sp_icfftr2_dif((float*)tempBuffer1, (float*)twiddle, nFFT);		//perform the inverse FFT
	for(i = 0; i < nCarry; i++){		//add the last carryBuffer to the signal and store the last [nCarry] values of the time signal in tempBuffer1 to the CarryBuffer
		tempBuffer1[i].real += carryBuffer[i].real;
		carryBuffer[i].real = tempBuffer1[nFFT- nCarry + i].real;
	}
	for(i = 0; i < nIO; i++){					//put the output data to the output Buffer
		output[2 * i] = (short)(tempBuffer1[i].real * 32767 / nFFT);
		output[2*i + 1] = 0;
	}
}

void dotProductC(ComplexFloat* in0, ComplexFloat* in1, ComplexFloat* out, short nIO){
	int i=0;
	for(i=0; i < nIO; i++){
		out[i].real = (in0[i].real * in1[i].real ) - (in0[i].imag * in1[i].imag );
		out[i].imag = (in0[i].real * in1[i].imag ) + (in0[i].imag * in1[i].real );
	}
}
void dotAdditionC(ComplexFloat* inOut0, ComplexFloat* in1, float gain ,short nIO) {
	int i=0;
	for(i=0; i < nIO; i++){
			inOut0[i].real += in1[i].real;
			inOut0[i].imag += in1[i].imag;
		}
}
void dotSum3(ComplexFloat* in0, ComplexFloat* in1, ComplexFloat* in2, short* out ,float gain0, float gain1, float gain2, short nIO) {
	int i=0;
	for(i=0; i < nIO; i++){
		out[2*i]=(short)( (in0[i].real * gain0) + (in1[i].real * gain1) + (in2[i].real * gain2) );
	}
}

int abs(int in){
	if(in >= 0){
		return in;
	}else{
		return in;
	}
}

void convertToComplexFloatAndGenerateSpectrum(
  short* input,
  ComplexFloat* twiddle,
  ComplexFloat* output,
  short Nin,
  short Nout
){
  short i=0;
  for(i=0; i < Nin; i++){						//convert and copy input
  	output[i].real = (float)input[2*i]/32767;
  	output[i].imag = 0;
  }
  for(i=Nin; i < Nout; i++){					//zero padding to the size of the needed FFT (nFFT)
  	output[i].real = 0;
  	output[i].imag = 0;
  }
  DSPF_sp_cfftr2_dit((float*)output, (float*)twiddle, Nout);

}
