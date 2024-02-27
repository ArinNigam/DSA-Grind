// Same Tree ( Given the roots of two binary trees p and q, write a function to check if they are the same or not.
// Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.)
// Input: p = [1,2,3], q = [1,2,3]
// Output: true
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p==NULL && q==NULL){
            return 1;
        }
        if (p==NULL || q==NULL){
            return 0;
        }
        return ((p->val == q->val) && isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
    }
};
signed main()
{    
    string s,t;
    getline(cin,s,'\n');
    getline(cin,t,'\n');
    TreeNode* root1 = buildTree(s);
    TreeNode* root2 = buildTree(t);
    Solution ob;
    auto ans = ob.isSameTree(root1,root2);
    cout<<ans;
    return 0;
}