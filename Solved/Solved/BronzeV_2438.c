#include <stdio.h>

int main(void)
{
	unsigned char n;

	//scanf("%hhd", &n);
	scanf_s("%hhd", &n);

	for (unsigned char i = 1; i <= n; i++)
	{
		for (unsigned char j = 0; j < i; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}