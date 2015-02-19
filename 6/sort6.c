#include <stdio.h>
#include <stdlib.h>
//связный список-стек для функции сортировки
typedef struct stack {
    long high,low; //вехняя и нижняя границы текущего отрезка сортировки
    struct stack *prev; //предыдущий элемент стека
} STACK;

STACK* push(STACK *list,long low, long high){
  STACK *new_elem;
    new_elem=(STACK*)malloc(sizeof(STACK));
    if (new_elem!=NULL){
        new_elem->low=low;
        new_elem->high=high;
        new_elem->prev=list;
    }
    return new_elem;
}
STACK* pop(STACK *list){
  STACK *old_elem;
    if (list!=NULL){
        old_elem=list->prev;
        free(list);
    } else old_elem=NULL;
    return old_elem;
};

void clearstack(STACK *list){
  STACK *rider;
    rider=list;
    while(rider!=NULL){
        rider=pop(rider);
    }
};

int QuickSort(double *array, long size) {

  int log;

  double  swap,x;
  STACK *stck=NULL,*tmp=NULL;
  long i,j, L, R;

    log=((stck=push(stck,0,size-1))!=NULL);
    while (log&&(stck!=NULL)){
        L=stck->low; R=stck->high;
        stck=pop(stck);
        while (log&&L<R){
            i=L;j=R;x=array[(L+R)/2];
            do{
                while (array[i]<x) i++;
                while (x<array[j]) j--;
                if (i<=j){
                    swap=array[i];array[i]=array[j];array[j]=swap;
                    i++;j--;
                }
            }while(i<=j);
            if (R-i<j-L){
                if (L<j){
                    log=((tmp=push(stck,L,j))!=NULL);
                    if (log)
                        stck=tmp;
                    else
                        clearstack(stck);
                }
                L=i;

            } else {
                if (i<R){
                    log=((tmp=push(stck,i,R))!=NULL);
                    if (log)
                        stck=tmp;
                    else
                        clearstack(stck);
                }
                R=j;
            }
        }
    };
    return log;
}   

int main(){
    double a,b,c;
    int n,na,nb,nc,di=0;
    double *X;
    int i=0,d=0;
    printf("Введите размер массива.\n");
    scanf("%d",&n);
    n+=3;
    X=malloc(n*sizeof(double));
    printf("Введите 3 новых элемента.\n");
    scanf("%lf %lf %lf",&a,&b,&c);
    printf("Введите индексы новых элементов: [0..%d]\n",n-1);
    scanf("%d %d %d",&na,&nb,&nc);
    for(i=0;i<n;++i){
        if(i==na){
            X[na]=a;
            ++d;
        } else if(i==nb){
            X[nb]=b;
            ++d;
        } else if(i==nc){
            X[nc]=c;
            ++d;
        } else {
            X[i]=i-d;
        }
    }
    printf("Исходный массив:\n");
    for(i=0;i<n;++i){
	printf("%7.2lf ",X[i]);
    }
    printf("\n");
    QuickSort(X,n);
    printf("Отсортированный массив:\n");
    for(i=0;i<n;++i){
	printf("%7.2lf ",X[i]);
    }
    printf("\n");
    return 0;
}
