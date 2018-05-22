#define Nfft 128						//Length of the processed FFT should be k by the Power of 2 and minimum 128; to change anything of the buffers only edit this line;
#define firCoefN (16)						//Length of the impulse response of the Filter (wrost case: NCarry1)
#define N (Nfft - firCoefN*4 + 4)		//length of the signal block from input/to output in Complex Float
#define BUFFER_LEN (2 * N)					//length of the signal block from input/to output in float
#define Ncarry0 (firCoefN*2 - 2)			//length of the carryBuffer0
#define Ncarry1 (firCoefN*4 - 4)			//length of the carryBuffer1
#define Ncarry2 (firCoefN*2 - 2)			//length of the carryBuffer2




#define g0 3.f
#define g1 0.f
#define g2 0.f

#pragma DATA_SECTION(w, ".datenpuffer");
#include "twiddle.h"
ComplexFloat* twiddleFacC = (ComplexFloat*) w;


#pragma DATA_SECTION(BufferInputSpec, ".datenpuffer");
ComplexFloat BufferInputSpec[Nfft];

#pragma DATA_SECTION(outBuffer0, ".datenpuffer");
ComplexFloat outBuffer0[Nfft];
#pragma DATA_SECTION(outBuffer1, ".datenpuffer");
ComplexFloat outBuffer1[Nfft];
#pragma DATA_SECTION(outBuffer2, ".datenpuffer");
ComplexFloat outBuffer2[Nfft];

#pragma DATA_SECTION(outBufferSum, ".datenpuffer");
ComplexFloat outBufferSum[N];


#pragma DATA_SECTION(carryBuffer0, ".datenpuffer");
ComplexFloat carryBuffer0[Ncarry0];
#pragma DATA_SECTION(carryBuffer1, ".datenpuffer");
ComplexFloat carryBuffer1[Ncarry1];
#pragma DATA_SECTION(carryBuffer2, ".datenpuffer");
ComplexFloat carryBuffer2[Ncarry2];

#pragma DATA_SECTION(g00, ".datenpuffer");
#include "filters/g00.h"
#pragma DATA_SECTION(g01, ".datenpuffer");
#include "filters/g01.h"
#pragma DATA_SECTION(g10, ".datenpuffer");
#include "filters/g10.h"
#pragma DATA_SECTION(g11, ".datenpuffer");
#include "filters/g11.h"
#pragma DATA_SECTION(h00, ".datenpuffer");
#include "filters/h00.h"
#pragma DATA_SECTION(h01, ".datenpuffer");
#include "filters/h01.h"
#pragma DATA_SECTION(h10, ".datenpuffer");
#include "filters/h10.h"
#pragma DATA_SECTION(h11, ".datenpuffer");
#include "filters/h11.h"
#pragma DATA_SECTION(g00Spec, ".datenpuffer");
ComplexFloat g00Spec[Nfft];
#pragma DATA_SECTION(g01Spec, ".datenpuffer");
ComplexFloat g01Spec[Nfft];
#pragma DATA_SECTION(g10Spec, ".datenpuffer");
ComplexFloat g10Spec[Nfft];
#pragma DATA_SECTION(g11Spec, ".datenpuffer");
ComplexFloat g11Spec[Nfft];
#pragma DATA_SECTION(h00Spec, ".datenpuffer");
ComplexFloat h00Spec[Nfft];
#pragma DATA_SECTION(h01Spec, ".datenpuffer");
ComplexFloat h01Spec[Nfft];
#pragma DATA_SECTION(h10Spec, ".datenpuffer");
ComplexFloat h10Spec[Nfft];
#pragma DATA_SECTION(h11Spec, ".datenpuffer");
ComplexFloat h11Spec[Nfft];


#pragma DATA_SECTION(resultingSpec0, ".datenpuffer");
ComplexFloat resultingSpec0[Nfft];
#pragma DATA_SECTION(resultingSpec1, ".datenpuffer");
ComplexFloat resultingSpec1[Nfft];
#pragma DATA_SECTION(resultingSpec2, ".datenpuffer");
ComplexFloat resultingSpec2[Nfft];

