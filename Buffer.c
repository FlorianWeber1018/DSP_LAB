#define coefN 16						//Length of the impulse response of the Filter
#define N 1024								////length of the signal block from input/to output in StereoFloat
#define BUFFER_LEN (2*N)					//length of the signal block from input/to output in float
#define delayHP (2*coefN-2)					//delay of the highpass path




#define gain0 1.f
#define gain1 1.f
#define gain2 1.f





#pragma DATA_SECTION(Bca0, ".datenpuffer");
StereoFloat Bca0[N];
#pragma DATA_SECTION(Bca1, ".datenpuffer");
StereoFloat Bca1[N];
#pragma DATA_SECTION(Bcd2, ".datenpuffer");
StereoFloat Bcd2[N];
#pragma DATA_SECTION(Bca2, ".datenpuffer");
StereoFloat Bca2[N];
#pragma DATA_SECTION(Bcd1, ".datenpuffer");
StereoFloat Bcd1[N];
#pragma DATA_SECTION(Bcd21, ".datenpuffer");
StereoFloat Bcd21[N];
#pragma DATA_SECTION(Bcd1d, ".datenpuffer");
StereoFloat Bcd1d[N];
#pragma DATA_SECTION(Bca01, ".datenpuffer");
StereoFloat Bca01[N];
#pragma DATA_SECTION(Bca21, ".datenpuffer");
StereoFloat Bca21[N];
#pragma DATA_SECTION(Bca11, ".datenpuffer");
StereoFloat Bca11[N];

#pragma DATA_SECTION(Cca0, ".datenpuffer");
StereoFloat Cca0[coefN];
#pragma DATA_SECTION(Cca1, ".datenpuffer");
StereoFloat Cca1[coefN];
#pragma DATA_SECTION(Ccd2, ".datenpuffer");
StereoFloat Ccd2[coefN];
#pragma DATA_SECTION(Cca2, ".datenpuffer");
StereoFloat Cca2[coefN];
#pragma DATA_SECTION(Ccd1, ".datenpuffer");
StereoFloat Ccd1[delayHP];
#pragma DATA_SECTION(Ccd21, ".datenpuffer");
StereoFloat Ccd21[coefN];
#pragma DATA_SECTION(Ccd1d, ".datenpuffer");
StereoFloat Ccd1d[coefN];


#pragma DATA_SECTION(g00, ".datenpuffer");
#include "filters/g00.h"
#pragma DATA_SECTION(g01, ".datenpuffer");
#include "filters/g01.h"

#pragma DATA_SECTION(h00, ".datenpuffer");
#include "filters/h00.h"
#pragma DATA_SECTION(h01, ".datenpuffer");
#include "filters/h01.h"






