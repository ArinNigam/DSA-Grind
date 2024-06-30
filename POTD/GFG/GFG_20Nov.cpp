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
    const int mod = 1e9 + 7;
    int func(Node *root, map <int, int>&mp, int k, int sum)
    {
        if(root == NULL) return 0;
        int ans = 0;
        if(mp.find(sum + root->data - k) != mp.end()) ans += mp[sum + root->data - k] % mod;
        mp[sum + root->data]++;
        ans += (func(root->left, mp, k, sum + root->data) % mod + func(root->right, mp, k, sum + root->data) % mod) % mod;
        mp[sum + root->data]--;
        return ans % mod;
    }
    int sumK(Node *root,int k)
    {
        // code here 
        map <int, int> mp;
        mp[0] = 1;
        return func(root, mp, k, 0);
    }
};
signed main()
{    
    string s;
    getline(cin,s,'\n');
    Node* root = buildTree(s);
    Solution ob;
    auto ans = ob.solve(root);
    cout<<ans;
    return 0;
}