// A pangram is a sentence where every letter of the English alphabet appears at least once.

// Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, or false otherwise.

// Example 1:

// Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
// Output: true
// Explanation: sentence contains at least one of every letter of the English alphabet.
// Example 2:

// Input: sentence = "leetcode"
// Output: false

// Constraints:

// 1 <= sentence.length <= 1000
// sentence consists of lowercase English letters.

class Solution
{
public:
    bool checkIfPangram(string sentence)
    {
        if (sentence.size() < 26)
            return false;
        for (char i = 'a'; i <= 'z'; i++)
            if (find(sentence.begin(), sentence.end(), i) == sentence.end())
                return false;
        return true;
    }
};
