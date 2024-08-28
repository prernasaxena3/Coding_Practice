//Next Permutation

/*Implement the next permutation, which rearranges the list of numbers into Lexicographically next greater permutation of list of numbers.
If such arrangement is not possible, it must be rearranged to the lowest possible order i.e. sorted in an ascending order. 
You are given an list of numbers arr[ ] of size N.*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        // code here
        // next_permutation(arr.begin(),arr.end());
        // return arr;
        int index = -1;
        for(int i = N-2;i>=0;i--){
            if(arr[i] <arr[i+1]){
                index = i;
                break;
            }
        }
        if(index == -1){
            reverse(arr.begin(),arr.end());
            return arr;
        }
        for(int i = N-1;i>index;i--){
            if(arr[i] > arr[index]){
                swap(arr[i],arr[index]);
                break;
            }
        }
        reverse(arr.begin()+index+1,arr.end());
        return arr;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
