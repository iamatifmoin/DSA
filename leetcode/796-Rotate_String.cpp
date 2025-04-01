// Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

// A shift on s consists of moving the leftmost character of s to the rightmost position.

// For example, if s = "abcde", then it will be "bcdea" after one shift.

// Example 1:

// Input: s = "abcde", goal = "cdeab"
// Output: true
// Example 2:

// Input: s = "abcde", goal = "abced"
// Output: false

// Constraints:

// 1 <= s.length, goal.length <= 100
// s and goal consist of lowercase English letters.

class Solution
{
public:
    string rev(string s, int first, int last)
    {
        while (first < last)
            swap(s[first++], s[last--]);
        return s;
    }

    bool rotateString(string s, string goal)
    {

        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (s == goal)
                return true;
            s = rev(s, 0, n - 1);
            s = rev(s, 1, n - 1);
        }

        return false;
    }
};
