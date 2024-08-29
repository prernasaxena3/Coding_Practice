//Find distinct elements

/*Given a N x N matrix M. Write a program to find count of all the distinct elements common to all rows of the matrix. Print count of such elements.*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int distinct(vector<vector<int>> M, int N)
    {
        unordered_set<int>s;
        unordered_map<int,int>m;
        vector<int>ans;
        for(int i = 0;i<N;i++){
            for(int j = 0;j<N;j++){
                s.insert(M[i][j]);
            }
            for(auto it:s){
                m[it]++;
            }
            s.clear();
        }
        for(auto it:m){
            if(it.second == N){
                ans.push_back(it.first);
            }
        }
        return ans.size();
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> M(N, vector<int>(N, 0));
        for(int i = 0;i < N*N; i++)
            cin>>M[i/N][i%N];
        
        Solution ob;
        cout<<ob.distinct(M, N)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
