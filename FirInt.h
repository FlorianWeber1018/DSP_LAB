/**
 * Make Shure that the size of the inbuffer and the outbuffer is the same and min (1 + coefSize)
 */
void processStereoFir(
 		short* inBuffer,
 		short* outBuffer,
 		unsigned int bufferSize,
 		short* carryBuffer,
 		short* coef,
 		unsigned int coefSize,
 		unsigned int gainCorrection,
 		long gain);
void stupidMemCopy(
	 short* src,
	 short* dest,
	 int cnt);

