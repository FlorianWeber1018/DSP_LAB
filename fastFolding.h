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
	ComplexFloat* tempBuffer0,
	ComplexFloat* tempBuffer1,
	short nIO,							//size of the Input/output array interpreted as Complex Float
	short nFFT,							//size of the FFT (must be something like k by the power of 2)
	short nCarry						//size of the CarryBuffer in ComplexFloat
);
void fastConvolutionOverlapAddfftDone(
	ComplexFloat* input,				//FFT of input
	ComplexFloat* output,				//output samples in time
	ComplexFloat* specImpuleResponse,	//spectrum of the Impulse response
	ComplexFloat* carryBuffer,			//CarryBuffer to save the last [nCarry] values of the last Convolution
	ComplexFloat* twiddle,				//Constant TwiddleFactors in bit reversal order for the FFT
	short nIO,
	short nFFT,							//size of the FFT (must be something like k by the power of 2)
	short nCarry						//size of the CarryBuffer in ComplexFloat
);
void dotProductC(
	ComplexFloat* in0,
	ComplexFloat* in1,
	ComplexFloat* out,
	short nIO
);
void dotAdditionC(
	ComplexFloat* inOut0,
	ComplexFloat* in1,
	float gain,
	short nIO
);
void dotSum3(
	ComplexFloat* in0,
	ComplexFloat* in1,
	ComplexFloat* in2,
	short* out,
	float gain0,
	float gain1,
	float gain2,
	short nIO
);
void convertToComplexFloatAndGenerateSpectrum(
  short* input,
  ComplexFloat* twiddle,
  ComplexFloat* output,
  short Nin,
  short Nout
);
void copyC(
	ComplexFloat* src,
	ComplexFloat* dest,
	short size
);
int abs(int in);
#endif
