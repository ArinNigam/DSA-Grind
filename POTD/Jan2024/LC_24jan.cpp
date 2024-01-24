// Pseudo-Palindromic Paths in a Binary Tree (Medium)
// Given a binary tree where node values are digits from 1 to 9. A path in the binary tree is said to be pseudo-palindromic if at least one permutation of the node values in the path is a palindrome.
// Return the number of pseudo-palindromic paths going from the root node to leaf nodes.

// Input: root = [2,3,1,3,1,null,1]
// Output: 2 
// Explanation: The figure above represents the given binary tree. There are three paths going from the root node to leaf nodes: the red path [2,3,3], the green path [2,1,1], and the path [2,3,1]. 
// Among these paths only red path and green path are pseudo-palindromic paths since the red path [2,3,3] can be rearranged in [3,2,3] (palindrome) and the green path [2,1,1] can be rearranged in [1,2,1] (palindrome).

// HINT: DFS and At most one digit should have an odd frequency.
// Use bitwise operations to efficiently handle digit occurrences.

#include<bits/stdc++.h>
using namespace std;
//------------------------------------------------------------
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

void printInorder(TreeNode* node){
    if(!node) return;
    printInorder(node->left);
    cout<<node->val<<" ";
    printInorder(node->right);
}

struct TreeNode* buildTree(string str){
    if (str.length()==0 || str[0]=='N'){
        return NULL;
    }
    vector<string>ip;
    
    istringstream iss(str);
    for (string str;iss>>str;){
        ip.push_back(str);
    }
    TreeNode* root = new TreeNode(stoi(ip[0]));
    
    queue<TreeNode*>q;
    q.push(root);
    int i = 1;
    while(!q.empty() && i<ip.size()){
        TreeNode* currNode = q.front();
        q.pop();
        
        string currVal = ip[i];
        
        if (currVal !="N"){
            currNode->left = new TreeNode(stoi(currVal));
            
            q.push(currNode->left);
        }
        i++;
        if (i>=ip.size()){
            break;
        }
        currVal = ip[i];
        if (currVal !="N"){
            currNode->right = new TreeNode(stoi(currVal));
            q.push(currNode->right);
        }
        i++;
    }
    return root;
}
//------------------------------------------------------------



class Solution {
public:
    int pseudoPalindromicPaths(TreeNode* root) {
        int count = 0;

        stack<pair<TreeNode*, int>> st;
        st.push({root, 0});

        while (!st.empty()) {
            auto it = st.top();
            TreeNode* node = it.first;
            int path = it.second;
            st.pop();

            if (node != nullptr) {
                
                path = path ^ (1 << node->val);

                
                if (node->left == nullptr && node->right == nullptr) {
                    
                    if ((path & (path - 1)) == 0) {
                        ++count;
                    }
                } else {
                    st.push({node->left, path});
                    st.push({node->right, path});
                }
            }
        }

        return count;
    }
};




signed main()
{    
    string s;
    getline(cin,s,'\n');
    TreeNode* root = buildTree(s);
    Solution ob;
    auto ans = ob.pseudoPalindromicPaths(root);
    cout<<ans;
    return 0;
}