//Union of two arrays

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template in C++

class Solution {
  public:
    // Function to return the count of number of elements in union of two arrays.
    int doUnion(vector<int> arr1, vector<int> arr2) {
        sort(arr1.begin(),arr1.end());
        sort(arr2.begin(),arr2.end());
        int count = 0;
        int n = arr1.size();
        int m = arr2.size();
        int i = 0,j=0;
        
        while(i<n && j<m){
            if(arr1[i] == arr2[j]){
                count++;
                i++;
                j++;
                //skip duplicates in arr1
                while(i<n && arr1[i] == arr1[i-1])i++;
                
                //skip duplicates in arr2
                while(j<m && arr2[j] == arr2[j-1])j++;
            }else if(arr1[i] < arr2[j]){
                count++;
                i++;
                //skip duplicates in arr1
                while(i<n && arr1[i] == arr1[i-1])i++;
            }else{
                j++;
                count++;
                //skip duplicates in arr2
                while(j<m && arr2[j] == arr2[j-1])j++;
            }
        }
        
        while(i<n){
            i++;
            count++;
            //skip duplicates in arr1
            while(i<n && arr1[i] == arr1[i-1])i++;
        }
        
        while(j<m){
            j++;
            count++;
            //skip duplicates in arr2
            while(j<m && arr2[j] == arr2[j-1])j++;
        }
        
        // while(i<n || j<m){
        //     if(arr1[i] == arr2[j]){
        //         i++;
        //         j++;
        //         count++;
        //     }else if(arr1[i] < arr2[j]){
        //         count++;
        //         i++;
        //     }else{
        //         j++;
        //         count++;
        //     }
        // }
        
        
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after reading t

    while (t--) {
        vector<int> a;
        vector<int> b;

        string input;
        // For a
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        // For b
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss2(input);
        while (ss2 >> number) {
            b.push_back(number);
        }

        Solution ob;
        cout << ob.doUnion(a, b) << endl;
    }

    return 0;
}
// } Driver Code Ends
