// Balance a Binary Search Tree (Medium)

// Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.
// A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.

// Input: root = [1,null,2,null,3,null,4,null,null]
// Output: [2,1,3,null,null,null,4]
// Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.

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
    TreeNode(int x, TreeNode *left, TreeNode *right){
        val = x;
        left = left;
        right = right;
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
    vector<int>ans;
    void inorderTrav(TreeNode* root){
        if (root==NULL) return;
        inorderTrav(root->left);
        ans.push_back(root->val);
        inorderTrav(root->right);
        
    }
    TreeNode* balance(int l,int r){
        if (l>r) return NULL;
        int mid = (l+r)/2;
        TreeNode* left = (l > mid + 1) ? NULL : balance(l,mid-1);
        TreeNode* right = (mid + 1 > r) ? NULL : balance(mid+1,r);
        return new TreeNode(ans[mid],left,right);
    }
    TreeNode* balanceBST(TreeNode* root) {
        inorderTrav(root);
        sort(ans.begin(),ans.end());
        return balance(0,ans.size()-1);
    }
};
signed main()
{    
    string s;
    getline(cin,s,'\n');
    TreeNode* root = buildTree(s);
    Solution ob;
    auto ans = ob.balanceBST(root);
    printInorder(root);
    return 0;
}