#define N BUFFER_LEN/2
/*
#pragma DATA_SECTION(carryBuffer, ".datenpuffer");
short carryBuffer[carryBufferLen];
#pragma DATA_SECTION(carryBuffer1, ".datenpuffer");
short carryBuffer1[carryBufferLen];
#pragma DATA_SECTION(buffer1inPing, ".datenpuffer");
short buffer1inPing[BUFFER_LEN];
*/
ComplexFloat* BufferInPingC = (ComplexFloat*) Buffer_in_ping;
ComplexFloat* BufferInPongC = (ComplexFloat*) Buffer_in_pong;
ComplexFloat* BufferOutPingC = (ComplexFloat*) Buffer_out_ping;
ComplexFloat* BufferOutPongC = (ComplexFloat*) Buffer_out_pong;

#pragma DATA_SECTION(twiddleFac, ".datenpuffer");
#include "twiddle.h"
ComplexFloat* twiddleFacC = (ComplexFloat*) twiddleFac;
#pragma DATA_SECTION(impuleResponseSpecFilter, ".datenpuffer");
ComplexFloat impuleResponseSpecFilter[N];
#pragma DATA_SECTION(impuleResponseFilter, ".datenpuffer");
float impuleResponseFilter[N];


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
