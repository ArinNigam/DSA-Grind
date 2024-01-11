// Maximum Difference Between Node and Ancestor (Medium)

// Input: root = [8,3,10,1,6,null,14,null,null,4,7,13]
// Output: 7
// Explanation: We have various ancestor-node differences, some of which are given below :
// |8 - 3| = 5
// |3 - 7| = 4
// |8 - 1| = 7
// |10 - 13| = 3
// Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.

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
    int maxAncestorDiff(TreeNode* root) {
        if (!root)
            return 0;
        int minVal = root->val, maxVal = root->val;
        differ(root, minVal, maxVal);
        return diff;
    }

private:
    int diff = 0;

    void differ(TreeNode* root, int minVal, int maxVal) {
        if (!root)
            return;
        diff = max(diff, max(abs(minVal - root->val), abs(maxVal - root->val)));
        minVal = min(minVal, root->val);
        maxVal = max(maxVal, root->val);
        differ(root->left, minVal, maxVal);
        differ(root->right, minVal, maxVal);
    }
};
signed main()
{    
    string s;
    getline(cin,s,'\n');
    TreeNode* root = buildTree(s);
    Solution ob;
    auto ans = ob.maxAncestorDiff(root);
    cout<<ans;
    return 0;
}