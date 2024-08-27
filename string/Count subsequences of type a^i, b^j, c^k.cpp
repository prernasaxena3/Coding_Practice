//Count subsequences of type a^i, b^j, c^k

/*Given a string S, the task is to count number of subsequences of the form aibjck, where i >= 1, j >=1 and k >= 1.

Note: 
1. Two subsequences are considered different if the set of array indexes picked for the 2 subsequences are different.
2.  For large test cases, the output value will be too large, return the answer MODULO 10^9+7*/

//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template 

class Solution{
  public:
    // s : given string
    // return the expected answer
    int fun(string &s) {
        long long int aCount = 0,bCount = 0,cCount = 0;
        long long int mod = 1e9+7;
        int n = s.length();
        for(int i = 0;i<n;i++){
            if(s[i] == 'a'){
                aCount = ((2*aCount)+1) %mod;
            }else if(s[i] == 'b'){
                bCount = ((2*bCount)+aCount) %mod;
            }else if(s[i] == 'c'){
                cCount = ((2*cCount)+bCount) %mod;
            }
        }
        return cCount;
    }
};

//{ Driver Code Starts.
 
int main()
 {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.fun(s)<<endl;
    }
	return 0;
}
// } Driver Code Ends
