#include <stdio.h>

int main(void)
{
	long long n, m, result;

	//scanf("%lld %lld", &n, &m);
	scanf_s("%lld %lld", &n, &m);

	result = n - m;
	if (result < 0) result *= -1;

	printf("%lld", result);

	return 0;
}