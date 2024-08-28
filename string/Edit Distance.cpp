//Edit Distance

/*Given two strings str1 and str2. Return the minimum number of operations required to convert str1 to str2.
The possible operations are permitted:

Insert a character at any position of the string.
Remove any character from the string.
Replace any character from the string with any other character.*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int editDistance(string str1, string str2) {
        // int count = 0;
        // int i = 0,j= 0;
        // while(i< str1.length() && j < str2.length()){
        //     if(str1[i] == str2[j]){
        //         i++;
        //         j++;
        //     }else{
        //         j++;
        //         count++;
        //     }
        // }
        // return count++;
        
        int n = str1.length();
        int m = str2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1));
        for(int i = 0;i<=n;i++){
            for(int j = 0;j<=m;j++){
                if(i == 0){
                    dp[i][j] = j;
                }else if(j == 0){
                    dp[i][j] = i;
                }else if(str1[i-1] == str2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = 1+min({dp[i-1][j],  //remove
                                dp[i][j-1],   //insert
                                dp[i-1][j-1]});  //replace
                }
            }
        }
        return dp[n][m];
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
