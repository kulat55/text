#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int count_bits(size_t x)
{
	int bits = 0;
	while (x)
	{
		if (x & 1U)bits++;
		x >>= 1;
	}
	return bits;
}
int int_bits(void)
{
	return count_bits(~0U);
}
void print_bits(size_t x)
{
	int i;
	for (i = int_bits(); i > 0; i--)
	{
		putchar(((x >> i) & 1U) ? '1' : '0');
	}
	printf("\n");
}
int main()
{
	unsigned int a, b;
	printf("a :  "); scanf("%u", &a);
	printf("\nb :  "); scanf("%u", &b);
	printf("a = "); print_bits(a);
	printf("b = "); print_bits(b);
	printf("a & b = "); print_bits(a & b);
	printf("a | b = "); print_bits(a | b);
	printf("a ^ b "); print_bits(a ^ b);
	printf("~a = "); print_bits(~a);
	printf("~b = "); print_bits(~b);
	printf("a>>b = "); print_bits(a>>b);
	system("pause");
	return 0;
}