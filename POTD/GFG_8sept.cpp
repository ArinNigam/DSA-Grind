// Convert a tree to a binary search tree
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

class Solution{
  public:
    void inorder(Node* root,vector<int>&in){
        if (root==NULL) return;
        inorder(root->left,in);
        in.push_back(root->data);
        inorder(root->right,in);
        
    }
    Node* convert(vector<int>&in, int low,int high){
        if (low > high) return NULL;
        int mid = low + (high - low)/2;
        Node* root = new Node(in[mid]);
        root->left = convert(in,low,mid-1);
        root->right = convert(in,mid+1,high);
        return root;
    }
    Node *binaryTreeToBST (Node *root)
    {
        vector<int>in;
        inorder(root,in);
        sort(in.begin(),in.end());
        return convert(in,0,in.size()-1);
    }
};
signed main()
{    
    string s;
    getline(cin,s,'\n');
    Node* root = buildTree(s);
    Solution ob;
    auto ans = ob.binaryTreeToBST(root);
    cout<<ans;
    return 0;
}