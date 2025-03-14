// Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

// Example 1:

// Input: s = "Let's take LeetCode contest"
// Output: "s'teL ekat edoCteeL tsetnoc"
// Example 2:

// Input: s = "Mr Ding"
// Output: "rM gniD"

// Constraints:

// 1 <= s.length <= 5 * 104
// s contains printable ASCII characters.
// s does not contain any leading or trailing spaces.
// There is at least one word in s.
// All the words in s are separated by a single space.

class Solution
{
public:
    string reverseWords(string s)
    {
        string res = "", temp = "", word = "";
        s = s + " ";
        for (auto it : s)
        {
            if (it == ' ')
            {
                for (int i = 0; i < word.size(); i++)
                {
                    temp = word[i] + temp;
                }
                res = res + temp + " ";
                word = "";
                temp = "";
            }
            else
                word += it;
        }

        res = res.substr(0, res.size() - 1);

        return res;
    }
};
