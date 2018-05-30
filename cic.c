#include "cic.h"
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

}
void ToFloat(
	StereoShort* in,
	StereoFloat* out,
	short bufferSize
){
	int i=0;
	for (i=0;i<bufferSize;i++){
		out[i].left = (float)in[i].left;

	}
}
void ToShort(
	StereoFloat* in,
	StereoShort* out,
	short bufferSize
){
	int i=0;
	for (i=0;i<bufferSize;i++){
		out[i].left = (short)in[i].left;
		out[i].right = 0;
	}
}
