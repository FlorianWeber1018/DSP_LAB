/**
 * Make Shure that the size of the inbuffer and the outbuffer is the same and min (1 + coefSize)
 */
#ifndef FirInt__h
#define FirInt__h
#ifndef true
#define true 1
#endif
#ifndef false
#define false 0
#endif
#ifndef bool
#define bool short
#endif

typedef struct{
	float left;
	float right;
} StereoFloat;

typedef struct{
	short left;
	short right;
} StereoShort;
void stupidMemCopy(
	 short* src,
	 short* dest,
	 int cnt
);
void processStereoFir(
	StereoFloat* inBuffer,
 	StereoFloat* outBuffer,
 	short bufferSize,
 	StereoFloat* carryBuffer,
 	float* coef,
 	short coefSize,
	short SRD,
	bool saveCarry
);
/*
void upsample2(
	StereoFloat* ioBuffer,
	short bufferSize
);
*/
void att(
	StereoFloat* ioBuffer,
	short bufferSize,
	float att
);
void convertToFloat(
	StereoShort* in,
	StereoFloat* out,
	short bufferSize
);
void convertToShort(
	StereoFloat* in,
	StereoShort* out,
	short bufferSize
);
void delay(
	StereoFloat* inBuffer,
 	StereoFloat* outBuffer,
 	short bufferSize,
 	StereoFloat* carryBuffer,
	short delay
);
void sum(
	StereoFloat* ioBuffer,
	StereoFloat* inBuffer,
	short bufferSize
);
#endif
