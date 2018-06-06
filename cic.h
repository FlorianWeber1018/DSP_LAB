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
  int real;
  int imag;
} ComplexInt;


void integrate(
  ComplexInt* BufferIn,
  ComplexInt* BufferOut,
  short BufferSize,
  ComplexInt* LastOutVal
);
void differentiate(
  ComplexInt* BufferIn,
  ComplexInt* BufferOut,
  short BufferSize,
  ComplexInt* LastInVal
);
void downSample(
  ComplexInt* BufferIn,
  ComplexInt* BufferOut,
  short BufferSizeOut,
  short SampleRateDivider
);
void upSample(
  ComplexInt* BufferIn,
  ComplexInt* BufferOut,
  short BufferSizeOut,
  short SampleRateMultiplikator
);
/*
void StereoFir(
	StereoFloat* inBuffer,
 	StereoFloat* outBuffer,
 	short bufferSize,
 	StereoFloat* carryBuffer,
 	float* coef,
 	short coefSize
);
*/
void ToComplexInt(
	StereoShort* in,
	ComplexInt* out,
	short bufferSize
);
void ToShort(
	ComplexInt* in,
	StereoShort* out,
	short bufferSize
);
void mulLookup(
  ComplexInt* in,
  ComplexInt* out,
  short bufferSize,
  ComplexInt* lookupTable,
  int DCgain,
  short lookupTableSize,
  short* currentindex
);
void initComplexInt(ComplexInt* data);

#endif /* CIC_H_ */
