#ifndef fastFolding__h
#define fastFolding__h
#include "skeleton.h"

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
  );
  void generateSpectrumOnes(
    float* input,
    ComplexFloat* twiddle,
    ComplexFloat* output,
    short Nin,
    short Nout
  );


#endif
