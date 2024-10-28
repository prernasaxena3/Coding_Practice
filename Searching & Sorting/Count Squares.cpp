//Count Squares

/*Consider a sample space S consisting of all perfect squares starting from 1, 4, 9 and so on. You are given a number N, you have to output the number of integers less than N in the sample space S.*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSquares(int N) {
        // int count = 0;
        // for(int i = 1;i<N;i++){
        //     int num = i*i;
        //     if(num<N){
        //         count++;
        //     }else{
        //         return count;
        //     }
        // }
        // return count;
        return sqrt(N - 1);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.countSquares(N) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends
