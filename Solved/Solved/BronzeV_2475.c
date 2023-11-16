#include <stdio.h>
#include <math.h>

int main(void)
{
	double unique_num[6] = { 0, };

	for (int i = 0; i < 5; i++)
	{
		//scanf("%lf", &unique_num[i]);
		scanf_s("%lf", &unique_num[i]);
		unique_num[5] += pow(unique_num[i], (double)2);
	}
	unique_num[5] = fmod(unique_num[5], (double)10);
	
	printf("%d", (int)(unique_num[5]));

	return 0;
}