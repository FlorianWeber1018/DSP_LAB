/*
 * buf.c
 *
 *  Created on: 30.05.2018
 *      Author: dsplab
 */
#define srd 48
#define BUFFER_LEN 4096
#define Nhigh ( BUFFER_LEN / 2 )
#define Nlow ( Nhigh / srd )
#define CoefSize  40


#pragma DATA_SECTION(Hlp, ".datenpuffer");
#include "fdacoefs.h"

#pragma DATA_SECTION(i0, ".datenpuffer");
StereoFloat i0[Nhigh];
#pragma DATA_SECTION(i1, ".datenpuffer");
StereoFloat i1[Nhigh];
#pragma DATA_SECTION(i2, ".datenpuffer");
StereoFloat i2[Nhigh];
#pragma DATA_SECTION(i3, ".datenpuffer");
StereoFloat i3[Nhigh];
#pragma DATA_SECTION(i4, ".datenpuffer");
StereoFloat i4[Nhigh];
#pragma DATA_SECTION(i5, ".datenpuffer");
StereoFloat i5[Nhigh];
#pragma DATA_SECTION(c0, ".datenpuffer");
StereoFloat c0[Nlow];
#pragma DATA_SECTION(c1, ".datenpuffer");
StereoFloat c1[Nlow];
#pragma DATA_SECTION(c2, ".datenpuffer");
StereoFloat c2[Nlow];
#pragma DATA_SECTION(c3, ".datenpuffer");
StereoFloat c3[Nlow];
#pragma DATA_SECTION(c4, ".datenpuffer");
StereoFloat c4[Nlow];
#pragma DATA_SECTION(c5, ".datenpuffer");
StereoFloat c5[Nlow];
#pragma DATA_SECTION(dn, ".datenpuffer");
StereoFloat dn[Nhigh];
#pragma DATA_SECTION(up, ".datenpuffer");
StereoFloat up[Nlow];
#pragma DATA_SECTION(hp, ".datenpuffer");
StereoFloat hp[Nlow];


#pragma DATA_SECTION(ci0, ".datenpuffer");
StereoFloat ci0;
#pragma DATA_SECTION(ci1, ".datenpuffer");
StereoFloat ci1;
#pragma DATA_SECTION(ci2, ".datenpuffer");
StereoFloat ci2;
#pragma DATA_SECTION(ci3, ".datenpuffer");
StereoFloat ci3;
#pragma DATA_SECTION(ci4, ".datenpuffer");
StereoFloat ci4;
#pragma DATA_SECTION(ci5, ".datenpuffer");
StereoFloat ci5;
#pragma DATA_SECTION(cc0, ".datenpuffer");
StereoFloat cc0;
#pragma DATA_SECTION(cc1, ".datenpuffer");
StereoFloat cc1;
#pragma DATA_SECTION(cc2, ".datenpuffer");
StereoFloat cc2;
#pragma DATA_SECTION(cc3, ".datenpuffer");
StereoFloat cc3;
#pragma DATA_SECTION(cc4, ".datenpuffer");
StereoFloat cc4;
#pragma DATA_SECTION(cc5, ".datenpuffer");
StereoFloat cc5;
#pragma DATA_SECTION(chp, ".datenpuffer");
StereoFloat chp[CoefSize];
#pragma DATA_SECTION(out, ".datenpuffer");
StereoFloat out[Nhigh];
