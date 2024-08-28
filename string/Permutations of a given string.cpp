//Permutations of a given string

/*Given a string S. The task is to print all unique permutations of the given string that may contain dulplicates in lexicographically sorted order. */

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    void solve(string &S,set<string>&ans,int index){
	        //base case
	        if(index>= S.length()){
	            ans.insert(S);
	            return;
	        }
	        for(int j = index;j<S.length();j++){
	            swap(S[index],S[j]);
	            solve(S,ans,index+1);
	            swap(S[index],S[j]);
	        }
	    }
	
		vector<string>find_permutation(string S)
		{
		  //  vector<string>ans;
		  //  sort(S.begin(),S.end()); //to ensure we start from the smallest lexicographicall order
		  //  ans.push_back(S);
		  //  while(next_permutation(S.begin(),S.end())){
		  //      ans.push_back(S);
		  //  }
		  //  return ans;
		  set<string>ans;
		  int index = 0;
		  solve(S,ans,index);
		  vector<string>a(ans.begin(),ans.end());
		  return a;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends
