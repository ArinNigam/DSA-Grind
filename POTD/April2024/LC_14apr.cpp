// Sum of Left Leaves (Easy)
// Given the root of a binary tree, return the sum of all left leaves.
// A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.

// Input: root = [3,9,20,null,null,15,7]
// Output: 24
// Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.

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
    
    int sumOfLeftLeaves(TreeNode* root) {
        queue<pair<int,TreeNode*>>q;
        q.push({0,root});
        int ans = 0;
        while(!q.empty()){
            auto it = q.front();
            int flag = it.first;
            TreeNode* node = it.second;
            q.pop();
            
            if ( flag && node->left==NULL && node->right==NULL){
                ans+=node->val;
            }
            
            if (node->left){
                q.push({1,node->left});
            }
            
            if (node->right){
                q.push({0,node->right});
            }
        }
        return ans;
        
    }
};
signed main()
{    
    string s;
    getline(cin,s,'\n');
    TreeNode* root = buildTree(s);
    Solution ob;
    auto ans = ob.sumOfLeftLeaves(root);
    cout<<ans;
    return 0;
}