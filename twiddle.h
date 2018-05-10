/* -------------------------------------------------------------------- */
/*  Automatically generated twiddle-factor array.                       */
/*      Number of points:    512                                         */
/*      Appropriate FFTs:    DSPF_sp_cfftr2_dit, DSPF_sp_icfftr2_dif    */
/*      Required alignment:  8 byte (word)                              */
/* -------------------------------------------------------------------- */
/*  NOTE:  It is suggested that this array be aligned in a different    */
/*  starting bank than the actual FFT data, to reduce bank conflicts.   */
/*  This can be achieved by using the DATA_MEM_BANK pragma.  Please     */
/*  see the TMS320C6000 Optimizing C Compiler Reference (SPRU187E)      */
/*  for details on "#pragma DATA_MEM_BANK".                             */
/* -------------------------------------------------------------------- */

//#pragma DATA_ALIGN(w, 8);  /* Remove this if using DATA_MEM_BANK */

float twiddleFac[2 * 256] =
{
     1.000000,  0.000000,  0.000000,  1.000000,  0.707107,  0.707107, -0.707107,  0.707107,
     0.923880,  0.382683, -0.382683,  0.923880,  0.382683,  0.923880, -0.923880,  0.382683,
     0.980785,  0.195090, -0.195090,  0.980785,  0.555570,  0.831470, -0.831470,  0.555570,
     0.831470,  0.555570, -0.555570,  0.831470,  0.195090,  0.980785, -0.980785,  0.195090,
     0.995185,  0.098017, -0.098017,  0.995185,  0.634393,  0.773010, -0.773010,  0.634393,
     0.881921,  0.471397, -0.471397,  0.881921,  0.290285,  0.956940, -0.956940,  0.290285,
     0.956940,  0.290285, -0.290285,  0.956940,  0.471397,  0.881921, -0.881921,  0.471397,
     0.773010,  0.634393, -0.634393,  0.773010,  0.098017,  0.995185, -0.995185,  0.098017,
     0.998795,  0.049068, -0.049068,  0.998795,  0.671559,  0.740951, -0.740951,  0.671559,
     0.903989,  0.427555, -0.427555,  0.903989,  0.336890,  0.941544, -0.941544,  0.336890,
     0.970031,  0.242980, -0.242980,  0.970031,  0.514103,  0.857729, -0.857729,  0.514103,
     0.803208,  0.595699, -0.595699,  0.803208,  0.146730,  0.989177, -0.989177,  0.146730,
     0.989177,  0.146730, -0.146730,  0.989177,  0.595699,  0.803208, -0.803208,  0.595699,
     0.857729,  0.514103, -0.514103,  0.857729,  0.242980,  0.970031, -0.970031,  0.242980,
     0.941544,  0.336890, -0.336890,  0.941544,  0.427555,  0.903989, -0.903989,  0.427555,
     0.740951,  0.671559, -0.671559,  0.740951,  0.049068,  0.998795, -0.998795,  0.049068,
     0.999699,  0.024541, -0.024541,  0.999699,  0.689541,  0.724247, -0.724247,  0.689541,
     0.914210,  0.405241, -0.405241,  0.914210,  0.359895,  0.932993, -0.932993,  0.359895,
     0.975702,  0.219101, -0.219101,  0.975702,  0.534998,  0.844854, -0.844854,  0.534998,
     0.817585,  0.575808, -0.575808,  0.817585,  0.170962,  0.985278, -0.985278,  0.170962,
     0.992480,  0.122411, -0.122411,  0.992480,  0.615232,  0.788346, -0.788346,  0.615232,
     0.870087,  0.492898, -0.492898,  0.870087,  0.266713,  0.963776, -0.963776,  0.266713,
     0.949528,  0.313682, -0.313682,  0.949528,  0.449611,  0.893224, -0.893224,  0.449611,
     0.757209,  0.653173, -0.653173,  0.757209,  0.073565,  0.997290, -0.997290,  0.073565,
     0.997290,  0.073565, -0.073565,  0.997290,  0.653173,  0.757209, -0.757209,  0.653173,
     0.893224,  0.449611, -0.449611,  0.893224,  0.313682,  0.949528, -0.949528,  0.313682,
     0.963776,  0.266713, -0.266713,  0.963776,  0.492898,  0.870087, -0.870087,  0.492898,
     0.788346,  0.615232, -0.615232,  0.788346,  0.122411,  0.992480, -0.992480,  0.122411,
     0.985278,  0.170962, -0.170962,  0.985278,  0.575808,  0.817585, -0.817585,  0.575808,
     0.844854,  0.534998, -0.534998,  0.844854,  0.219101,  0.975702, -0.975702,  0.219101,
     0.932993,  0.359895, -0.359895,  0.932993,  0.405241,  0.914210, -0.914210,  0.405241,
     0.724247,  0.689541, -0.689541,  0.724247,  0.024541,  0.999699, -0.999699,  0.024541,
     0.999925,  0.012272, -0.012272,  0.999925,  0.698376,  0.715731, -0.715731,  0.698376,
     0.919114,  0.393992, -0.393992,  0.919114,  0.371317,  0.928506, -0.928506,  0.371317,
     0.978317,  0.207111, -0.207111,  0.978317,  0.545325,  0.838225, -0.838225,  0.545325,
     0.824589,  0.565732, -0.565732,  0.824589,  0.183040,  0.983105, -0.983105,  0.183040,
     0.993907,  0.110222, -0.110222,  0.993907,  0.624860,  0.780737, -0.780737,  0.624860,
     0.876070,  0.482184, -0.482184,  0.876070,  0.278520,  0.960431, -0.960431,  0.278520,
     0.953306,  0.302006, -0.302006,  0.953306,  0.460539,  0.887640, -0.887640,  0.460539,
     0.765167,  0.643832, -0.643832,  0.765167,  0.085797,  0.996313, -0.996313,  0.085797,
     0.998118,  0.061321, -0.061321,  0.998118,  0.662416,  0.749136, -0.749136,  0.662416,
     0.898674,  0.438616, -0.438616,  0.898674,  0.325310,  0.945607, -0.945607,  0.325310,
     0.966976,  0.254866, -0.254866,  0.966976,  0.503538,  0.863973, -0.863973,  0.503538,
     0.795837,  0.605511, -0.605511,  0.795837,  0.134581,  0.990903, -0.990903,  0.134581,
     0.987301,  0.158858, -0.158858,  0.987301,  0.585798,  0.810457, -0.810457,  0.585798,
     0.851355,  0.524590, -0.524590,  0.851355,  0.231058,  0.972940, -0.972940,  0.231058,
     0.937339,  0.348419, -0.348419,  0.937339,  0.416430,  0.909168, -0.909168,  0.416430,
     0.732654,  0.680601, -0.680601,  0.732654,  0.036807,  0.999322, -0.999322,  0.036807,
     0.999322,  0.036807, -0.036807,  0.999322,  0.680601,  0.732654, -0.732654,  0.680601,
     0.909168,  0.416430, -0.416430,  0.909168,  0.348419,  0.937339, -0.937339,  0.348419,
     0.972940,  0.231058, -0.231058,  0.972940,  0.524590,  0.851355, -0.851355,  0.524590,
     0.810457,  0.585798, -0.585798,  0.810457,  0.158858,  0.987301, -0.987301,  0.158858,
     0.990903,  0.134581, -0.134581,  0.990903,  0.605511,  0.795837, -0.795837,  0.605511,
     0.863973,  0.503538, -0.503538,  0.863973,  0.254866,  0.966976, -0.966976,  0.254866,
     0.945607,  0.325310, -0.325310,  0.945607,  0.438616,  0.898674, -0.898674,  0.438616,
     0.749136,  0.662416, -0.662416,  0.749136,  0.061321,  0.998118, -0.998118,  0.061321,
     0.996313,  0.085797, -0.085797,  0.996313,  0.643832,  0.765167, -0.765167,  0.643832,
     0.887640,  0.460539, -0.460539,  0.887640,  0.302006,  0.953306, -0.953306,  0.302006,
     0.960431,  0.278520, -0.278520,  0.960431,  0.482184,  0.876070, -0.876070,  0.482184,
     0.780737,  0.624860, -0.624860,  0.780737,  0.110222,  0.993907, -0.993907,  0.110222,
     0.983105,  0.183040, -0.183040,  0.983105,  0.565732,  0.824589, -0.824589,  0.565732,
     0.838225,  0.545325, -0.545325,  0.838225,  0.207111,  0.978317, -0.978317,  0.207111,
     0.928506,  0.371317, -0.371317,  0.928506,  0.393992,  0.919114, -0.919114,  0.393992,
     0.715731,  0.698376, -0.698376,  0.715731,  0.012272,  0.999925, -0.999925,  0.012272
};
