
// Input: nums = [10,12,13,14]

// Output: 1

// Explanation:

// nums becomes [1, 3, 4, 5] after all replacements, with minimum element 1.

// Example 2:

// Input: nums = [1,2,3,4]

// Output: 1

// Explanation:

// nums becomes [1, 2, 3, 4] after all replacements, with minimum element 1.

// Example 3:

// Input: nums = [999,19,199]

// Output: 10

// Explanation:

// nums becomes [27, 10, 19] after all replacements, with minimum element 10.

// Constraints:

// 1 <= nums.length <= 100
// 1 <= nums[i] <= 104

class Solution
{
public:
    int sumOfDig(int num)
    {
        int sum = 0, d;
        while (num > 0)
        {
            d = num % 10;
            sum += d;
            num = num / 10;
        }
        return sum;
    }
    int minElement(vector<int> &nums)
    {
        int min = nums[0];
        for (int i = 0; i < nums.size(); i++)
            nums[i] = sumOfDig(nums[i]);

        for (auto it : nums)
            if (it < min)
                min = it;

        return min;
    }
};
