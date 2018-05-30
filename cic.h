/*
 * cic.h
 *
 *  Created on: 30.05.2018
 *      Author: dsplab
 */

#ifndef CIC_H_
#define CIC_H_

typedef struct{
  short left;
  short right;
} StereoShort;
typedef struct{
  float left;
  float right;
} StereoFloat;


void integrate(
  StereoFloat* BufferIn,
  StereoFloat* BufferOut,
  short BufferSize,
  StereoFloat* LastOutVal
);
void differentiate(
  StereoFloat* BufferIn,
  StereoFloat* BufferOut,
  short BufferSize,
  StereoFloat* LastInVal
);
void downSample(
  StereoFloat* BufferIn,
  StereoFloat* BufferOut,
  short BufferSizeOut,
  short SampleRateDivider
);
void upSample(
  StereoFloat* BufferIn,
  StereoFloat* BufferOut,
  short BufferSizeOut,
  short SampleRateMultiplikator
);
void StereoFir(
	StereoFloat* inBuffer,
 	StereoFloat* outBuffer,
 	short bufferSize,
 	StereoFloat* carryBuffer,
 	float* coef,
 	short coefSize
);
void ToFloat(
	StereoShort* in,
	StereoFloat* out,
	short bufferSize
);
void ToShort(
	StereoFloat* in,
	StereoShort* out,
	short bufferSize
);

#endif /* CIC_H_ */
