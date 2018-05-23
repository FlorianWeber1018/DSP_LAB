#include "FirInt.h"
void stupidMemCopy(short* src, short* dest, int cnt)
{
	int i=0;
	for(i=0;i < cnt; i++){
		dest[i]=src[i];
	}
}
void processStereoFir(
	StereoFloat* inBuffer,
 	StereoFloat* outBuffer,
 	short bufferSize,
 	StereoFloat* carryBuffer,
 	float* coef,
 	short coefSize,
	short SRD,
	bool saveCarry
){
	short i=0;
	short j=0;
	for(i=0; i < bufferSize; i += SRD){
		outBuffer[i].left = 0;
		outBuffer[i].right = 0;
		for(j=0;j<coefSize;j++){
			if(i-j*SRD >= 0){
				outBuffer[i].left += inBuffer[i-j*SRD].left * coef[j];
				outBuffer[i].right += inBuffer[i-j*SRD].right * coef[j];
			}else{
				outBuffer[i].left += carryBuffer[coefSize + i/SRD - j].left * coef[j];
				outBuffer[i].right += carryBuffer[coefSize + i/SRD - j].right * coef[j];
			}
		}
	}
	// * Save the last (coefSize) values of inBuffer for next processing
	if(saveCarry){
		for( i=0; i<coefSize; i++){
			carryBuffer[i].left = inBuffer[i*SRD + (bufferSize-(coefSize*SRD))].left;
			carryBuffer[i].right = inBuffer[i*SRD + (bufferSize-(coefSize*SRD))].right;
		}
	}
}
/*
void upsample2(
	StereoFloat* ioBuffer,
	short bufferSize
){
	int i=0;
	for (i=1;i<bufferSize-2;i+=2){
		ioBuffer[i].left= (ioBuffer[i-1].left + ioBuffer[i+1].left)/2;	//interpol all values between
	}
	ioBuffer[bufferSize-1].left = 2*ioBuffer[bufferSize-2].left-ioBuffer[bufferSize-3].left;//interpol last val
}
*/
void convertToFloat(
	StereoShort* in,
	StereoFloat* out,
	short bufferSize
){
	int i=0;
	for (i=0;i<bufferSize;i++){
		out[i].left = (float)in[i].left;
		out[i].right = (float)in[i].right;
	}
}
void convertToShort(
	StereoFloat* in,
	StereoShort* out,
	short bufferSize
){
	int i=0;
	for (i=0;i<bufferSize;i++){
		out[i].left = (short)in[i].left;
		out[i].right = (short)in[i].right;
	}
}

void att(
	StereoFloat* ioBuffer,
	short bufferSize,
	float att
){
	int i=0;
	for(i=0;i<bufferSize;i++){
		ioBuffer[i].left *= att;
		ioBuffer[i].right *= att;
	}
}
void delay(
	StereoFloat* inBuffer,
 	StereoFloat* outBuffer,
 	short bufferSize,
 	StereoFloat* carryBuffer,
	short delay
){
	int i=0;
	for (i=0;i<bufferSize;i++){
		if(i-delay >= 0){
			outBuffer[i].left = inBuffer[i-delay].left;
			outBuffer[i].right = inBuffer[i-delay].right;
		}else{
			outBuffer[i].left = carryBuffer[i].left;
			outBuffer[i].right = carryBuffer[i].right;
		}
	}
	for( i=0; i<delay; i++){
		carryBuffer[i].left = inBuffer[i + bufferSize - delay].left;
		carryBuffer[i].right = inBuffer[i + bufferSize - delay].right;
	}
}
void sum(
	StereoFloat* ioBuffer,
	StereoFloat* inBuffer,
	short bufferSize
){
	int i=0;
	for (i=0;i<bufferSize;i++){
		ioBuffer[i].left += inBuffer[i].left;
		ioBuffer[i].right += inBuffer[i].right;
	}
}
