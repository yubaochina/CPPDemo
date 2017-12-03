#include<stdio.h>
#include<stdlib.h>

int num = 10; //static area
static int static_num = 30; //limited access privilage to only this file

void test()
{
	int data = 3;
	printf("%p, %p\n", &num, &data);

	num = 101;

	data = 34;
	printf("\n");
}
void main()
{
	//Test local and globle variables
	test();
	printf("\n");
	test();
	printf("\n");

	//static
	for (int i = 0; i < 10; i++)
	{
		int a = 10;
		static int b = 11; //static local variable, initialized when compile, initialize once
		a += 1;
		b += 1;
		printf("%d, %d\n", a, b);
	}

	for (int i = 0; i <= 100; i++)
	{
		static int res = 0;
		res += i;
		if(i==100)
		{
			printf("%d\n", res);
		}
	}


	//parameter sequence
	int p = 5;
	printf("%d, %d", p, ++p);//参数压栈的顺序是从右向左

	getchar();
}
