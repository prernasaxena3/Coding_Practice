//Count Ways To Reach The N-th Stairs

/*You have been given a number of stairs. Initially, you are at the 0th stair, and you need to reach the Nth stair.
Each time, you can climb either one step or two steps.
You are supposed to return the number of distinct ways you can climb from the 0th step to the Nth step.*/

#include <bits/stdc++.h> 

#define MOD 1000000007

int solve(int n,int i,vector<int>&dp){
    //base case
    if(i == n){
        return 1;
    }
    if(i>n){
        return 0;
    }
    if(dp[i] != -1){
        return dp[i];
    }
    dp[i] = (solve(n,i+1,dp)+solve(n,i+2,dp))%MOD;
    return dp[i];
}
int countDistinctWays(int nStairs) {
    //  Write your code here.
    // if(nStairs < 0){
    //     return 0;
    // }
    // if(nStairs == 0){
    //     return 1;
    // }
    // int ans = countDistinctWays(nStairs-1) +
    //     countDistinctWays(nStairs-2);
    
    // return ans;
    vector<int>dp(nStairs+1,-1);
    int ans = solve(nStairs,0,dp);
    return ans;
}
