//Subarray with 0 sum

/*Given an array of integers. Find if there is a subarray (of size at-least one) with 0 sum. 
You just need to return true/false depending upon whether there is a subarray present with 0-sum or not.
Printing will be taken care by the driver code.*/

//{ Driver Code Starts
// A C++ program to find if there is a zero sum
// subarray
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        //only 3 test cases passed
        
        // sort(arr,arr+n);
        // bool ans = false;
        // int sum = 0;
        // for(int i = 0;i<n;i++){
        //     for(int j = i;j<n;j++){
        //         sum += arr[j];
        //         if(sum == 0){
        //             ans = true;
        //         }
        //     }
        // }
        // return ans;
        
        
        
        int sum[n+1];
        sum[0] = arr[0];
        //finding cumulative sum
        for(int i = 1;i<=n;i++){
            sum[i] = sum[i-1]+arr[i-1];
        }
        
        sort(sum,sum+n+1);
        //checking is repeated sum exists
        for(int i = 1;i<=n;i++){
                if(sum[i] == sum[i-1]){
                    return true;
                }
            
        }
        return false;
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    Solution obj;
	    	if (obj.subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}
// } Driver Code Ends
