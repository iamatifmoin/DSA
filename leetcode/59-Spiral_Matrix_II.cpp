// Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

// Example 1:

// Input: n = 3
// Output: [[1,2,3],[8,9,4],[7,6,5]]
// Example 2:

// Input: n = 1
// Output: [[1]]

// Constraints:

// 1 <= n <= 20

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int limit = n * n;
        int item = 1;

        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = n - 1;

        while (top <= bottom && left <= right)
        {

            for (int i = left; i <= right; i++)
                matrix[top][i] = item++;
            top++;

            for (int i = top; i <= bottom; i++)
                matrix[i][right] = item++;
            right--;

            for (int i = right; i >= left; i--)
                matrix[bottom][i] = item++;
            bottom--;

            for (int i = bottom; i >= top; i--)
                matrix[i][left] = item++;
            left++;
        }

        return matrix;
    }
};
