#include <stdio.h>
using namespace std;

int main ()
{
  int arr[]={6,1,3,5,6,8,8,10};

  int len=sizeof(arr)/sizeof(arr[0]);

  printf("array size: %d", len);

}
