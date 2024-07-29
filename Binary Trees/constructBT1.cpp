#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
 
// Data structure to store a binary tree node
struct Node
{
    int key;
    Node *left, *right;
 
    Node(int key)
    {
        this->key = key;
        this->left = this->right = nullptr;
    }
};
 
// Recursive function to perform inorder traversal on a given binary tree
void inorderTraversal(Node* root)
{
    if (root == nullptr) {
        return;
    }
 
    inorderTraversal(root->left);
    cout << root->key << ' ';
    inorderTraversal(root->right);
}
 
// Recursive function to perform postorder traversal on a given binary tree
void preorderTraversal(Node* root)
{
    if (root == nullptr) {
        return;
    }
 
    cout << root->key << ' ';
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
 
// Recursive function to construct a binary tree from a given
// inorder and preorder sequence
Node* construct(int start, int end, vector<int> const &preorder,
                int &pIndex, unordered_map<int, int> &map)
{
    // base case
    if (start > end) {
        return nullptr;
    }
 
    // The next element in `preorder[]` will be the root node of subtree
    // formed by sequence represented by `inorder[start, end]`
    Node *root = new Node(preorder[pIndex++]);
 
    // get the root node index in sequence `inorder[]` to determine the
    // left and right subtree boundary
    int index = map[root->key];
 
    // recursively construct the left subtree
    root->left = construct(start, index - 1, preorder, pIndex, map);
 
    // recursively construct the right subtree
    root->right = construct(index + 1, end, preorder, pIndex, map);
 
    // return current node
    return root;
}
 
// Construct a binary tree from inorder and preorder traversals.
// This function assumes that the input is valid
// i.e., given inorder and preorder sequence forms a binary tree
Node* construct(vector<int> const &inorder, vector<int> const &preorder)
{
    // get the total number of nodes in the tree
    int n = inorder.size();
 
    // create a map to efficiently find the index of any element in
    // a given inorder sequence
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++) {
        map[inorder[i]] = i;
    }
 
    // `pIndex` stores the index of the next unprocessed node in preorder;
    // start with the root node (present at 0th index)
    int pIndex = 0;
 
    return construct(0, n - 1, preorder, pIndex, map);
}
 
int main()
{
    /* Construct the following tree
               1
             /   \
            /     \
           2       3
          /       / \
         /       /   \
        4       5     6
               / \
              /   \
             7     8
    */
 
    vector<int> inorder = { 4, 2, 1, 7, 5, 8, 3, 6 };
    vector<int> preorder = { 1, 2, 4, 3, 5, 7, 8, 6 };
 
    Node* root = construct(inorder, preorder);
 
    // traverse the constructed tree
    cout << "The inorder traversal is "; inorderTraversal(root);
    cout << "\nThe preorder traversal is "; preorderTraversal(root);
    cout << "\nThe Postorder traversal is ";postorderTraversal(root);
    return 0;
}