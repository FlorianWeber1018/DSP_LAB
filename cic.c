#include "cic.h"

void integrate(
  ComplexInt* BufferIn,
  ComplexInt* BufferOut,
  short BufferSize,
  ComplexInt* LastOutVal
){
  short i=0;
  BufferOut[0].real = BufferIn[0].real + LastOutVal->real;
  BufferOut[0].imag = BufferIn[0].imag + LastOutVal->imag;

  for(i=1; i < BufferSize; i++){
    BufferOut[i].real = BufferIn[i].real + BufferOut[i-1].real;
    BufferOut[i].imag = BufferIn[i].imag + BufferOut[i-1].imag;
  }
  LastOutVal->real = BufferOut[ BufferSize - 1 ].real;
  LastOutVal->imag = BufferOut[ BufferSize - 1 ].imag;
}
void differentiate(
  ComplexInt* BufferIn,
  ComplexInt* BufferOut,
  short BufferSize,
  ComplexInt* LastInVal
){
  short i=0;
  BufferOut[0].real = BufferIn[0].real - LastInVal->real;
  BufferOut[0].imag = BufferIn[0].imag - LastInVal->imag;
  for(i=1; i < BufferSize; i++){
    BufferOut[i].real = BufferIn[i].real - BufferIn[i-1].real;
    BufferOut[i].imag = BufferIn[i].imag - BufferIn[i-1].imag;
  }
  LastInVal->real = BufferIn[ BufferSize - 1 ].real;
  LastInVal->imag = BufferIn[ BufferSize - 1 ].imag;
}
void downSample(
  ComplexInt* BufferIn,
  ComplexInt* BufferOut,
  short BufferSizeOut,
  short SampleRateDivider
){
  short i=0;
  for(i=0; i < BufferSizeOut; i++){
    BufferOut[i].real = BufferIn[ i * SampleRateDivider].real;
    BufferOut[i].imag = BufferIn[ i * SampleRateDivider].imag;
  }
}
void upSample(
  ComplexInt* BufferIn,
  ComplexInt* BufferOut,
  short BufferSizeOut,
  short SampleRateMultiplikator
){
  short i=0;
  for(i=0; i < BufferSizeOut; i ++){
    BufferOut[i].real = 0;
    BufferOut[i].imag = 0;
  }
  for(i=0; i < BufferSizeOut; i += SampleRateMultiplikator){
    BufferOut[i].real = BufferIn[ i / SampleRateMultiplikator ].real;
    BufferOut[i].imag = BufferIn[ i / SampleRateMultiplikator ].imag;
  }
}


/*
void integrate(
  StereoFloat* BufferIn,
  StereoFloat* BufferOut,
  short BufferSize,
  StereoFloat* LastOutVal
){
  int i=0;
  BufferOut[0].left = BufferIn[0].left + LastOutVal->left;
  for(i=1; i < BufferSize; i++){
    BufferOut[i].left = BufferIn[i].left + BufferOut[i-1].left;
  }
  LastOutVal->left = BufferOut[ BufferSize - 1 ].left;
}

void differentiate(
  StereoFloat* BufferIn,
  StereoFloat* BufferOut,
  short BufferSize,
  StereoFloat* LastInVal
){
  int i=0;
  BufferOut[0].left = BufferIn[0].left - LastInVal->left;
  for(i=1; i < BufferSize; i++){
    BufferOut[i].left = BufferIn[i].left - BufferIn[i-1].left;
  }
  LastInVal->left = BufferIn[ BufferSize - 1 ].left;
}
void downSample(
  StereoFloat* BufferIn,
  StereoFloat* BufferOut,
  short BufferSizeOut,
  short SampleRateDivider
){
  int i=0;
  for(i=0; i < BufferSizeOut; i++){
    BufferOut[i].left = BufferIn[ i * SampleRateDivider].left;
  }
}
void upSample(
  StereoFloat* BufferIn,
  StereoFloat* BufferOut,
  short BufferSizeOut,
  short SampleRateMultiplikator
){
  int i=0;
  for(i=0; i < BufferSizeOut; i += 48){
    BufferOut[i].left = BufferIn[ i / SampleRateMultiplikator ].left;
  }
}
void StereoFir(
	StereoFloat* inBuffer,
 	StereoFloat* outBuffer,
 	short bufferSize,
 	StereoFloat* carryBuffer,
 	float* coef,
 	short coefSize
){
	short i=0;
	short j=0;
	for(i=0; i < bufferSize; i++){
		outBuffer[i].left = 0;
		outBuffer[i].right = 0;
		for(j=0;j<coefSize;j++){
			if(i-j >= 0){
				outBuffer[i].left += inBuffer[i-j].left * coef[j];
				outBuffer[i].right += inBuffer[i-j].right * coef[j];
			}else{
				outBuffer[i].left += carryBuffer[coefSize + i - j].left * coef[j];
				outBuffer[i].right += carryBuffer[coefSize + i - j].right * coef[j];
			}
	   }
	 }
	 // * Save the last (coefSize) values of inBuffer for next processing
	 for( i=0; i<coefSize; i++){
		  carryBuffer[i].left = inBuffer[i + bufferSize - coefSize].left;
		  carryBuffer[i].right = inBuffer[i + bufferSize - coefSize].right;
	 }

}*/
void ToComplexInt(
	StereoShort* in,
	ComplexInt* out,
	short bufferSize
){
	int i=0;
	for (i=0;i<bufferSize;i++){
		out[i].real = (int)(in[i].left) / 16;
    out[i].imag = 0;
	}
}
void ToShort(
	ComplexInt* in,
	StereoShort* out,
	short bufferSize
){
	int i=0;

	for (i=0;i<bufferSize;i++){
		out[i].left = (short)(in[i].real /4);
		out[i].right = 0;
	}
}
void mulLookup(
  ComplexInt* in,
  ComplexInt* out,
  short bufferSize,
  ComplexInt* lookupTable,
  int DCgain,
  short lookupTableSize,
  short* currentindex
){
  short i=0;
  for(i=0; i<bufferSize; i++){
    out[i].real = ((lookupTable[*currentindex].real * in[i].real )
      - (lookupTable[*currentindex].imag * in[i].imag ))/DCgain;
    out[i].imag = ((lookupTable[*currentindex].real * in[i].imag )
      + (lookupTable[*currentindex].imag * in[i].real ))/DCgain;
    *currentindex ++;
    if(*currentindex >= lookupTableSize ){
      *currentindex = 0;
    }
  }
}
void initComplexInt(ComplexInt* data){
  data->real=0;
  data->imag=0;
}
