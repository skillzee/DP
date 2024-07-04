// Minimum path sum

#include <bits/stdc++.h>

using namespace std;

int f(int m, int n, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (m == 0 and n == 0)
    {
        return grid[0][0];
    }
    if (m < 0 or n < 0)
    {
        return 9999;
    }

    if (dp[m][n] != -1)
    {
        return dp[m][n];
    }

    int up = grid[m][n] + f(m - 1, n, grid, dp);
    int left = grid[m][n] + f(m, n - 1, grid, dp);

    return dp[m][n] = min(up, left);
}

int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));

    return f(m - 1, n - 1, grid, dp);
}

int main()
{

    vector<vector<int>> matrix{
        {5, 9, 6},
        {11, 5, 2}
    };

    cout << "Minimum Path Sum: "<<minPathSum(matrix)<<endl;

    return 0;
}