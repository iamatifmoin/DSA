// Given an integer n, return true if it is a power of two. Otherwise, return false.

// An integer n is a power of two, if there exists an integer x such that n == 2x.

// Example 1:

// Input: n = 1
// Output: true
// Explanation: 20 = 1
// Example 2:

// Input: n = 16
// Output: true
// Explanation: 24 = 16
// Example 3:

// Input: n = 3
// Output: false

// Constraints:

// -231 <= n <= 231 - 1

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {

        int i = 0;
        while (pow(2, i) <= n)
        {
            if (pow(2, i) == n)
                return true;

            i++;
        }

        return false;
    }
};
