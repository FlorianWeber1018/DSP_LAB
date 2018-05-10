void stupidMemCopy(short* src, short* dest, int cnt)
{
	int i=0;
	for(i=0;i < cnt; i++){
		dest[i]=src[i];
	}
}

void processStereoFir(
		short* inBuffer,
		short* outBuffer,
		unsigned int bufferSize,
		short* carryBuffer,
		short* coef,
		unsigned int coefSize,
		int gainCorrection,
		long gain)
{
	int i=0;
	int j=0;
	long temp = 0;


//Left Channel

	for(i=0; i<bufferSize; i+=2){
		temp=0;
		for(j=0;j<coefSize;j++){
			if((i-(2*j)) >= 0){
				temp += inBuffer[i-(j*2)]*coef[j];
			}else{
				temp += carryBuffer[coefSize*2 + (i-(j*2))]*coef[j];
			}
		}
		outBuffer[i] = (short)(temp*gain/gainCorrection);
	}

	//Right Channel

	 for(i=1; i<bufferSize; i+=2){
 		temp=0;
 		for(j=0;j<coefSize;j++){
 			if((i-(2*j)) >= 0){
 				temp += inBuffer[i-(j*2)]*coef[j];
 			}else{
 				temp += carryBuffer[coefSize*2 + (i-(j*2))]*coef[j];
 			}
 		}
 		outBuffer[i] = (short)(temp*gain/gainCorrection);
 	}

	// * Save the last (coefSize*2) values of inBuffer for next processing

	for( i=0;i<coefSize*2;i++){
		carryBuffer[i]=inBuffer[i+(bufferSize-(coefSize*2))];
	}
}
