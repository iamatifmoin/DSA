// Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

// You must write an algorithm with O(log n) runtime complexity.

// Example 1:

// Input: nums = [1,3,5,6], target = 5
// Output: 2
// Example 2:

// Input: nums = [1,3,5,6], target = 2
// Output: 1
// Example 3:

// Input: nums = [1,3,5,6], target = 7
// Output: 4

// Constraints:

// 1 <= nums.length <= 104
// -104 <= nums[i] <= 104
// nums contains distinct values sorted in ascending order.
// -104 <= target <= 104

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int index = 0;
        int flag = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == target)
            {
                index = i;
                flag = 1;
                break;
            }
            if (nums[i] > target)
            {
                index = i;
                flag = 1;
                break;
            }
        }
        if (flag != 1)
            index = nums.size();
        return index;
    }
};