//Row with max 1s

/*You are given a 2D array consisting of only 1's and 0's, where each row is sorted in non-decreasing order. You need to find and return the index of the first row that has the most number of 1s. If no such row exists, return -1.
Note: 0-based indexing is followed.*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > &arr) {
        // int row = -1;
        // int count = 0;
        // int val = 0;
        // int n = arr.size();
        // int m = arr[0].size();
        // for(int i = 0;i<n;i++){
        //     for(int j = 0;j<m;j++){
        //         if(arr[i][j] == 1){
        //             count++;
        //         }
        //     }
        //     if(val < count){
        //         row = i;
        //         val = count;
        //         count = 0;
        //     }
        // }
        // return row;
        
        int row = -1;
        int n = arr.size();
        int m = arr[0].size();
        int j = m-1;
        for(int i = 0;i<n;i++){
            while(j>=0 && arr[i][j] == 1){
                j--;
                row  = i;
            }
        }
        
        return row;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
