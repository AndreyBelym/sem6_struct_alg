#include <dos.h>
#include <iostream.h>
#include <iomanip.h>
const unsigned START_SIZE=-1;
void memtest(){
	unsigned size=START_SIZE;
    int stat=-1;
    long count=0;
    unsigned ptr;
    while(size>0){
		stat=allocmem(size,&ptr);
		if(stat==-1){
			count+=size;
			cout<<"Allocated block size: "<<size*16<<hex
				<<", start: "<<ptr
				<<", end: "<<ptr+size-1<<endl<<dec;
		} else
			size=stat;
	};
   cout<<"Memory allocated from DOS: "<<count*16<<endl;
}
int main(){
   cout<<setiosflags(ios::showbase);
   memtest();
   cin.get();
   return 0;
}
