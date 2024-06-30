// Isomorphic Trees
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
    // Return True if the given trees are isomotphic. Else return False.
    bool solve(Node* root1,Node* root2){
        if (root1==NULL && root2==NULL){
            return true;
        }
        if (root1==NULL || root2==NULL){
            return false;
        }
        if (root1->data != root2->data){
            return false;
        }
        
        bool case1 = solve(root1->left,root2->left) && solve(root1->right,root2->right);
        bool case2 = solve(root1->left,root2->right) && solve(root1->right,root2->left);
        return case1 || case2;
    }
    bool isIsomorphic(Node *root1,Node *root2)
    {
    //add code here.
        return solve(root1,root2);
        
    }
};
signed main()
{    
    string s1,s2;
    getline(cin,s1,'\n');
    getline(cin,s2,'\n');
    Node* root1 = buildTree(s1);
    Node* root2 = buildTree(s2);
    Solution ob;
    auto ans = ob.isIsomorphic(root1,root2);
    cout<<ans;
    return 0;
}