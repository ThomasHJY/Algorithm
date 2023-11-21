//¹Ì¿Ï¼º
#include <stdio.h>
#include <string.h>

#define MAX_DIGITS 1003

void setResultZero(char result[]);
int isNegative(char num[], int *digits);
void addLargeIntegers(char result[], char num1[], char num2[], int num1_digits, int num2_digits, int negative1);
void subAdd(char result[], char num1[], char num2[], int num1_digits, int num2_digits);
void subtractLargeIntegers(char result[], char num1[], char num2[], int num1_digits, int num2_digits, int negative1);
int isLargeEqual(char num1[], char num2[], int digits);
void subSubtract(char result[], char num1[], char num2[], int digits);
void subSubtract2(char result[], char num1[], char num2[], int num1_digits, int num2_digits);
void multiplyLargeIntegers(char result[], char num1[], char num2[], int num1_digits, int num2_digits, int negative1, int negative2);
void subMultiply(char result[], char num1[], char num2[], int num1_digits, int num2_digits);

int main(void) {
    char num1[MAX_DIGITS] = {0, }, num2[MAX_DIGITS] = { 0, }, result[MAX_DIGITS] = { 0, };
    int num1_digits, num2_digits, negative1 = 0, negative2 = 0;
    // ¾ç¼ö,¾ç¼ö: µ¡¼À(±×´ë·Î) »¬¼À(±×´ë·Î)
    // ¾ç¼ö,À½¼ö: »¬¼À(±×´ë·Î) µ¡¼À(±×´ë·Î)
    // À½¼ö,¾ç¼ö: »¬¼À(¹İÀü), µ¡¼À(¹İÀü)
    // À½¼ö,À½¼ö: µ¡¼À(¹İÀü) »¬¼À(¹İÀü)

    //µ¡¼À »¬¼À ½Ã result ÀÚ¸®¼ö°¡ 1ÀÚ¸® ´õ ´Ã¾î³¯ °æ¿ì Ã³¸®, ¾ç¼ö, À½¼ö »¬¼À Ã³¸® ºÒ°¡´É
    //°ö¼À result ¿À·ù?

    fgets(num1, sizeof(num1), stdin); // Ã¹Â° ÁÙ ÀÔ·Â
    num1[strlen(num1) - 1] = '\0'; // °³Çà ¹®ÀÚ Á¦°Å
    num1_digits = strlen(num1); //ÀÚ¸´¼ö ÀúÀå
    negative1 = isNegative(num1, &num1_digits); //ºÎÈ£È®ÀÎ

    fgets(num2, sizeof(num2), stdin); // Ã¹Â° ÁÙ ÀÔ·Â
    num2[strlen(num2) - 1] = '\0'; // °³Çà ¹®ÀÚ Á¦°Å
    num2_digits = strlen(num2); //ÀÚ¸´¼ö ÀúÀå
    negative2 = isNegative(num2, &num2_digits); //ºÎÈ£È®ÀÎ

    if (negative1 == negative2)
    {
        addLargeIntegers(result, num1, num2, num1_digits, num2_digits, negative1);
        subtractLargeIntegers(result, num1, num2, num1_digits, num2_digits, negative1);
    }
    else
    {
        subtractLargeIntegers(result, num1, num2, num1_digits, num2_digits, negative1);
        addLargeIntegers(result, num1, num2, num1_digits, num2_digits, negative1);
    }
    //multiplyLargeIntegers(result, num1, num2, num1_digits, num2_digits, negative1, negative2);

    return 0;
}

void setResultZero(char result[])
{
    for (int i = 0; i < MAX_DIGITS; i++) result[i] = '\0';
}
int isNegative(char num[], int *digits)
{
    int temp_digits = *digits;
    if (num[0] == '-')
    {
        for (int i = 0; i < temp_digits - 1; i++)
        {
            num[i] = num[i + 1];
        }
        num[temp_digits - 1] = '\0';
        *digits = strlen(num);
        return 1;
    }
    return 0;
}
void addLargeIntegers(char result[], char num1[], char num2[], int num1_digits, int num2_digits, int negative1)
{
    if (num1_digits == num2_digits)
    {
        int carry = 0, digit_sum;
        for (int i = num1_digits - 1; i >= 0; i--)
        {
            digit_sum = (num1[i] - '0') + (num2[i] - '0') + carry;
            result[i] = (char)((digit_sum % 10) + '0');
            carry = digit_sum / 10;
        }
    }
    else if (num1_digits > num2_digits)
    {
        subAdd(result, num1, num2, num1_digits, num2_digits);
    }
    else
    {
        subAdd(result, num2, num1, num2_digits, num1_digits);
    }
    if (negative1) printf("-%s\n", result);
    else printf("%s\n", result);
    setResultZero(result);
}
void subAdd(char result[], char num1[], char num2[], int num1_digits, int num2_digits)
{
    int carry = 0, digit_sum, j = num2_digits - 1;
    for (int i = num1_digits - 1; i >= 0; i--)
    {
        if (j >= 0)
        {
            digit_sum = (num1[i] - '0') + (num2[j] - '0') + carry;
            j--;
        }
        else
        {
            digit_sum = (num1[i] - '0') + carry;
        }
        result[i] = (char)((digit_sum % 10) + '0');
        carry = digit_sum / 10;
    }
}
void subtractLargeIntegers(char result[], char num1[], char num2[], int num1_digits, int num2_digits, int negative1)
{
    int negative_result = 0;
    if (num1_digits == num2_digits)
    {
        if (isLargeEqual(num1, num2, num1_digits))
        {
            subSubtract(result, num1, num2, num1_digits);
        }
        else
        {
            negative_result = 1;
            subSubtract(result, num2, num1, num1_digits);
        }
    }
    else if (num1_digits > num2_digits)
    {
        subSubtract2(result, num1, num2, num1_digits, num2_digits);
    }
    else
    {
        negative_result = 1;
        subSubtract2(result, num2, num1, num2_digits, num1_digits);
    }
    int result_digits = strlen(result), checkZero = 0;
    for (int i = 0; i < result_digits; i++)
    {
        if (result[i] == '0') checkZero++;
    }
    if (result_digits == checkZero)
    {
        printf("0\n");
    }
    else
    {
        for (int i = 0; i < result_digits - checkZero; i++)
        {
            result[i] = result[i + checkZero];
        }
        result[result_digits - checkZero] = '\0';
        if (negative1 != negative_result) printf("-%s\n", result);
        else printf("%s\n", result);
    }
    setResultZero(result);
}
int isLargeEqual(char num1[], char num2[], int digits)
{
    for (int i = 0; i < digits; i++)
    {
        if (num1[i] != num2[i])
        {
            if (num1[i] > num2[i]) return 1;
            else return 0;
        }
    }
    return 1;
}
void subSubtract(char result[], char num1[], char num2[], int digits)
{
    int digit_diff;
    for (int i = 0; i < digits; i++)
    {
        digit_diff = (num1[i] - '0') - (num2[i] - '0');
        if (digit_diff < 0)
        {
            digit_diff += 10;
            result[i - 1] -= 1;
        }
        result[i] = digit_diff + '0';
    }
}
void subSubtract2(char result[], char num1[], char num2[], int num1_digits, int num2_digits)
{
    int digit_diff, j = num1_digits - num2_digits;
    for (int i = 0; i < num1_digits; i++)
    {
        if (i < j)
        {
            result[i] = num1[i];
            continue;
        }
        digit_diff = (num1[i] - '0') - (num2[i] - '0');
        if (digit_diff < 0)
        {
            digit_diff += 10;
            result[i - 1] -= 1;
        }
        result[i] = digit_diff + '0';
    }
}
void multiplyLargeIntegers(char result[], char num1[], char num2[], int num1_digits, int num2_digits, int negative1, int negative2)
{
    if (num1_digits == num2_digits)
    {
        int carry = 0, digit_result;
        for (int i = num1_digits - 1; i >= 0; i--)
        {
            digit_result = (num1[i] - '0') * (num2[i] - '0') + carry;
            result[i + 1] = (char)((digit_result % 10) + '0');
            carry = digit_result / 10;
        }
        if (carry != 0)
        {
            result[0] = carry;
        }
        else
        {
            int result_digit = strlen(result);
            for (int i = 0; i < result_digit - 1; i++)
            {
                result[i] = result[i + 1];
            }
            result[result_digit - 2] = '\0';
        }
    }
    else if (num1_digits > num2_digits)
    {
        subMultiply(result, num1, num2, num1_digits, num2_digits);
    }
    else
    {
        subMultiply(result, num2, num1, num2_digits, num1_digits);
    }
    if (negative1 != negative2) printf("-%s\n", result);
    else printf("%s\n", result);
    result[0] = '\0';
}
void subMultiply(char result[], char num1[], char num2[], int num1_digits, int num2_digits)
{
    int carry = 0, digit_sum, j = num2_digits - 1;
    for (int i = num1_digits - 1; i >= 0; i--)
    {
        if (j >= 0)
        {
            digit_sum = (num1[i] - '0') * (num2[j] - '0') + carry;
            j--;
        }
        else
        {
            digit_sum = (num1[i] - '0') + carry;
        }
        result[i] = (char)((digit_sum % 10) + '0');
        carry = digit_sum / 10;
    }
}