#include <stdlib.h>
#include <stdio.h>
int bin2dec(const char *src){
	int res=0;
	for(src;*src;++src){
		res<<=1;
		res+=*src=='1'?1:0;
	}
	return res;
}
int ln2(int a){
	int res=0;
	while(a>>=1)
		res++;
	return res+1;
}
char* dec2bin(int dec){
    int len=ln2(dec)+1;
    char *bin=malloc(len*sizeof(char));
    if(bin!=NULL){
        bin[len-1]='\0';
        int i=len-2;
        while(dec>0){
            bin[i]=dec&1?'1':'0';
            dec>>=1;
            i--;
        }
    }
    return bin;
}
void clbin(char *s){
    int i=0;
    for(i=0;s[i]=='1'||s[i]=='0';++i);
    s[i]='\0';
}

int main(){
    char *a_bin=NULL,*b_bin=NULL;
    size_t a_len,b_len;
	printf("Введите а\n");
    getline(&a_bin,&a_len,stdin);
    clbin(a_bin);
	printf("Введите b\n");
    getline(&b_bin,&b_len,stdin);
    clbin(b_bin);
    int a=bin2dec(a_bin),
        b=bin2dec(b_bin);
	if(b<=a)
		return 0;
    srand(time(NULL));
	int c=rand()%(b-a+1)+a;
    char* c_bin=dec2bin(c);
    printf("%s\n",c_bin);
    free(a_bin);
    free(b_bin);
    free(c_bin);
    return 0;
}
