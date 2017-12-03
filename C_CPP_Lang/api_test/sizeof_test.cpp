#include <stdio.h>

int main()
{
  int intValue=5;
  int *pInt=&intValue;
  printf("sizeof int pointer: %d\n",sizeof(pInt));

  int int_arr[6];
  printf("sizeof int arr without initialize: %d\n",sizeof(int_arr));

  int int_array[6]={0};
  printf("sizeof int array with initialization:%d \n",sizeof(int_array));

  char charValue='A';
  char* pChar=&charValue;
  printf("sizeof char pointer: %d \n",sizeof(pChar));

  char char_arr[10]={'\0'};
  printf("sizeof char array: %d \n", sizeof(char_arr));
}
