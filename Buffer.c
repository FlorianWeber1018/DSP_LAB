#define Nfft 512						//Length of the processed FFT should be k by the Power of 2; to change anything of the buffers only edit this line;
#define firCoefN (16)						//Length of the impulse response of the Filter
#define N (Nfft - firCoefN + 1)		//length of the signal block from input/to output in Complex Float
#define BUFFER_LEN (2 * N)					//length of the signal block from input/to output in float
#define Ncarry (firCoefN - 1)			//length of the carryBuffer





#pragma DATA_SECTION(w, ".datenpuffer");
#include "twiddle.h"
ComplexFloat* twiddleFacC = (ComplexFloat*) w;



#pragma DATA_SECTION(impuleResponseSpecFilter, ".datenpuffer");
ComplexFloat impuleResponseSpecFilter[Nfft];

#pragma DATA_SECTION(tempBuffer0, ".datenpuffer");
ComplexFloat tempBuffer0[Nfft];

#pragma DATA_SECTION(tempBuffer1, ".datenpuffer");
ComplexFloat tempBuffer1[Nfft];

#pragma DATA_SECTION(carryBuffer, ".datenpuffer");
ComplexFloat carryBuffer[Ncarry];


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
