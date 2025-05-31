#include<stdio.h>
#include "percent_encod_decod.h"


unsigned char plain_text[10]={'Z','~','%','d','?','.',221,255,'_','-'};
unsigned char enc_text[30]={0};
unsigned char dec_text[30]={0};

void main(void){
	unsigned int enc_size=percent_encode(plain_text,10, enc_text);
    printf("enc_size %d\n",enc_size);
	for(int i=0;i<enc_size;i++){
		printf("enc_text[%d] : %c | %d | %#x\n",i, enc_text[i],enc_text[i],enc_text[i]);
	}
	unsigned int dec_size=percent_decode(enc_text,enc_size,dec_text);
    printf("_size %d\n",dec_size);	
    for(int j=0;j<dec_size;j++){
		printf("dec_text[%d] : %c | %d | %#x\n",j, dec_text[j],dec_text[j],dec_text[j]);
	}


}
