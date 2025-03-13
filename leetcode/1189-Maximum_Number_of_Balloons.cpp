// Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

// You can use each character in text at most once. Return the maximum number of instances that can be formed.

// Example 1:

// Input: text = "nlaebolko"
// Output: 1
// Example 2:

// Input: text = "loonbalxballpoon"
// Output: 2
// Example 3:

// Input: text = "leetcode"
// Output: 0

// Constraints:

// 1 <= text.length <= 104
// text consists of lower case English letters only.

class Solution
{
public:
    int maxNumberOfBalloons(string text)
    {
        unordered_map<char, int> freq;
        for (auto it : text)
            freq[it]++;

        int counter = 0;
        while (freq['b'] > 0 && freq['a'] > 0 && freq['l'] > 1 && freq['o'] > 1 && freq['n'] > 0)
        {
            counter++;
            freq['b']--;
            freq['a']--;
            freq['l'] = freq['l'] - 2;
            freq['o'] = freq['o'] - 2;
            freq['n']--;
        }
        return counter;
    }
};