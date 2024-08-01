 // Create Binary Tree From Descriptions (Medium)
 
// Topic: Tree
// Expected Time Complexity: O(N)
// Expected Space Complexity: O(N)
// URL: https://leetcode.com/problems/create-binary-tree-from-descriptions/

// You are given a 2D integer array descriptions where descriptions[i] = [parenti, childi, isLefti] indicates that parenti is the parent of childi in a binary tree of unique values. Furthermore,

// If isLefti == 1, then childi is the left child of parenti.
// If isLefti == 0, then childi is the right child of parenti.
// Construct the binary tree described by descriptions and return its root.

// The test cases will be generated such that the binary tree is valid

// Input: descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
// Output: [50,20,80,15,17,19]
// Explanation: The root node is the node with value 50 since it has no parent.
// The resulting binary tree is shown in the diagram.

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
    if (str.length()==0 || str[0]=='null'){
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
        
        if (currVal !="null"){
            currNode->left = new TreeNode(stoi(currVal));
            
            q.push(currNode->left);
        }
        i++;
        if (i>=ip.size()){
            break;
        }
        currVal = ip[i];
        if (currVal !="null"){
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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int n = descriptions.size();
        
        unordered_map<int,TreeNode*>adj;
        unordered_set<int>hasParent;
        
        for(auto it:descriptions){
            if (adj.find(it[0])==adj.end()){
                adj[it[0]] = new TreeNode(it[0]);
            }
            if (adj.find(it[1])==adj.end()){
                adj[it[1]] = new TreeNode(it[1]);
            }
            hasParent.insert(it[1]);
        }
        TreeNode* root;
        
        for(auto it:descriptions){
            if (it[2]){
                adj[it[0]] -> left = adj[it[1]];
            }
            else{
                adj[it[0]] -> right = adj[it[1]];
            }
            if (hasParent.find(it[0])==hasParent.end()){
                root = adj[it[0]];
            }
        }
        return root;
    }
};
signed main()
{    
    int n;
    cin>>n;
    vector<vector<int>>des(n,vector<int>(3));
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>des[i][j];
        }
    }
    Solution ob;
    auto ans = ob.createBinaryTree(des);
    printInorder(ans);
    return 0;
}