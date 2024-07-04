// Unique Grids 02

#include <bits/stdc++.h>

using namespace std;

int f(int m, int n, vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp)
{
    if (m == 0 and n == 0 and obstacleGrid[m][n] == 0)
    {
        return 1;
    }

    if (m < 0 or n < 0 or obstacleGrid[m][n] != 0)
    {
        return 0;
    }

    if (dp[m][n] != -1)
    {
        return dp[m][n];
    }

    int left = f(m - 1, n, obstacleGrid, dp);
    int up = f(m, n - 1, obstacleGrid, dp);

    return dp[m][n] = left + up;
}

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));

    return f(m - 1, n - 1, obstacleGrid, dp);
}

int main()
{
    vector<vector<int>> maze{
        {0, 0, 0},
        {0, -1, 0},
        {0, 0, 0}
    };

    cout << "Number of paths when obstacle included: " << uniquePathsWithObstacles(maze)<<endl;

    return 0;
}