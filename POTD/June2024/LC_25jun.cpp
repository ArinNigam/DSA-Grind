// Binary Search Tree to Greater Sum Tree (Medium)
// Topic: Trees
// Expected Time Complexcity: O(N)
// Expected Space Complexity: O(N)
// Problem Statement: https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/

// Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus the sum of all keys greater than the original key in BST.
// As a reminder, a binary search tree is a tree that satisfies these constraints:
// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.

// Input: root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
// Output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
#include <bits/stdc++.h>
using namespace std;
//------------------------------------------------------------
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

void printInorder(TreeNode *node)
{
    if (!node)
        return;
    printInorder(node->left);
    cout << node->val << " ";
    printInorder(node->right);
}

struct TreeNode *buildTree(string str)
{
    if (str.length() == 0 || str[0] == 'N')
    {
        return NULL;
    }
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
    {
        ip.push_back(str);
    }
    TreeNode *root = new TreeNode(stoi(ip[0]));

    queue<TreeNode *> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < ip.size())
    {
        TreeNode *currNode = q.front();
        q.pop();

        string currVal = ip[i];

        if (currVal != "N")
        {
            currNode->left = new TreeNode(stoi(currVal));

            q.push(currNode->left);
        }
        i++;
        if (i >= ip.size())
        {
            break;
        }
        currVal = ip[i];
        if (currVal != "N")
        {
            currNode->right = new TreeNode(stoi(currVal));
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
    int sum = 0;
    TreeNode *bstToGst(TreeNode *root)
    {
        if (root == NULL)
            return NULL;
        bstToGst(root->right);
        sum += root->val;
        root->val = sum;
        bstToGst(root->left);
    }
};

signed main()
{
    string s;
    getline(cin, s, '\n');
    TreeNode *root = buildTree(s);
    Solution ob;
    auto ans = ob.bstToGst(root);
    printInorder(root);
    return 0;
}