// Minimun falling path sum  Leetcode(931)

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        // Copy the first row to the dp array
        for (int i = 0; i < cols; ++i) {
            dp[0][i] = matrix[0][i];
        }

        // Fill the dp array
        for (int i = 1; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                int up = dp[i - 1][j];
                int left = (j > 0) ? dp[i - 1][j - 1] : INT_MAX;
                int right = (j < cols - 1) ? dp[i - 1][j + 1] : INT_MAX;

                dp[i][j] = matrix[i][j] + min(up, min(left, right));
            }
        }

        // Find the minimum in the last row
        int mini = INT_MAX;
        for (int i = 0; i < cols; ++i) {
            mini = min(mini, dp[rows - 1][i]);
        }

        return mini;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {2, 1, 3},
        {6, 5, 4},
        {7, 8, 9}
    };
    cout << sol.minFallingPathSum(matrix) << endl; // Output: 13
    return 0;
}
