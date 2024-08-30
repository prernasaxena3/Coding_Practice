//Median in a row-wise sorted Matrix

/*Given a row wise sorted matrix of size R*C where R and C are always odd, find the median of the matrix.*/

//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:

    int countSmallerOrEqual(vector<int> &row, int mid){
        return upper_bound(row.begin(),row.end(),mid)-row.begin();
    }

    int median(vector<vector<int>> &matrix, int R, int C){
        // vector<int>ans;
        // for(int i = 0;i<R;i++){
        //     for(int j = 0;j<C;j++){
        //         ans.push_back(matrix[i][j]);
        //     }
        // }
        // sort(ans.begin(),ans.end());
        // int num = ans.size()/2;
        // return ans[num];
        
        int low = INT_MAX,high = INT_MIN;
        for(int i = 0;i<R;i++){
            for(int j = 0;j<C;j++){
                low = min(low,matrix[i][j]);
                high = max(high,matrix[i][j]);
            }
        }
        
        while(low<=high){
            int mid = low + (high-low)/2;
            int count = 0;
            for(int i = 0;i<R;i++){
                count += countSmallerOrEqual(matrix[i],mid);
            }
            if(count <= (R*C)/2){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return low;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends
