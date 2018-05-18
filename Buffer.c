#define Nfft 1024						//Length of the processed FFT should be k by the Power of 2; to change anything of the buffers only edit this line;
#define firCoefN 32						//Length of the impulse response of the Filter
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

/*
#pragma DATA_SECTION(BufferBand0In, ".datenpuffer");
ComplexFloat BufferBand0In[N];
#pragma DATA_SECTION(BufferBand1In, ".datenpuffer");
ComplexFloat BufferBand1In[N];
#pragma DATA_SECTION(BufferBand2In, ".datenpuffer");
ComplexFloat BufferBand2In[N];

#pragma DATA_SECTION(BufferBand0Out, ".datenpuffer");
ComplexFloat BufferBand0Out[N];
#pragma DATA_SECTION(BufferBand1Out, ".datenpuffer");
ComplexFloat BufferBand1Out[N];
#pragma DATA_SECTION(BufferBand2Out, ".datenpuffer");
ComplexFloat BufferBand2Out[N];

*/
#pragma DATA_SECTION(FIRCoef, ".datenpuffer");
float FIRCoef[32] = {
    0.03001603397175882000,
    0.03017513797085835700,
    0.03033148742601846100,
    0.03048560524906013300,
    0.03063817253487747000,
    0.03079008862094845300,
    0.03094256291669092100,
    0.03109726098864474700,
    0.03125654840416408600,
    0.03142392274140393800,
    0.03160483935260422600,
    0.03180845653001406600,
    0.03205187770636352300,
    0.03237288792495747500,
    0.03288517975719685400,
    0.03438610572034986300,
    0.03288517975719685400,
    0.03237288792495747500,
    0.03205187770636352300,
    0.03180845653001406600,
    0.03160483935260422600,
    0.03142392274140393800,
    0.03125654840416408600,
    0.03109726098864474700,
    0.03094256291669092100,
    0.03079008862094845300,
    0.03063817253487747000,
    0.03048560524906013300,
    0.03033148742601846100,
    0.03017513797085835700,
    0.03001603397175882000,
    0.02985377008852711800
};
