#include <stdio.h>

int main(){
    int a,b,c,sum;

    printf("Enter first number :");
    scanf("%d",&a);
    printf("Enter Second number :");
    scanf("%d",&b);
    printf("Enter Third number :");
    scanf("%d",&c);

    sum = a+b+c;
    printf("Addition of Three numbers is %d\n",sum);

    return 0;
}