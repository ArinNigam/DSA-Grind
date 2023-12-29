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
    int matching = 0;
    pair<int,int> postOrder(Node* root){
        if (root==nullptr) return {0,0}; 
        auto l_sum = postOrder(root->left);
        auto r_sum = postOrder(root->right);
        int sum = root->data + l_sum.first + r_sum.first;
        int count = 1 + l_sum.second + r_sum.second;
        if (count!=0 && sum/count == root->data){
            matching++;
        }
        return {sum,count};

    }
    int averageOfSubtree(Node* root) {
        postOrder(root);
        return matching;
    }
};
signed main()
{    
    string s;
    getline(cin,s,'\n');
    Node* root = buildTree(s);
    Solution ob;
    auto ans = ob.averageOfSubtree(root);
    cout<<ans;
    return 0;
}