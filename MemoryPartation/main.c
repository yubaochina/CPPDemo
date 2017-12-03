#include <stdio.h>
#include<stdlib.h>

//This is correct.
//Global variable, only declaration
int a;
int a;
int a=10;

void add(int a, int b);

int main(int argc, char *argv[])
{
    //This can cause stack overflow
    //int static_overflow[1024*6000];

    printf("%p\n",&a);

   //This can cause higher CPU utilization
    while(1)
    {
        double db[1024*200];
        double temp=db[0];
    }
    return 0;
}
void add(int a, int b)
{
    return a+b;
}
