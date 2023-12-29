//Leaf under budget
// Leaf Nodes + knapsack
#include<bits/stdc++.h>
using namespace std;
//------------------------------------------------------------
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printInorder(Node* node){
    if(!node) return;
    printInorder(node->left);
    cout<<node->data<<" ";
    printInorder(node->right);
}

struct Node* buildTree(string str){
    if (str.length()==0 || str[0]=='N'){
        return NULL;
    }
    vector<string>ip;
    
    istringstream iss(str);
    for (string str;iss>>str;){
        ip.push_back(str);
    }
    Node* root = new Node(stoi(ip[0]));
    
    queue<Node*>q;
    q.push(root);
    int i = 1;
    while(!q.empty() && i<ip.size()){
        Node* currNode = q.front();
        q.pop();
        
        string currVal = ip[i];
        
        if (currVal !="N"){
            currNode->left = new Node(stoi(currVal));
            
            q.push(currNode->left);
        }
        i++;
        if (i>=ip.size()){
            break;
        }
        currVal = ip[i];
        if (currVal !="N"){
            currNode->right = new Node(stoi(currVal));
            q.push(currNode->right);
        }
        i++;
    }
    return root;
}
//------------------------------------------------------------

class Solution
{
public:
    void solve(Node* root,vector<pair<Node*,int>>&ans,int lvl){
        if (root==NULL) return;
        if (root->left == NULL && root->right==NULL){
            ans.push_back({root,lvl});
            return;
        }
        solve(root->left,ans,lvl+1);
        solve(root->right,ans,lvl+1);
        return;
    }
    static bool cmp(pair<Node*,int>&p1,pair<Node*,int>&p2){
        return p1.second < p2.second;
    }
    int getCount(Node *root, int k)
    {
        vector<pair<Node*,int>>ans;
        solve(root,ans,1);
        sort(ans.begin(),ans.end(),cmp);
        int cnt = 0;
        int cost = 0;
        for (auto i: ans){
            if (cost + i.second <=k){
                cost+=i.second;
                cnt++;
            }
        }
        return cnt;
    }
};
signed main()
{    
    string s;
    getline(cin,s,'\n');
    Node* root = buildTree(s);
    int k;
    cin>>k;
    Solution ob;
    auto ans = ob.getCount(root,k);
    cout<<ans;
    return 0;
}