#include <stdio.h>
#include <string.h>

int main(void)
{
    long long creditCardNumber;
    printf("Please input CC number: ");
    scanf("%lld", &creditCardNumber);
    long long workingCC = creditCardNumber;
    long long sum = 0;
    long long count = 0;
    long long divisor = 10;
    char result[11];

    // 1st case
    while (workingCC > 0)
    {
        long long lastDigit = workingCC % 10;
        sum = sum + lastDigit;
        workingCC = workingCC / 100;
    }

    // 2nd case
    workingCC = creditCardNumber / 10;
    while (workingCC > 0)
    {
        long long lastDigit = workingCC % 10;
        long long timesTwo = lastDigit * 2;
        if (timesTwo/10 == 0)
        {
            sum = sum + timesTwo;   
        }
        else if (timesTwo/10 != 0)
        {
            long long firstdigit = timesTwo / 10;
            long long last = timesTwo % 10;
            sum = sum + firstdigit + last ; 
        }
        
        workingCC = workingCC / 100;
    }

    // length of the number / digit count

    workingCC = creditCardNumber;
    while (workingCC != 0)
    {
       workingCC =workingCC / 10;
       count++;
    }

    // divisor
    for (long long i = 0; i < count - 2; i++)
    {
        divisor = divisor * 10;
    }

    long long firstDigit = creditCardNumber / divisor;
    long long firstTwoDigits = creditCardNumber / (divisor / 10);

    // final checks
    if (sum % 10 == 0)
    {
        if (firstDigit == 4 && (count == 13 || count == 16))
        {
            strcpy(result, "VISA");
        }
        else if ((firstTwoDigits == 34 || firstTwoDigits == 37) && count == 15)
        {
            strcpy(result, "AMEX");
        }
        else if ((50 < firstTwoDigits && firstTwoDigits < 56) && count == 16)
        {
            strcpy(result, "MASTERCARD");
        }
        else 
        {
            strcpy(result, "INVALID");
        }
    }
    else
    {
        strcpy(result, "INVALID");
    }

    printf("%s\n", result);
}