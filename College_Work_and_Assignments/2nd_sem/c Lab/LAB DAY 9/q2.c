#include<stdio.h>
#include<string.h>
int main(){
    char str1[100];
    char str2[100];
    printf("Enter first string: ");
    fgets(str1, 100, stdin);
    printf("Enter second string: ");
    fgets(str2, 100, stdin);
    int c = strcmp(str1, str2);
    if(c>0){
        printf("first string is bigger\n");
    }else if(c<0){
        printf("second string is bigger\n");
    }else{
        printf("both string is equal\n");
    }
    int a = strlen(str1)-1;
    int b = strlen(str2)-1;
    if(a == b){
    printf("length of both string is : %d\n",a);
    }
    else{
    printf("length of first string is : %d\n",a);
    printf("length of second string is : %d\n",b);
    }
    return 0;
}