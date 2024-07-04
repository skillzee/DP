// 62. Unique Paths

#include<bits/stdc++.h>

using namespace std;

    int f(int m, int n, vector<vector<int>> &dp){
        if(m == 0 && n == 0){
            return 1;
        }
        if(m<0 || n<0){
            return 0;
        }

        if(dp[m][n] != -1){
            return dp[m][n];
        }

        int up = f(m-1 , n, dp);
        int left = f(m, n-1, dp);

        return dp[m][n] = up + left;

    }


    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m-1, n-1, dp);
        
    }

int main(){

    int m = 3;
    int n = 2;

    cout << "Number of ways to reach (" << m - 1 << ", " << n - 1 << "): " << uniquePaths(m, n) << endl;

    return 0;
}