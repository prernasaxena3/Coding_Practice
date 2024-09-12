//Arranging the array

/*You are given an array of size N. Rearrange the given array in-place such that all the negative numbers occur before all non-negative numbers.
(Maintain the order of all -ve and non-negative numbers as given in the original array).*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long

// } Driver Code Ends
class Solution
{
    public:
        void Rearrange(int arr[], int n)
        {
            //wrong approach
            // for(int i = 0;i<n;i++){
            //     for(int j = 0;j<n;j++)
            //     if(arr[j]>arr[j+1] && arr[j+1]<0){
            //         swap(arr[j],arr[j+1]);
            //     }
            // }
            
            
            //right approach
            /*vector<int>pos,neg;
            for(int i = 0;i<n;i++){
                if(arr[i]<0){
                    neg.push_back(arr[i]);
                }else{
                    pos.push_back(arr[i]);
                }
            }
            for(int i = 0;i<neg.size();i++){
                arr[i] = neg[i];
            }
            for(int i = neg.size();i<n;i++){
                arr[i] = pos[i-neg.size()];
            }*/
            
            //second right approach
            stack<int>s;
            stack<int>m;
            for(int i = n-1;i>=0;i--){
                if(arr[i]<0){
                    s.push(arr[i]);
                }else{
                    m.push(arr[i]);
                }
            }
            int i = 0;
            while(!s.empty()){
                arr[i] = s.top();
                s.pop();
                i++;
            }
            while(!m.empty()){
                arr[i] = m.top();
                m.pop();
                i++;
            }
        }
};

//{ Driver Code Starts.
void Rearrange(int arr[], int n);

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
        long long j=0;
        Solution ob;
        ob.Rearrange(arr, n);
      
        for (int i = 0; i < n; i++) 
            cout << arr[i] << " "; 
        cout << endl;  
    }
    return 0; 
} 
// } Driver Code Ends
