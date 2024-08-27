//Split the binary string into substrings with equal number of 0s and 1s

/*Given binary string str of length N. The task is to find the maximum count of consecutive substrings str can be divided into such that all the substrings are balanced i.e. they have an equal number of 0s and 1s. 
If it is not possible to split str satisfying the conditions then return -1.*/

//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int maxSubStr(string str){
        int zero = 0,one = 0,count = 0;
        int len = 0;
        for(int i = 0;i<str.length();i++){
            if(str[i] == '0'){
                zero++;
            }else{
                one++;
            }
            if(one == zero && zero != 0){
                count++;
                len += (zero+one);
                zero = 0;
                one = 0;
            }
        }
        if(len != str.length()){
            return -1;
        }
        return count;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.maxSubStr(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends
