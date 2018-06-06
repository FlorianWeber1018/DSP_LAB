/*
 * buf.c
 *
 *  Created on: 30.05.2018
 *      Author: dsplab
 */
#define srd 48
#define BUFFER_LEN 4032       //GANZZAHLIG TEILBAR DURCH SRD!!!!!
#define Nhigh ( BUFFER_LEN / 2 )
#define Nlow ( Nhigh / srd )
#define coefSize  40


#pragma DATA_SECTION(Ghp, ".datenpuffer");
#include "fdacoefs.h"
#pragma DATA_SECTION(H, ".datenpuffer");
#include "H.h"
#pragma DATA_SECTION(R, ".datenpuffer");
#include "R.h"

#pragma DATA_SECTION(ba, ".datenpuffer");
ComplexInt ba[Nhigh];
#pragma DATA_SECTION(bb, ".datenpuffer");
ComplexInt bb[Nhigh];

#pragma DATA_SECTION(ci0, ".datenpuffer");
ComplexInt ci0;
#pragma DATA_SECTION(ci1, ".datenpuffer");
ComplexInt ci1;
#pragma DATA_SECTION(ci2, ".datenpuffer");
ComplexInt ci2;
#pragma DATA_SECTION(ci3, ".datenpuffer");
ComplexInt ci3;
#pragma DATA_SECTION(ci4, ".datenpuffer");
ComplexInt ci4;
#pragma DATA_SECTION(ci5, ".datenpuffer");
ComplexInt ci5;
#pragma DATA_SECTION(cc0, ".datenpuffer");
ComplexInt cc0;
#pragma DATA_SECTION(cc1, ".datenpuffer");
ComplexInt cc1;
#pragma DATA_SECTION(cc2, ".datenpuffer");
ComplexInt cc2;
#pragma DATA_SECTION(cc3, ".datenpuffer");
ComplexInt cc3;
#pragma DATA_SECTION(cc4, ".datenpuffer");
ComplexInt cc4;
#pragma DATA_SECTION(cc5, ".datenpuffer");
ComplexInt cc5;
#pragma DATA_SECTION(cc4, ".datenpuffer");
ComplexInt cc4;
#pragma DATA_SECTION(cc5, ".datenpuffer");
ComplexInt cc5;
#pragma DATA_SECTION(indexH, ".datenpuffer");
short indexH;
#pragma DATA_SECTION(indexR, ".datenpuffer");
short indexR;

#pragma DATA_SECTION(chp, ".datenpuffer");
ComplexInt chp[coefSize];
