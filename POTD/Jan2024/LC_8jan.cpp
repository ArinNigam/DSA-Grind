// Range Sum of BST (easy)
// Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a value in the inclusive range [low, high].

// Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
// Output: 32
// Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 = 32.

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

void printInorder(TreeNode* TreeNode){
    if(!TreeNode) return;
    printInorder(TreeNode->left);
    cout<<TreeNode->val<<" ";
    printInorder(TreeNode->right);
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

class Solution
{
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root==NULL){
            return 0;
        }
        
        if( low<= root->val && high>= root->val){
            return root->val + rangeSumBST(root->left,low,high) + rangeSumBST(root->right,low,high);
        }
        else if (root->val < low){
            return rangeSumBST(root->right,low,high);
        }
        else{
            return rangeSumBST(root->left,low,high);
        }
    }
};
signed main()
{    
    string s;
    getline(cin,s,'\n');
    TreeNode* root = buildTree(s);
    int low,high;
    cin>>low>>high;
    Solution ob;
    auto ans = ob.rangeSumBST(root,low,high);
    cout<<ans;
    return 0;
}