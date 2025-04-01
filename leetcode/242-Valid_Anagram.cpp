// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// Example 1:

// Input: s = "anagram", t = "nagaram"

// Output: true

// Example 2:

// Input: s = "rat", t = "car"

// Output: false

// Constraints:

// 1 <= s.length, t.length <= 5 * 104
// s and t consist of lowercase English letters.

class Solution
{
public:
    string rev(string s, int first, int last)
    {
        while (first < last)
            swap(s[first++], s[last--]);
        return s;
    }

    bool isAnagram(string s, string t)
    {

        unordered_map<char, int> freq;
        if (t.size() != s.size())
            return false;

        for (auto it : s)
            freq[it]++;

        for (auto it : t)
        {
            if (freq[it] == 0)
                return false;
            else
                freq[it]--;
        }
        return true;
    }
};
