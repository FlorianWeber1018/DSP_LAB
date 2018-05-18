#ifndef fastFolding__h
#define fastFolding__h
#include "skeleton.h"
/*
  void processFastFolding(
  ComplexFloat* input,
  ComplexFloat* twiddle,
  ComplexFloat* impuleResponseSpecFilter,
  ComplexFloat* output,
  short N
  );
  void convertShortBufferToComplexFloatAndInsulateFirstChannel(
    short* input,
  	ComplexFloat* output,
  	short N
  );
  void convertComplexFloatBufferToShort(
      ComplexFloat* input,
	  short* output,
	  short N
  );*/
  void generateSpectrumOnes(
    float* input,
    ComplexFloat* twiddle,
    ComplexFloat* output,
    short Nin,
    short Nout
  );

void fastConvolutionOverlapAdd(
	short* input,						//input samples
	short* output,						//output samples
	ComplexFloat* specImpuleResponse,	//spectrum of the Impulse response
	ComplexFloat* carryBuffer,			//CarryBuffer to save the last [nCarry] values of the last Convolution
	ComplexFloat* twiddle,				//Constant TwiddleFactors in bit reversal order for the FFT
	ComplexFloat* tempBuffer0,			//tempBuffer0 (used for storing the input)
	ComplexFloat* tempBuffer1,			//tempBuffer1 (used for storing the output after multiplication)
	short nIO,							//size of the Input/output array interpreted as Complex Float
	short nFFT,							//size of the FFT (must be something like k by the power of 2)
	short nCarry						//size of the CarryBuffer in ComplexFloat
);
int abs(int in);
#endif
