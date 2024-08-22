//Same characters in two strings

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int sameChar(string A, string B)
    {
        int count = 0;
        int i = 0;
        int j = 0;
        transform(A.begin(), A.end(), A.begin(), ::toupper); 
        transform(B.begin(), B.end(), B.begin(), ::toupper); 
        while(i<A.length() && j <B.length()){
            if(A[i] == B[j]){
                count++;
            }
            i++;
            j++;
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
        string A,B;
        cin>>A;
        cin>>B;
        Solution ob;
        cout<<ob.sameChar(A,B)<<endl;
    }
    return 0;
}
// } Driver Code Ends
