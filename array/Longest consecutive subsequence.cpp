//Longest consecutive subsequence

//Given an array of non-negative integers. 
//Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        // int count = 0;
        // sort(arr,arr+N);
        // for(int i = 0;i<N-1;i++){
        //     if((arr[i]-arr[i+1]) <= 1){
        //         count++;
        //     }else{
        //         return count;
        //     }
        // }
        // return count;
        
        int longest = 1;
        int count = 1;
        if(N==0){
            return 0;
        }
        sort(arr,arr+N);
        for(int i = 1;i<N;i++){
            if(arr[i] == arr[i-1])continue;
            
            if(arr[i] == arr[i-1]+1){
                count++;
            }else{
                longest = max(longest,count);
                count = 1;
            }
        }
        return max(longest,count);
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends
