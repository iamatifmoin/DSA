// Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

// Each letter in magazine can only be used once in ransomNote.

// Example 1:

// Input: ransomNote = "a", magazine = "b"
// Output: false
// Example 2:

// Input: ransomNote = "aa", magazine = "ab"
// Output: false
// Example 3:

// Input: ransomNote = "aa", magazine = "aab"
// Output: true

// Constraints:

// 1 <= ransomNote.length, magazine.length <= 105
// ransomNote and magazine consist of lowercase English letters.

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> ransomFreq;
        unordered_map<char, int> magazineFreq;

        for (auto it : ransomNote)
            ransomFreq[it]++;

        for (auto it : magazine)
            magazineFreq[it]++;

        for (auto it : ransomFreq)
        {
            if (it.second > magazineFreq[it.first])
                return false;
        }

        return true;
    }
};
