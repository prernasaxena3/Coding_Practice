//Smallest subarray with sum greater than x

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int smallestSubWithSum(int x, vector<int>& arr) {
        //approach 1 - sliding window
        
        //approach 2
        int currSum = 0 ;
        int n = arr.size();
        int minLen = n+1;
        int start = 0,end = 0;
        while(end<n){
            while(currSum <= x && end < n){
                currSum += arr[end++];
            }
            while(currSum > x && start<n){
                if(end-start < minLen){
                    minLen = end-start;
                }
                currSum -= arr[start++];
            }
        }
        return minLen == n+1?0:minLen;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        vector<int> arr;
        int x;

        cin >> x;
        cin.ignore(); // Ignore the newline character after x

        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution obj;
        cout << obj.smallestSubWithSum(x, arr) << endl;
    }

    return 0;
}
// } Driver Code Ends
