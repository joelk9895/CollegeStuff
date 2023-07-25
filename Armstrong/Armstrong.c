#include <stdio.h>

int pwr(int a, int b){
    if(b>1){
        return a*pwr(a,b-1);
    }
    else{
        return a;
    }

}

int main(){
    int arm=0,temp=0,temp2 = 0, power=0,sum=0;
    printf("Enter the number: ");
    scanf("%d", &arm);
    temp = arm;
    while(arm>0){
        arm = arm/10;
        power++;
    }
    temp2 = temp;
    while(temp>0){
        sum += pwr(temp%10,power);
        temp = temp/10;
    }
    if(sum == temp2){
        printf("It's an armstrong number");
    }
    else{
        printf("It is not");
    }
}