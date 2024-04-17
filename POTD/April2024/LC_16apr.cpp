//Add One Row to Tree (Medium)

// Given the root of a binary tree and two integers val and depth, add a row of nodes with value val at the given depth depth.
//Note that the root node is at depth 1.

// Input: root = [4,2,null,3,1], val = 1, depth = 3
// Output: [4,2,null,1,1,3,null,null,1]

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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(!root){
            return root;
        }
        if (depth == 1){
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }
        queue<pair<int,TreeNode*>>q;
        q.push({1,root});

        while(!q.empty()){
            auto it = q.front();
            TreeNode* node = it.second;
            int dep = it.first;
            q.pop();
            if (dep == depth-1){
                TreeNode* temp1 = new TreeNode(val);
                TreeNode* temp2 = new TreeNode(val);
                temp1->left = node->left;
                temp2->right = node->right;
                node->left = temp1;
                node->right = temp2;
            }
            if (node->left){
                q.push({dep+1,node->left});
            }
            if (node->right){
                q.push({dep+1,node->right});
            } 
        }
        return root;
    }
};
signed main()
{    
    string s;
    getline(cin,s,'\n');
    TreeNode* root = buildTree(s);
    Solution ob;
    int val,depth;
    cin>>val>>depth;
    auto ans = ob.addOneRow(root,val,depth);
    printInorder(root);
    return 0;
}