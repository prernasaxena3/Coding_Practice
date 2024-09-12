//Array Subset

//Given two arrays: a1[0..n-1] of size n and a2[0..m-1] of size m, where both arrays may contain duplicate elements. 
//The task is to determine whether array a2 is a subset of array a1. It's important to note that both arrays can be sorted or unsorted. 
//Additionally, each occurrence of a duplicate element within an array is considered as a separate element of the set.

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m) ;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        int a1[n], a2[m];

        for (int i = 0; i < n; i++) {
            cin >> a1[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> a2[i];
        }

        cout << isSubset(a1, a2, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends


string isSubset(int a1[], int a2[], int n, int m) {
    
    //current implementation does not account for duplicate elements in a2. 
    // unordered_map<int,int>m1;
    // for(int i = 0;i<n;i++){
    //     m1[a1[i]]++;
    // }
    // for(int i = 0;i<m;i++){
    //     if(m1.find(a2[i]) == m1.end()){
    //         return "No";
    //     }
    // }
    // return "Yes";
    
    unordered_map<int, int> m1;
    
    // Store frequency of elements of a1
    for (int i = 0; i < n; i++) {
        m1[a1[i]]++;
    }
    
    // Check if all elements of a2 are in a1 with correct frequency
    for (int i = 0; i < m; i++) {
        if (m1.find(a2[i]) == m1.end() || m1[a2[i]] == 0) {
            return "No";
        }
        m1[a2[i]]--; // Decrease the count
    }
    
    return "Yes";
}
