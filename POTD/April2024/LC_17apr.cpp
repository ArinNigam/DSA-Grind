// Smallest String Starting From Leaf (Medium)

// You are given the root of a binary tree where each node has a value in the range [0, 25] representing the letters 'a' to 'z'.
// Return the lexicographically smallest string that starts at a leaf of this tree and ends at the root.

// Input: root = [25,1,3,1,3,0,2]
// Output: "adz"

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
    void dfs(TreeNode* node,string path,string &min){
        if (node==NULL){
            return;
        }
        
        path+= char('a' + node->val);
        
        if (!node->left && !node->right){
            reverse(path.begin(),path.end());
            if (min.empty() || path < min){
                min = path;
            }
            reverse(path.begin(),path.end());
        }
        dfs(node->left,path,min);
        dfs(node->right,path,min);
    }
    string smallestFromLeaf(TreeNode* root) {
        string min;
        dfs(root,"",min);
        return min;
    }
};

signed main()
{    
    string s;
    getline(cin,s,'\n');
    TreeNode* root = buildTree(s);
    Solution ob;
    auto ans = ob.smallestFromLeaf(root);
    cout<<ans;
    return 0;
}