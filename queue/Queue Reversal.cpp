//Queue Reversal

//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//function Template for C++

//Function to reverse the queue.
class Solution
{
    public:
    
    void reverse(queue<int> &q){
        if(q.empty()){
            return;
        }
        int num1 = q.front();
        q.pop();
        reverse(q);
        q.push(num1);
    }
    
    queue<int> rev(queue<int> q)
    {
        // stack<int>st;
        // while(!q.empty()){
        //     int temp = q.front();
        //     st.push(temp);
        //     q.pop();
        // }
        // while(!st.empty()){
        //     q.push(st.top());
        //     st.pop();
        // }
        // return q;
        
        reverse(q);
        return q;
    }
};


//{ Driver Code Starts.
int main()
{
    int test;
    cin>>test; 
    while(test--)
    {
    queue<int> q; 
    int n, var; 
    cin>>n; 
    while(n--)
    {
        cin>>var; 
        q.push(var);
    }
    Solution ob;
    queue<int> a=ob.rev(q); 
    while(!a.empty())
    {
        cout<<a.front()<<" ";
        a.pop();
    }
    cout<<endl; 
    }
}
// } Driver Code Ends
