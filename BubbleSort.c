#include <stdio.h>

int main(){
    int a[10] = {2, 7, 3, 4, 5, 6, 7, 8, 9, 10};
    int i = 0, j=0, temp;
    printf("%d\n", a[0]);
    for (i=0; i<10; i++){
        for(j=0;j<10;j++){
            if(a[i]<a[j]){
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    for(i=0; i<10; i++){
        printf("%d ",a[i]);
    }
}