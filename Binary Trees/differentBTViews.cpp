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

class Solution{
public:
    vector<int> leftView(TreeNode *root){
        vector<int> ans;
        if (root==NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            int i=0;
            while(i<size){
                auto it = q.front();
                q.pop();
                auto left = it->left;
                auto right = it->right;
                if (left!=NULL){
                    q.push(left);
                }
                if (right!=NULL){
                    q.push(right);
                }
                if (i==0){
                    ans.push_back(it->val);
                }
                i++;
            }
        }
        return ans;
    }
    vector<int> rightView(TreeNode *root){
        vector<int> ans;
        if (root==NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int i=0;
            int size = q.size();
            while(i<size){
                auto it = q.front();
                q.pop();
                auto left = it->left;
                auto right = it->right;
                if (left!=NULL){
                    q.push(left);
                }
                if (right!=NULL){
                    q.push(right);
                }
                if (i==size-1){
                    ans.push_back(it->val);
                }
                i++;
            }
        }
        return ans;
    }
    vector<int> bottomView(TreeNode *root){
        vector<int> ans;
        if (root==NULL) return ans;
        queue<pair<TreeNode*,int>>q;
        map<int,int>mp;
        q.push({root,0});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            TreeNode* node = it.first;
            int verticalLvl = it.second;
            mp[verticalLvl] = node->val;
            if (node->left!=NULL){
                q.push({node->left,verticalLvl-1});
            }
            if (node->right!=NULL){
                q.push({node->right,verticalLvl+1});
            }
        }
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
    vector<int> topView(TreeNode* root){
        vector<int> ans;
        if (root==NULL) return ans;
        queue<pair<TreeNode*,int>>q;
        map<int,vector<int>>mp;
        q.push({root,0});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            TreeNode* node = it.first;
            int verticalLvl = it.second;\
            mp[verticalLvl].push_back(node->val);
            if (node->left!=NULL){
                q.push({node->left,verticalLvl-1});
            }
            if (node->right!=NULL){
                q.push({node->right,verticalLvl+1});
            }
        }
        for(auto it:mp){
            ans.push_back(it.second[0]);
        }
        return ans;
    }
};
signed main()
{   
    // INPUT
    // 1 2 3 4 5 6 7 N N 8 N 9 10 N N 11 N N N N N
    // OUTPUT
    // 1 2 4 8 11 
    // 1 3 7 10 11 
    // 11 9 6 10 7 
    // 4 2 1 3 7
    string s;
    getline(cin,s,'\n');
    TreeNode* root = buildTree(s);
    Solution ob;
    auto leftViewAns = ob.leftView(root);
    for(auto it:leftViewAns){
        cout<<it<<" ";
    }
    cout<<endl;
    auto rightViewAns = ob.rightView(root);
    for(auto it:rightViewAns){
        cout<<it<<" ";
    }
    cout<<endl;
    auto bottomViewAns = ob.bottomView(root);
    for(auto it:bottomViewAns){
        cout<<it<<" ";
    }
    cout<<endl;
    auto topViewAns = ob.topView(root);
    for(auto it:topViewAns){
        cout<<it<<" ";
    }
    return 0;
}