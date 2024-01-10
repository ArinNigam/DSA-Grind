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
    void adjList(TreeNode* root,unordered_map<int,vector<int>>&adj){
        if (!root){
            return;
        }
        if(root->left!=NULL){
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
        }
        if (root->right!=NULL){
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
        }
        adjList(root->left,adj);
        adjList(root->right,adj);
        
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,vector<int>>adj;
        adjList(root,adj);
        
        unordered_set<int> vis;
        
        queue<int> q;
        q.push(start);
        
        int time = -1;
        
        while(!q.empty()){
            time++;
            for (int lvl = q.size();lvl>0;lvl--){
                int curr = q.front();
                q.pop();
                vis.insert(curr);
                for (auto it: adj[curr]){
                    if (!vis.count(it)){
                        q.push(it);
                    }
                }
            }
        }
        
        return time;
    }
};
signed main()
{    
    string s;
    getline(cin,s,'\n');
    TreeNode* root = buildTree(s);
    Solution ob;
    int start;
    cin>>start;
    auto ans = ob.amountOfTime(root,start);
    cout<<ans;
    return 0;
}