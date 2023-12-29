// Unique Binary Search Trees II (Medium)
// Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.

// Example 1:

// Input: n = 3
// Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
// Example 2:

// Input: n = 1
// Output: [[1]]
 

// Constraints:
// 1 <= n <= 8

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
    if(!node){
        return;
    } 
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

void check(Node* node){
    if (node==NULL){
        cout<<"N";
    }
    else{
        cout<<node->data;
    }
}
//------------------------------------------------------------

class Solution {
private:
    vector<Node*> generate_trees(int start, int end){
        if (start > end) return {nullptr};

        vector<Node*> all_trees;
        for (int i=start;i<=end;i++){
            vector<Node*> left_trees = generate_trees(start,i-1);
            vector<Node*> right_trees = generate_trees(i+1,end);

            for (Node *L : left_trees){
                for (Node *R : right_trees){
                    Node* curr_tree = new Node(i);
                    curr_tree->left = L;
                    curr_tree->right = R;
                    all_trees.push_back(curr_tree);
                }
            }
        }
        return all_trees;
    }
public:
    vector<Node*> generateTrees(int n) {
        return n ? generate_trees(1,n) : vector<Node*>();
    }
};
signed main()
{    
    int n;
    cin>>n;
    Solution ob;
    auto ans = ob.generateTrees(n);
    for (auto i:ans){  
        check(i);
        check(i->left);
        check(i->right);
        cout<<endl;
    }
    return 0;
}