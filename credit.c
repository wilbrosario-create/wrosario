#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Ask for the credit card number
    long number = get_long("Number: ");

    // Keep a copy of the original number
    long temp = number;

    // Count the number of digits
    int digits = 0;
    while (temp > 0)
    {
        temp /= 10;
        digits++;
    }

    // Apply Luhn's algorithm
    temp = number;
    int sum = 0;
    bool multiply = false;

    while (temp > 0)
    {
        int digit = temp % 10;

        if (multiply)
        {
            int product = digit * 2;
            sum += product / 10;
            sum += product % 10;
        }
        else
        {
            sum += digit;
        }

        multiply = !multiply;
        temp /= 10;
    }

    // If the checksum is invalid, the card is invalid
    if (sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    // Get the first two digits
    long first_two = number;
    while (first_two >= 100)
    {
        first_two /= 10;
    }

    // Get the first digit
    long first_digit = number;
    while (first_digit >= 10)
    {
        first_digit /= 10;
    }

    // Check the card type
    if (digits == 15 && (first_two == 34 || first_two == 37))
    {
        printf("AMEX\n");
    }
    else if (digits == 16 && first_two >= 51 && first_two <= 55)
    {
        printf("MASTERCARD\n");
    }
    else if ((digits == 13 || digits == 16) && first_digit == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
