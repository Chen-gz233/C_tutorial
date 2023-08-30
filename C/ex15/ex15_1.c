#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

typedef int (*comp_cb) (int a , int b);

int computer (int a ,int b , comp_cb cmp)
{
    
    return cmp(a,b);

}
int add(int a ,int b)
{
    

    return a+b;
}

int sub(int a ,int b)
{
    return a-b;
}

int mul(int a ,int b)
{
    return a*b;
}

int main(int a ,int b)
{
    a = 8;
    b = 3;
    int x,y,z;
    x= computer (a ,b , add);
    printf("first, %d add %d = %d. \n",a,b,x);
    
    y= computer (a ,b , sub);
    printf("second,%d sub %d = %d. \n",a,b,y);

    z= computer (a ,b , mul);
    printf("third, %d mul %d = %d. \n",a,b,z);

    return 0;

}