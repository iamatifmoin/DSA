// You are given a 0-indexed 2D integer array brackets where brackets[i] = [upperi, percenti] means that the ith tax bracket has an upper bound of upperi and is taxed at a rate of percenti. The brackets are sorted by upper bound (i.e. upperi-1 < upperi for 0 < i < brackets.length).

// Tax is calculated as follows:

// The first upper0 dollars earned are taxed at a rate of percent0.
// The next upper1 - upper0 dollars earned are taxed at a rate of percent1.
// The next upper2 - upper1 dollars earned are taxed at a rate of percent2.
// And so on.
// You are given an integer income representing the amount of money you earned. Return the amount of money that you have to pay in taxes. Answers within 10-5 of the actual answer will be accepted.

// Example 1:

// Input: brackets = [[3,50],[7,10],[12,25]], income = 10
// Output: 2.65000
// Explanation:
// Based on your income, you have 3 dollars in the 1st tax bracket, 4 dollars in the 2nd tax bracket, and 3 dollars in the 3rd tax bracket.
// The tax rate for the three tax brackets is 50%, 10%, and 25%, respectively.
// In total, you pay $3 * 50% + $4 * 10% + $3 * 25% = $2.65 in taxes.
// Example 2:

// Input: brackets = [[1,0],[4,25],[5,50]], income = 2
// Output: 0.25000
// Explanation:
// Based on your income, you have 1 dollar in the 1st tax bracket and 1 dollar in the 2nd tax bracket.
// The tax rate for the two tax brackets is 0% and 25%, respectively.
// In total, you pay $1 * 0% + $1 * 25% = $0.25 in taxes.
// Example 3:

// Input: brackets = [[2,50]], income = 0
// Output: 0.00000
// Explanation:
// You have no income to tax, so you have to pay a total of $0 in taxes.

// Constraints:

// 1 <= brackets.length <= 100
// 1 <= upperi <= 1000
// 0 <= percenti <= 100
// 0 <= income <= 1000
// upperi is sorted in ascending order.
// All the values of upperi are unique.
// The upper bound of the last tax bracket is greater than or equal to income.

class Solution
{
public:
    double calculateTax(vector<vector<int>> &brackets, int income)
    {

        double tax = 0;
        int sum = 0;
        int taxable;
        int m = brackets.size();
        for (int i = 0; i < m; i++)
        {
            if (i == 0)
                taxable = brackets[i][0];
            else
                taxable = brackets[i][0] - brackets[i - 1][0];

            if (sum + taxable <= income)
            {
                sum += taxable;
                tax += (double)(taxable * brackets[i][1]) / 100;
            }
            else
            {
                taxable = income - sum;
                tax += (double)(taxable * brackets[i][1]) / 100;
                break;
            }
        }

        return tax;
    }
};
