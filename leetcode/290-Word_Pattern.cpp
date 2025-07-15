// Given a pattern and a string s, find if s follows the same pattern.

// Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s. Specifically:

// Each letter in pattern maps to exactly one unique word in s.
// Each unique word in s maps to exactly one letter in pattern.
// No two letters map to the same word, and no two words map to the same letter.

// Example 1:

// Input: pattern = "abba", s = "dog cat cat dog"

// Output: true

// Explanation:

// The bijection can be established as:

// 'a' maps to "dog".
// 'b' maps to "cat".
// Example 2:

// Input: pattern = "abba", s = "dog cat cat fish"

// Output: false

// Example 3:

// Input: pattern = "aaaa", s = "dog cat cat dog"

// Output: false

// Constraints:

// 1 <= pattern.length <= 300
// pattern contains only lower-case English letters.
// 1 <= s.length <= 3000
// s contains only lowercase English letters and spaces ' '.
// s does not contain any leading or trailing spaces.
// All the words in s are separated by a single space.

class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        int patLen = pattern.size();
        int senLen = 0;
        vector<string> words;
        string word = "";
        s = s + ' ';
        for (auto it : s)
        {
            if (it == ' ')
            {
                senLen++;
                words.emplace_back(word);
                word.clear();
            }
            else
                word += it;
        }

        if (patLen != senLen)
            return false;

        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;

        for (int i = 0; i < patLen; i++)
        {

            if (charToWord.count(pattern[i]) && charToWord[pattern[i]] != words[i])
                return false;
            if (wordToChar.count(words[i]) && wordToChar[words[i]] != pattern[i])
                return false;

            charToWord[pattern[i]] = words[i];
            wordToChar[words[i]] = pattern[i];
        }

        return true;

        return true;
    }
};
