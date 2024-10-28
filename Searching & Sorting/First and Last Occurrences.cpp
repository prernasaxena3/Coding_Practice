//First and Last Occurrences

//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> find(vector<int> arr, int x) {
        // int first = -1;
        // int last  = -1;
        // int start = 0;
        // int end = arr.size()-1;
        // while(start<=end){
        //     if(arr[start] == x && arr[start-1] != x){
        //         first = start;
        //     }
        //     if(arr[end] == x && (arr[end+1] != x || end == arr.size()-1)){
        //         last = end;
        //     }
        //     start++;
        //     end--;
        // }
        // return {first,last};
        
        //USING BINARY SEARCH
        int first = -1;
        int last = -1;
        int start = 0;
        int end = arr.size()-1;
        //first occurence
        while(start<=end){
            int mid = start+ (end-start)/2;
            if(arr[mid] == x){
                first = mid;
                end = mid-1;  // Look for earlier occurrence on the left
            }else if(arr[mid]>x){
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        
        //last occurence
        start = 0;
        end = arr.size()-1;
        while(start<=end){
            int mid = start+ (end-start)/2;
            if(arr[mid] == x){
                last = mid;
                start = mid+1;
            }else if(arr[mid]>x){
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return {first,last};
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int x;
        cin >> x;
        cin.ignore();
        vector<int> ans;
        Solution ob;
        ans = ob.find(arr, x);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}

// } Driver Code Ends
