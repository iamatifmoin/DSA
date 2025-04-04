// You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

// Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

// The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

// Example 1:

// Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
// Output: 16
// Explanation: The perimeter is the 16 yellow stripes in the image above.
// Example 2:

// Input: grid = [[1]]
// Output: 4
// Example 3:

// Input: grid = [[1,0]]
// Output: 4

// Constraints:

// row == grid.length
// col == grid[i].length
// 1 <= row, col <= 100
// grid[i][j] is 0 or 1.
// There is exactly one island in grid.

class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        int peri = 0;
        int count;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    count = 4;
                    if (i - 1 >= 0)
                    {
                        if (grid[i - 1][j] == 1)
                            count--;
                    }
                    if (i + 1 < m)
                    {
                        if (grid[i + 1][j] == 1)
                            count--;
                    }
                    if (j - 1 >= 0)
                    {
                        if (grid[i][j - 1] == 1)
                            count--;
                    }
                    if (j + 1 < n)
                    {
                        if (grid[i][j + 1] == 1)
                            count--;
                    }
                    peri += count;
                }
            }
        }
        return peri;
    }
};
