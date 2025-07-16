// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

// Example 1:

// Input: strs = ["flower","flow","flight"]
// Output: "fl"
// Example 2:

// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.

// Constraints:

// 1 <= strs.length <= 200
// 0 <= strs[i].length <= 200
// strs[i] consists of only lowercase English letters if it is non-empty.

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
            return "";
        string pref = strs[0];

        for (int i = 1; i < strs.size(); i++)
        {
            while (strs[i].find(pref) != 0)
            {
                pref = pref.substr(0, pref.size() - 1);

                if (pref.empty())
                    return "";
            }
        }

        return pref;
    }
};
