#include<stdio.h>
int main2()
{
	int b;
	int *a = malloc(99);
	a = &b;
}
int main()
{
	system("leaks a.out");
}

