#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void shellsort(int *a,int n){
    const int n_gaps=8;
    int gaps[] = {701, 301, 132, 57, 23, 10, 4, 1};
     
    for(int g=0;g<n_gaps;++g)
    {
        int gap=gaps[g];
        for (int i = gap; i < n; ++i)
        {
            int j;
            int temp = a[i];
            for (j = i; j >= gap&&a[j - gap] < temp; j -= gap)
            {
                a[j] = a[j - gap];
            }
            a[j] = temp;
        }
     
    }
} 
void print_array(int *a,int n){
    for(int i=0;i<n;++i){
        printf("%d,",a[i]);
    };
    printf("\n");
}
int main(){
    int n,min_a;
    printf("Введите размер массива.\n");
    scanf("%d",&n);
    int *a=(int*)malloc(n*sizeof(int));
    printf("Введите минимальное значение элемента массива.\n");
    scanf("%d",&min_a);
    min_a=min_a>0?min_a:-min_a;
    srand(time(NULL));
    for(int i=0;i<n;i++){
        a[i]=-(rand()%min_a);
    }
    printf("Исходный массив:\n");
    print_array(a,n);
    shellsort(a,n);
    printf("Отсортированный массив:\n");
    print_array(a,n);
    return 0;
}
