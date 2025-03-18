// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

// Note that you must do this in-place without making a copy of the array.

// Example 1:

// Input: nums = [0,1,0,3,12]
// Output: [1,3,12,0,0]
// Example 2:

// Input: nums = [0]
// Output: [0]

// Constraints:

// 1 <= nums.length <= 104
// -231 <= nums[i] <= 231 - 1

// bruteforce
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int n = nums.size();
        int p = 0;
        int temp = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                p = i + 1;
                while (p < n && nums[p] == 0)
                    p++;
                if (p < nums.size())
                {
                    temp = nums[p];
                    nums[p] = nums[i];
                    nums[i] = temp;
                }
            }
        }
    }
};

// optimal
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int j = -1;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] == 0)
            {
                j = i;
                break;
            }

        if (j == -1)
            return;

        for (int i = j + 1; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};
