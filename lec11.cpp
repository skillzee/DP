#include<bits/stdc++.h>


using namespace std;

    int f(vector<vector<int>> &triangle, int rows, int cols, vector<vector<int>> &dp){
        int size = triangle.size()-1;
        if(rows == size || cols == triangle[size].size()){
            return triangle[rows][cols];
        }

        if(dp[rows][cols]!=-1){
            return dp[rows][cols];
        }
        int down = triangle[rows][cols] + f(triangle, rows+1, cols,dp);
        int diagonal = triangle[rows][cols] + f(triangle, rows+1, cols+1, dp);

        return dp[rows][cols] = min(down, diagonal);
        
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        
        int rows = triangle.size();
        int cols = triangle[rows-1].size();
        vector<vector<int>> dp(rows, vector<int>(cols, -1));
        return f(triangle, 0, 0, dp);
    }

int main(){

    vector<vector<int> > triangle{{1},
                                   {2, 3},
                                   {3, 6, 7},
                                   {8, 9, 6, 10}};

    cout<<minimumTotal(triangle)<<endl;

    return 0;
}