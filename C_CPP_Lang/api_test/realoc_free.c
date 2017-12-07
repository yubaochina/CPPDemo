#include <stdio.h>
#include <stdlib.h>
int main(void)
{
  int *ptr=(int*)malloc(10);
  realloc(ptr,0);
  return 0;
}
