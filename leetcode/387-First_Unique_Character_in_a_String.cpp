// Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

// Example 1:

// Input: s = "leetcode"

// Output: 0

// Explanation:

// The character 'l' at index 0 is the first character that does not occur at any other index.

// Example 2:

// Input: s = "loveleetcode"

// Output: 2

// Example 3:

// Input: s = "aabb"

// Output: -1

// Constraints:

// 1 <= s.length <= 105
// s consists of only lowercase English letters.

class Solution
{
public:
    int firstUniqChar(string s)
    {
        unordered_map<char, int> freq;
        unordered_map<char, int> index;

        int i = 0;
        for (auto it : s)
        {
            freq[it]++;
            index[it] = i++;
        }

        int minIndex = INT_MAX;
        for (auto it : freq)
        {
            if (it.second == 1)
                minIndex = min(minIndex, index[it.first]);
        }

        if (minIndex != INT_MAX)
            return minIndex;
        else
            return -1;
    }
};
