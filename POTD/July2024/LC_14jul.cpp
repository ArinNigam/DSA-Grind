 // Number of Atoms (Hard)

// Given a string formula representing a chemical formula, return the count of each atom.

// The atomic element always starts with an uppercase character, then zero or more lowercase letters, representing the name.

// One or more digits representing that element's count may follow if the count is greater than 1. If the count is 1, no digits will follow.

// For example, "H2O" and "H2O2" are possible, but "H1O2" is impossible.
// Two formulas are concatenated together to produce another formula.

// For example, "H2O2He3Mg4" is also a formula.
// A formula placed in parentheses, and a count (optionally added) is also a formula.

// For example, "(H2O2)" and "(H2O2)3" are formulas.
// Return the count of all elements as a string in the following form: the first name (in sorted order), followed by its count (if that count is more than 1), followed by the second name (in sorted order), followed by its count (if that count is more than 1), and so on.

// The test cases are generated so that all the values in the output fit in a 32-bit integer.

// Input: formula = "H2O"
// Output: "H2O"
// Explanation: The count of elements are {'H': 2, 'O': 1}.

// Input: formula = "K4(ON(SO3)2)2"
// Output: "K4N2O14S4"
// Explanation: The count of elements are {'K': 4, 'N': 2, 'O': 14, 'S': 4}.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string countOfAtoms(string s) {
        stack<unordered_map<string, int>> st;
        st.push({}); 
        
        int i = 0, n = s.length();
        
        while (i < n) {
            if (s[i] == '(') {
                st.push({});
                i++;
            } else if (s[i] == ')') {
                unordered_map<string, int> top = st.top();
                st.pop();
                i++;
                int start = i;
                while (i < n && isdigit(s[i])) {
                    i++;
                }
                int multiplier = start < i ? stoi(s.substr(start, i - start)) : 1;
                for (auto& kv : top) {
                    st.top()[kv.first] += kv.second * multiplier;
                }
            } else {
                int start = i++;
                while (i < n && islower(s[i])) {
                    i++;
                }
                string element = s.substr(start, i - start);
                start = i;
                while (i < n && isdigit(s[i])) {
                    i++;
                }
                int count = start < i ? stoi(s.substr(start, i - start)) : 1;
                st.top()[element] += count;
            }
        }
        
        unordered_map<string, int> result = st.top();
        vector<string> elements;
        for (auto kv : result) {
            elements.push_back(kv.first);
        }
        sort(elements.begin(), elements.end());
        
        string res;
        for (const auto element : elements) {
            res += element;
            if (result[element] > 1) {
                res += to_string(result[element]);
            }
        }
        
        return res;
    }
};

signed main()
{    
    string s;
    cin>>s;
    Solution ob;
    auto ans = ob.countOfAtoms(s);
    cout<<ans;
    return 0;
}