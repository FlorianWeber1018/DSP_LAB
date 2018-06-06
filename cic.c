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

void ToComplexInt(
	StereoShort* in,
	ComplexInt* out,
	short bufferSize
){
	int i=0;
	for (i=0;i<bufferSize;i++){
		out[i].real = (int)(in[i].left) ;
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
		out[i].left = (short)(in[i].real);///110592);
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
    (*currentindex)++;
    if(*currentindex >= lookupTableSize ){
      *currentindex = 0;
    }
  }
}
void initComplexInt(ComplexInt* data){
  data->real=0;
  data->imag=0;
}

void ComplexFir(
	ComplexInt* inBuffer,
 	ComplexInt* outBuffer,
 	short bufferSize,
 	ComplexInt* carryBuffer,
 	int* coef,
 	short coefSize,
	long DCgain
){
	short i=0;
	short j=0;
  long tempReal=0;
  long tempImag=0;
	for(i=0; i < bufferSize; i++){
		tempReal = 0;
		tempImag = 0;
		for(j=0;j<coefSize;j++){
			if(i-j >= 0){
				tempReal += inBuffer[i-j].real * coef[j];
				tempImag += inBuffer[i-j].imag * coef[j];
			}else{
				tempReal += carryBuffer[coefSize + i - j].real * coef[j];
				tempImag += carryBuffer[coefSize + i - j].imag * coef[j];
			}
		}
		outBuffer[i].real = (int)(tempReal / DCgain);
		outBuffer[i].imag = (int)(tempImag / DCgain);
	}
	// * Save the last (coefSize) values of inBuffer for next processing
	for( i=0; i<coefSize; i++){
		carryBuffer[i].real = inBuffer[i + bufferSize - coefSize].real;
		carryBuffer[i].imag = inBuffer[i + bufferSize - coefSize].imag;
	}
}
void stupidMemCopy(ComplexInt* src, ComplexInt* dest, int cnt)
{
	int i=0;
	for(i=0;i < cnt; i++){
		dest[i].real=src[i].real;
		dest[i].imag=src[i].imag;
	}
}
