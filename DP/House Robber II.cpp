//House Robber II

/*Mr. X is a professional robber planning to rob houses along a street. Each house has a certain amount of money hidden.
All houses along this street are arranged in a circle. That means the first house is the neighbour of the last one. 
Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses are broken into on the same night.
You are given an array/list of non-negative integers 'ARR' representing the amount of money of each house. 
Your task is to return the maximum amount of money Mr. X can rob tonight without alerting the police.
Note:
It is possible for Mr. X to rob the same amount of money by looting two different sets of houses. Just print the maximum possible robbed amount, irrespective of sets of houses robbed.
For example:
(i) Given the input array arr[] = {2, 3, 2} the output will be 3 because Mr X cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses. So, he’ll rob only house 2 (money = 3)

(ii) Given the input array arr[] = {1, 2, 3, 1} the output will be 4 because Mr X rob house 1 (money = 1) and then rob house 3 (money = 3).

(iii) Given the input array arr[] = {0} the output will be 0 because Mr. X has got nothing to rob.*/

#include <bits/stdc++.h> 
long long int solve(vector<int>&nums,int n,vector<long long int>&dp){
    if(n <0) return 0;
    if(n == 0) return nums[0];
    if(dp[n] != -1) return dp[n];
    
    long long int inc = solve(nums,n-2,dp)+nums[n];
    long long int exc = solve(nums,n-1,dp)+0;
    dp[n] = max(inc,exc);
    return dp[n];
}
long long int houseRobber(vector<int>& valueInHouse)
{
    int n = valueInHouse.size();
    if(n == 1){
        return valueInHouse[0];
    }
    vector<int>first,second;
    for(int i = 0;i<n;i++){
        if(i != n-1){
            first.push_back(valueInHouse[i]);
        }
        if(i != 0){
            second.push_back(valueInHouse[i]);
        }
    }

    vector<long long int>dp1(first.size(),-1);
    vector<long long int>dp2(second.size(),-1);
    return max(solve(first,first.size()-1,dp1),solve(second,second.size()-1,dp2));
}
