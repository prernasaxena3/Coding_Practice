//Count pairs with given sum

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getPairsCount(const vector<int>& arr, int k) {
        //brute force approach  - O(n^2)
        // int count = 0;
        // for(int i = 0;i<arr.size();i++){
        //     for(int j = i+1;j<arr.size();j++){
        //         if(arr[i]+arr[j] == k){
        //             count++;
        //         }
        //     }
        // }
        // return count;
        
        //optimised one - using hashmap for O(n)
        
        unordered_map<int,int>m;
        int count = 0;
        for(auto num : arr){
            int complement = k-num;
            if(m.find(complement) != m.end()){
                count += m[complement];
            }
            m[num]++;
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t
    while (t--) {
        vector<int> arr;
        int k;

        cin >> k;
        cin.ignore(); // Ignore the newline character after k

        string input;

        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        auto ans = ob.getPairsCount(arr, k);
        cout << ans << "\n";
    }

    return 0;
}
// } Driver Code Ends
