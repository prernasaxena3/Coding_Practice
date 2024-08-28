//Parenthesis Checker

/*Given an expression string x. Examine whether the pairs and the orders of {,},(,),[,] are correct in exp.
For example, the function should return 'true' for exp = [()]{}{[()()]()} and 'false' for exp = [(]).

Note: The drive code prints "balanced" if function return true, otherwise it prints "not balanced".*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char>s;
        for(char ch : x){
            if(ch == '{' || ch == '[' || ch == '('){
                s.push(ch);
            }else{
                if(s.empty()) return false;
                if((ch == ')' && s.top() == '(') || (ch == '}' && s.top() == '{') || (ch == ']' && s.top() == '[')){
                    s.pop();
                }else{
                    return false;
                }
            }
            
        }
        
        return s.empty();
    }
    

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends
