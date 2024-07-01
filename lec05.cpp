// Maximum sum of  non-adjacent elements
// House Robber Problem



#include<bits/stdc++.h>

using namespace std;

int f(int ind, vector<int> &nums, vector<int> &dp){
    if(ind == 0){
        return nums[ind];
    }

    if(ind<0){
        return 0;
    }

    if(dp[ind]!=-1) return dp[ind];

    int pick = nums[ind] + f(ind-2, nums, dp );
    int notPick = 0 + f(ind-1, nums, dp);

    return dp[ind] = max(pick, notPick);
}


int solve(int ind,vector<int> &arr){
    vector<int> dp(ind, -1);
    return f(ind-1, arr,dp); // Size se ek kamm jaayega bcoz of zero based indexing
}


int main(){
    vector<int> arr{2, 1, 4, 9};
    int n = arr.size();
    
    cout << solve(n, arr)<<endl;

    return 0;
}