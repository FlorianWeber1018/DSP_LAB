#include "skeleton.h"

#include <DSPF_sp_cfftr2_dit.h>
#include <DSPF_sp_icfftr2_dif.h>
#include <DSPF_sp_bitrev_cplx.h>


 ComplexFloat* convertShortBufferToComplexFloatAndInsulateFirstChannel(
    short* input,
    short N
  ){
  ComplexFloat* output = (ComplexFloat*)input;
  short i=0;
  for(i=0;i<N;i++){
    output[i].imag=0;
    output[i].real=(float)input[i];
  }
  return output;
}
void processFastFolding(
  ComplexFloat* input,
  ComplexFloat* twiddle,
  ComplexFloat* impuleResponseSpecFilter,
  ComplexFloat* output,
  short N
){
  short i=0;
  DSPF_sp_cfftr2_dit((float*)input, (float*)twiddle, N);
 /* for(i=0;i<N;i++){
    output[i].real = (input[i].real * impuleResponseSpecFilter[i].real )
                    -(input[i].imag * impuleResponseSpecFilter[i].imag );
    output[i].imag = (input[i].real * impuleResponseSpecFilter[i].imag )
                    -(input[i].imag * impuleResponseSpecFilter[i].real );
  }*/
  DSPF_sp_icfftr2_dif((float*)output, (float*)twiddle, N);
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
      output[i].real=input[i];
    }
    output[i].imag=0;
  }

  DSPF_sp_cfftr2_dit((float*)input, (float*)twiddle, Nout);
}
