// Given an integer numRows, return the first numRows of Pascal's triangle.

// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
// Example 1:

// Input: numRows = 5
// Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
// Example 2:

// Input: numRows = 1
// Output: [[1]]

// Constraints:

// 1 <= numRows <= 30

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        int count = 1;
        vector<vector<int>> res;
        while (count <= numRows)
        {
            vector<int> temp(count);
            temp[0] = 1;
            temp[count - 1] = 1;
            if (count > 2)
            {
                int pointer = 1;
                vector<int> prevArray;
                for (int num : res.back())
                    prevArray.emplace_back(num);

                for (int i = 0; i < count - 2; i++)
                {
                    temp[pointer] = prevArray[i] + prevArray[i + 1];
                    pointer++;
                }
            }
            res.emplace_back(temp);
            count++;
        }
        return res;
    }
};