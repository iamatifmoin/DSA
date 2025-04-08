// You are given an m x n 2D array grid of positive integers.

// Your task is to traverse grid in a zigzag pattern while skipping every alternate cell.

// Zigzag pattern traversal is defined as following the below actions:

// Start at the top-left cell (0, 0).
// Move right within a row until the end of the row is reached.
// Drop down to the next row, then traverse left until the beginning of the row is reached.
// Continue alternating between right and left traversal until every row has been traversed.
// Note that you must skip every alternate cell during the traversal.

// Return an array of integers result containing, in order, the value of the cells visited during the zigzag traversal with skips.

// Example 1:

// Input: grid = [[1,2],[3,4]]

// Output: [1,4]

// Explanation:

// Example 2:

// Input: grid = [[2,1],[2,1],[2,1]]

// Output: [2,1,2]

// Explanation:

// Example 3:

// Input: grid = [[1,2,3],[4,5,6],[7,8,9]]

// Output: [1,3,5,7,9]

// Explanation:

// Constraints:

// 2 <= n == grid.length <= 50
// 2 <= m == grid[i].length <= 50
// 1 <= grid[i][j] <= 2500

class Solution
{
public:
    vector<int> zigzagTraversal(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int count;
        vector<int> res;
        int i, j;
        int lastAccepted;
        int diff = 0;

        for (i = 0; i < m; i++)
        {

            if (i % 2 == 0)
            {
                for (j = 0 + diff; j < n; j++)
                {
                    diff = 0;
                    if (j == i || abs(j - i) > 1)
                    {
                        res.emplace_back(grid[i][j]);
                        lastAccepted = j;
                        j++;
                    }
                }
                if (lastAccepted == n - 1)
                    diff = 1;
            }
            else
            {
                for (j = n - 1 - diff; j >= 0; j--)
                {
                    diff = 0;
                    if (j == i || abs(j - i) > 1)
                    {
                        res.emplace_back(grid[i][j]);
                        lastAccepted = j;
                        j--;
                    }
                    if (lastAccepted == 0)
                        diff = 1;
                }
            }
        }

        return res;
    }
};
