#include <stdio.h>
#include <stdlib.h>
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
int main(){
	printf("%d\n",ln2(bin2dec("100"))+1);
	return 0;
}
