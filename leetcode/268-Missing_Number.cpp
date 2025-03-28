// Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

// Example 1:

// Input: nums = [3,0,1]

// Output: 2

// Explanation:

// n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.

// Example 2:

// Input: nums = [0,1]

// Output: 2

// Explanation:

// n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.

// Example 3:

// Input: nums = [9,6,4,2,3,5,7,0,1]

// Output: 8

// Explanation:

// n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.

// Constraints:

// n == nums.length
// 1 <= n <= 104
// 0 <= nums[i] <= n
// All the numbers of nums are unique.

// bruteforce
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int i;
        for (i = 0; i < n; i++)
        {
            if (count(nums.begin(), nums.end(), i) == 0)
                break;
        }
        return i;
    }
};

// better
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int k = 0;
        for (int it : nums)
        {
            if (it <= k)
                k++;
            else
                break;
        }
        return k;
    }
};

// optimal
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int s, sum;
        s = (n * (n + 1)) / 2;
        for (auto it : nums)
            sum += it;
        return s - sum;
    }
};
