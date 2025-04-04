// You are given a string sentence that consist of words separated by spaces. Each word consists of lowercase and uppercase letters only.

// We would like to convert the sentence to "Goat Latin" (a made-up language similar to Pig Latin.) The rules of Goat Latin are as follows:

// If a word begins with a vowel ('a', 'e', 'i', 'o', or 'u'), append "ma" to the end of the word.
// For example, the word "apple" becomes "applema".
// If a word begins with a consonant (i.e., not a vowel), remove the first letter and append it to the end, then add "ma".
// For example, the word "goat" becomes "oatgma".
// Add one letter 'a' to the end of each word per its word index in the sentence, starting with 1.
// For example, the first word gets "a" added to the end, the second word gets "aa" added to the end, and so on.
// Return the final sentence representing the conversion from sentence to Goat Latin.

// Example 1:

// Input: sentence = "I speak Goat Latin"
// Output: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
// Example 2:

// Input: sentence = "The quick brown fox jumped over the lazy dog"
// Output: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"

// Constraints:

// 1 <= sentence.length <= 150
// sentence consists of English letters and spaces.
// sentence has no leading or trailing spaces.
// All the words in sentence are separated by a single space.

class Solution
{
public:
    string toGoatLatin(string sentence)
    {

        sentence = sentence + " ";
        int n = sentence.size();
        char ch, temp;
        string word = "";
        int wordCount = 0, copyCount;
        string str = "";
        for (int i = 0; i < n; i++)
        {
            ch = sentence[i];

            if (ch != ' ')
                word += ch;

            else
            {
                wordCount++;
                if (word[0] == 'a' || word[0] == 'e' || word[0] == 'i' || word[0] == 'o' || word[0] == 'u' || word[0] == 'A' || word[0] == 'E' || word[0] == 'I' || word[0] == 'O' || word[0] == 'U')
                    word += "ma";

                else
                {
                    temp = word[0];
                    word = word.substr(1) + temp + "ma";
                }

                copyCount = wordCount;
                while (copyCount > 0)
                {
                    word = word + 'a';
                    copyCount--;
                }

                str += word + " ";
                word = "";
            }
        }

        return str.substr(0, str.length() - 1);
    }
};
