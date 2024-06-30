// Nodes at given distance in binary tree
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

    vector<int>ans;
    
    void calc(map<Node*, Node*>& mp, Node* root, Node* prev, Node* &dest, int k)
    {
        if(!root) return;
        
        mp[root] = prev;
        if(root->data == k && !dest) dest = root;
        
        calc(mp, root->left, root, dest, k);
        calc(mp, root->right, root, dest, k);
    }
    
    void solve(int k, map<Node*, Node*>& mp, Node* root, Node* prev)
    {
        if(!root) return;
        if(k == 0) 
        {
            ans.push_back(root->data);
            return;
        }
        
        if(root->left != prev) solve(k-1, mp, root->left, root);
        if(root->right != prev) solve(k-1, mp, root->right, root);
        if(mp[root] != prev) solve(k-1, mp, mp[root], root);
    }

    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        ans.clear();
        map<Node* , Node*>mp;
        
        Node* dest = NULL;
        calc(mp, root, NULL, dest, target);
        // cout<<dest->data<<endl;
        solve(k, mp, dest, NULL);
        
        sort(ans.begin(), ans.end());
        return ans;
    }

};
signed main()
{    
    string s;
    getline(cin,s,'\n');
    Node* root = buildTree(s);
    Solution ob;
    int target,k;
    cin>>target>>k;
    auto ans = ob.KDistanceNodes(root,target,k);
    return 0;
}