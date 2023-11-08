#include <stdio.h>

int main(void)
{
    int a, b;

    //scanf("%d %d", &a, & b);
    
    scanf_s("%d %d", &a, &b);
    printf("%d", a + b);
    return 0;
}