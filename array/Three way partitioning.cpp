///Three way partitioning

/*Given an array of size n and a range [a, b]. The task is to partition the array around the range such that the array is divided into three parts.
1) All elements smaller than a come first.
2) All elements in range a to b come next.
3) All elements greater than b appear in the end.
The individual elements of three sets can appear in any order. You are required to return the modified array.*/


//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    //Function to partition the array around the range such 
    //that array is divided into three parts.
    void threeWayPartition(vector<int>& array,int a, int b)
    {
        //approach 1 
        
        // vector<int>less;
        // vector<int>between;
        // vector<int>more;
        // for(int i = 0;i<array.size();i++){
        //     if(array[i] < a){
        //         less.push_back(array[i]);
        //     }else if(array[i] >= a && array[i] <= b){
        //         between.push_back(array[i]);
        //     }else{
        //         more.push_back(array[i]);
        //     }
        // }
        
        // int index = 0;
        // for(int i = 0;i<less.size();i++){
        //     array[index++] = less[i];
        // }
        // for(int i = 0;i<between.size();i++){
        //     array[index++] = between[i];
        // }
        // for(int i = 0;i<more.size();i++){
        //     array[index++] = more[i];
        // }
        
        //approach 2
        //Dutch National Flag algorithm
        
        // int low = 0;
        // int high = array.size()-1;
        // int i = 0;
        // while(i<=high){
        //     if(array[i] <a){
        //         swap(array[i],array[low]);
        //         i++;
        //         low++;
        //     }
        //     else if(array[i] >=a && array[i] <=b){
        //         i++;
        //     }
        //     else{
        //         swap(array[i],array[high]);
        //         high--;
        //     }
        // }
        
        sort(array.begin(),array.end());
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        
        vector<int> array(N);
        unordered_map<int,int> ump;
        
        for(int i=0;i<N;i++){
            cin>>array[i];
            ump[array[i]]++;
        }
        
        int a,b;
        cin>>a>>b;
        
        vector<int> original = array;

        int k1=0,k2=0,k3=0;
        int kk1=0;int kk2=0;int kk3=0;
        
        for(int i=0; i<N; i++)
        {
            if(original[i]>b)
                k3++;
            else if(original[i]<=b and original[i]>=a)
                k2++;
            else if(original[i]<b)
                k1++;
        }
        
        Solution ob;
        ob.threeWayPartition(array,a,b);
      
        for(int i=0;i<k1;i++)
        {
            if(array[i]<b)
            kk1++;
        }
        
        for(int i=k1;i<k1+k2;i++)
        {
            if(array[i]<=b and array[i]>=a)
            kk2++;
            
        }
        
        for(int i=k1+k2;i<k1+k2+k3;i++)
        {
            if(array[i]>b)
            kk3++;
        }
        bool ok = 0;
        if(k1==kk1 and k2 ==kk2 and k3 == kk3)
            ok = 1;
        
        for(int i=0;i<array.size();i++)
            ump[array[i]]--;
        
        for(int i=0;i<array.size();i++)
            if(ump[array[i]]!=0)
                ok=0;
        
        if(ok)
            cout<<1<<endl;
        else
            cout<<0<<endl;
        
    
cout << "~" << "\n";
}
    
    return 0;
}

// } Driver Code Ends
