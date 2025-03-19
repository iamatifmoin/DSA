// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

// Example 1:

// Input: nums = [3,2,3]
// Output: 3
// Example 2:

// Input: nums = [2,2,1,1,1,2,2]
// Output: 2

// Constraints:

// n == nums.length
// 1 <= n <= 5 * 104
// -109 <= nums[i] <= 109

// bruteforce
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int maj = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (count(nums.begin(), nums.end(), nums[i]) > (nums.size() / 2))
            {
                maj = nums[i];
                break;
            }
        }
        return maj;
    }
};

// optimal
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int maj = 0;
        unordered_map<int, int> freq;
        for (auto it : nums)
            freq[it]++;
        for (auto it : freq)
        {
            if (it.second > (nums.size() / 2))
                return it.first;
        }
        return 0;
    }
};

// moore's voting algo
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int count = 0;
        int elem;
        for (int i = 0; i < nums.size(); i++)
        {
            if (count == 0)
            {
                count = 1;
                elem = nums[i];
            }
            else if (nums[i] == elem)
                count++;
            else
                count--;
        }

        // dont do this loop as it is mentioned that maj elem always exists
        for (auto it : nums)
            if (it == elem)
                count++;
        if (count > nums.size() / 2)
            return elem;
        return -1;
    }
};
