#include <stdio.h>

void swap(int n1,int n2){

    printf("n1 = %d\n",n1);
    printf("n2 = %d\n",n2);

    int temp=n1;
    n1=n2;
    n2=temp;

    printf("n1 = %d\n",n1);
    printf("n2 = %d\n",n2);
}

void swap(int *ptr1,int *ptr2){

    printf("*ptr1 = %d\n",*ptr1);
    printf("*ptr2 = %d\n",*ptr2);

    int temp=*ptr1;
    *ptr1=*ptr2;
    *ptr2=temp;

    printf("ptr1 = %d\n",*ptr1);
    printf("ptr2 = %d\n",*ptr2);
}

int main(){

    int a = 1;
    int b = 2;

    printf("Swap\n");
    printf("a = %d\n",a);
    printf("b = %d\n",b);

    swap(a,b);
    swap(&a,&b);

    printf("a = %d\n",a);
    printf("b = %d\n",b);

    return 0;
}