// Count derangements

/*A Derangement is a permutation of ‘N’ elements, such that no element appears in its original position. 
For example, an instance of derangement of {0, 1, 2, 3} is {2, 3, 1, 0}, because 2 present at index 0 is not at its initial position which is 2 and similarly for other elements of the sequence.

Given a number ‘N’, find the total number of derangements possible of a set of 'N’ elements.

Note:
The answer could be very large, output answer %(10 ^ 9 + 7).*/

#include <iostream>
#include <vector>
#define MOD 1000000007

long long int solve(int n,vector<long long int>&dp){
    //base case
    if(n==1) return 0;
    if(n == 2) return 1;
    if(dp[n] != -1) return dp[n];
    // dp[n] = ((n-1)%MOD )*(((solve(n-1,dp))%MOD) + ((solve(n-2,dp))%MOD));
    dp[n] = ((n - 1) * ((solve(n - 1, dp) + solve(n - 2, dp)) % MOD)) % MOD;
    return dp[n];
}

long long int solveTab(int n){
    vector<long long int>dp(n+1,0);
    dp[1] = 0;
    dp[2] = 1;
    for(int i = 3;i<=n;i++){
        long long int num1 = dp[i-1]%MOD;
        long long int num2 = dp[i-2]%MOD;
        long long int sum = (num1+num2)%MOD;
        long long int ans = ((i-1)*sum)%MOD;
        dp[i] = ans;
    }
    return dp[n];
}

long long int countDerangements(int n) {
    // Write your code here.

    // vector<long long int>dp(n+1,-1);
    // return solve(n,dp);

    return solveTab(n);
}
