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
  ComplexFloat* convertShortBufferToComplexFloatAndInsulateFirstChannel(
    short* input,
    short N
  );

  void generateSpectrumOnes(
    float* input,
    ComplexFloat* twiddle,
    ComplexFloat* output,
    short Nin,
    short Nout
  );
  void gen_w_r2(ComplexFloat* twiddle, short N);
  void bit_rev(ComplexFloat* target, short N);
#endif
