#include <iostream>
using namespace std;
void shift(int *X,int k){
    for(int i=0;i<k-1;++i){
            X[i]=X[i+1];
    };
}

int additive_random(const int m,const int k, int* X){
	int Xn=(X[k-1]+X[0])%m;
        shift(X,k);
	X[k-1]=Xn;
	return Xn;
}

int main(){
	int k,m;
        cout<<"Программа генерирует случайные числа в диапазоне [0,m-1]."<<endl;
        cout<<"Введите m."<<endl;
        cin>>m;
        cout<<"Введите k - количество параметров генератора."<<endl;
        cin>>k;
	int *X=new int[k];
        for(int i=0;i<k;++i){
            cout<<"Введите параметр номер "<<i<<"."<<endl;
            cin>>X[i];
        }
        for(;;){
	    cout<<additive_random(m,k,X)<<endl;
            cout<<"Нажмите <Enter> для генерации следующего числа."<<endl;
            cin.get();
	};
	return 0;
}
