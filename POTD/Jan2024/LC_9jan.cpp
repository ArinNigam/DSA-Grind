// Leaf-Similar Trees (Easy)
// Return true if the leaves of tree1 == tree2

#include<bits/stdc++.h>
using namespace std;
//------------------------------------------------------------
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printInorder(TreeNode* Treenode){
    if(!Treenode) return;
    printInorder(Treenode->left);
    cout<<Treenode->data<<" ";
    printInorder(Treenode->right);
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
        TreeNode* currTreeNode = q.front();
        q.pop();
        
        string currVal = ip[i];
        
        if (currVal !="N"){
            currTreeNode->left = new TreeNode(stoi(currVal));
            
            q.push(currTreeNode->left);
        }
        i++;
        if (i>=ip.size()){
            break;
        }
        currVal = ip[i];
        if (currVal !="N"){
            currTreeNode->right = new TreeNode(stoi(currVal));
            q.push(currTreeNode->right);
        }
        i++;
    }
    return root;
}
//------------------------------------------------------------
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void leafNodes(TreeNode* root,vector<int>&ans){
        if (!root){
            return;
        }
        if (!root->left && !root->right){
            ans.push_back(root->data);
            return;
        }
        leafNodes(root->left,ans);
        leafNodes(root->right,ans);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>v1,v2;
        leafNodes(root1,v1);
        leafNodes(root2,v2);
        return v1==v2;
    }
};
signed main()
{    
    string s;
    getline(cin,s,'\n');
    TreeNode* root1 = buildTree(s);
    TreeNode* root2 = buildTree(s);
    Solution ob;
    auto ans = ob.leafSimilar(root1,root2);
    cout<<ans;
    return 0;
}