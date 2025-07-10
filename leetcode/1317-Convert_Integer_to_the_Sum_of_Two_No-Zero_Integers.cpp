// No-Zero integer is a positive integer that does not contain any 0 in its decimal representation.

// Given an integer n, return a list of two integers [a, b] where:

// a and b are No-Zero integers.
// a + b = n
// The test cases are generated so that there is at least one valid solution. If there are many valid solutions, you can return any of them.

// Example 1:

// Input: n = 2
// Output: [1,1]
// Explanation: Let a = 1 and b = 1.
// Both a and b are no-zero integers, and a + b = 2 = n.
// Example 2:

// Input: n = 11
// Output: [2,9]
// Explanation: Let a = 2 and b = 9.
// Both a and b are no-zero integers, and a + b = 11 = n.
// Note that there are other valid answers as [8, 3] that can be accepted.

// Constraints:

// 2 <= n <= 104

class Solution
{
public:
    vector<int> getNoZeroIntegers(int n)
    {
        bool res = false;
        int d;
        int x = 1, y, check1, copyY, check2, copyX;
        while (res == false)
        {
            y = n - x;

            check1 = 1;
            copyY = y;
            while (copyY > 0)
            {
                d = copyY % 10;
                check1 = check1 * d;
                copyY = copyY / 10;
            }
            check2 = 1;
            copyX = x;
            while (copyX > 0)
            {
                d = copyX % 10;
                check2 = check2 * d;
                copyX = copyX / 10;
            }

            if (check1 == 0 || check2 == 0)
                x++;

            else
                res = true;
        }

        return {x, y};
    }
};
