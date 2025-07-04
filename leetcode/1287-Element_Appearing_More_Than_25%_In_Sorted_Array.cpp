// Given an integer array sorted in non-decreasing order, there is exactly one integer in the array that occurs more than 25% of the time, return that integer.

// Example 1:

// Input: arr = [1,2,2,6,6,6,6,7,10]
// Output: 6
// Example 2:

// Input: arr = [1,1]
// Output: 1

// Constraints:

// 1 <= arr.length <= 104
// 0 <= arr[i] <= 105

class Solution
{
public:
    int findSpecialInteger(vector<int> &arr)
    {
        int occurrence = 0.25 * arr.size();

        map<int, int> freq;
        for (auto it : arr)
        {
            freq[it]++;
        }

        int toInt;
        for (auto it : freq)
        {
            toInt = it.second;
            if (toInt > occurrence)
            {
                return it.first;
            }
        }

        return 0;
    }
};
