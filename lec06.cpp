// House Robber 2

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
    return f(ind-1, arr,dp);
}

int rob(vector<int>& nums) {
    vector<int> temp1, temp2;
    int size = nums.size();
    if(size == 1){
        return nums[0];
    }
    for(int i = 0; i<size; i++){
        if(i!=0) temp1.push_back(nums[i]);
        if(i!=size-1) temp2.push_back(nums[i]);
    }
    int one = solve(size-1, temp1);
    int two = solve(size-1, temp2);
    return max(one, two);
}

int main(){
    vector<int> arr{2, 1, 4, 9};
    
    cout << rob(arr)<<endl;
}