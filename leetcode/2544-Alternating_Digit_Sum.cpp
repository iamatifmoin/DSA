// You are given a positive integer n. Each digit of n has a sign according to the following rules:

// The most significant digit is assigned a positive sign.
// Each other digit has an opposite sign to its adjacent digits.
// Return the sum of all digits with their corresponding sign.

// Example 1:

// Input: n = 521
// Output: 4
// Explanation: (+5) + (-2) + (+1) = 4.
// Example 2:

// Input: n = 111
// Output: 1
// Explanation: (+1) + (-1) + (+1) = 1.
// Example 3:

// Input: n = 886996
// Output: 0
// Explanation: (+8) + (-8) + (+6) + (-9) + (+9) + (-6) = 0.

// Constraints:

// 1 <= n <= 109

class Solution
{
public:
    int alternateDigitSum(int n)
    {
        int copyN = n;
        int digits = 0;
        int sign;
        int sum = 0;
        int d;

        while (copyN > 0)
        {
            digits++;
            copyN = copyN / 10;
        }

        if (digits % 2 == 0)
            sign = 1;
        else
            sign = -1;

        copyN = n;

        while (copyN > 0)
        {
            d = copyN % 10;
            sign = sign * -1;
            sum += (d * sign);
            copyN = copyN / 10;
        }

        return sum;
    }
};
