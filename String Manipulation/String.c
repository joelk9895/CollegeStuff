#include <stdio.h>

int main(){
    char str1[50], str2[50],str3[50];
    int i = 0, j=0,k=0;
    printf("Enter The First String: ");
    gets(str1);
    printf("Enter the second String: ");
    gets(str2);
    while(str1[i]!='\0'){
        str3[i] += str1[i];
        i++;
    }
    while(str2[j]!='\0'){
        str3[i] += str2[j];
        i++;
        j++;
    }
    str3[i] = '\0';
    printf("The Concatenated String is: %s", str3);
}