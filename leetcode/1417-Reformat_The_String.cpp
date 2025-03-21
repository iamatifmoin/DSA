// You are given an alphanumeric string s. (Alphanumeric string is a string consisting of lowercase English letters and digits).

// You have to find a permutation of the string where no letter is followed by another letter and no digit is followed by another digit. That is, no two adjacent characters have the same type.

// Return the reformatted string or return an empty string if it is impossible to reformat the string.

// Example 1:

// Input: s = "a0b1c2"
// Output: "0a1b2c"
// Explanation: No two adjacent characters have the same type in "0a1b2c". "a0b1c2", "0a1b2c", "0c2a1b" are also valid permutations.
// Example 2:

// Input: s = "leetcode"
// Output: ""
// Explanation: "leetcode" has only characters so we cannot separate them by digits.

class Solution
{
public:
    string reformat(string s)
    {
        int n = s.size();
        if (n == 1)
            return s;

        int alphabetCount = 0;

        string characters = "";
        string numbers = "";
        string res;

        for (char ch : s)
        {
            if (ch >= 97 && ch <= 122)
            {
                alphabetCount++;
                characters += ch;
            }
            else
                numbers += ch;
        }

        int numberCount = numbers.size();
        if (alphabetCount == 0 || numberCount == 0 || abs(alphabetCount - numberCount) > 1)
            return "";

        int q = 0, p = 0;
        if (alphabetCount > numberCount)
        {
            for (int i = 0; i < n; i++)
            {
                if (i % 2 == 0)
                    res += characters[p++];
                else
                    res += numbers[q++];
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (i % 2 == 0)
                    res += numbers[p++];
                else
                    res += characters[q++];
            }
        }

        return res;
    }
};
