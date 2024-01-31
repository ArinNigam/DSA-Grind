// Evaluate Reverse Polish Notation (Medium)
// You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

// Evaluate the expression. Return an integer that represents the value of the expression.
// Example 1:

// Input: tokens = ["2","1","+","3","*"]
// Output: 9
// Explanation: ((2 + 1) * 3) = 9
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<long>st;
        long res;
        for(int i=0;i<n;i++){
            if (tokens[i].size()==1 && tokens[i][0]<48){
                long first =st.top();
                st.pop();
                long second = st.top();
                st.pop();
                if (tokens[i]=="+"){
                    res= second+first;
                }
                else if (tokens[i]=="-"){
                    res = second-first;
                }
                else if(tokens[i]=="*"){
                    res = second*first;
                }
                else{
                    res = second/first;
                }
                st.push(res);
            }
            else{
                st.push(stol(tokens[i]));
            }
        }
        return st.top();
    }
};
signed main()
{    
    int n;
    cin>>n;
    vector<string>nums(n);
    for (int i=0;i<n;i++){
        cin>>nums[i];
    }
    Solution ob;
    auto ans = ob.evalRPN(nums);
    cout<<ans;
    return 0;
}