// Evaluate Boolean Binary Tree (Easy)
// Topic: Binary Tree
// Expected Time Complexity: O(n)
// Expected Space Complexity: O(1)
// Problem Statement: https://leetcode.com/problems/evaluate-boolean-expression/

// You are given the root of a full binary tree with the following properties:

// Leaf nodes have either the value 0 or 1, where 0 represents False and 1 represents True.
// Non-leaf nodes have either the value 2 or 3, where 2 represents the boolean OR and 3 represents the boolean AND.
// The evaluation of a node is as follows:

// If the node is a leaf node, the evaluation is the value of the node, i.e. True or False.
// Otherwise, evaluate the node's two children and apply the boolean operation of its value with the children's evaluations.
// Return the boolean result of evaluating the root node.

// A full binary tree is a binary tree where each node has either 0 or 2 children.

// A leaf node is a node that has zero children.

// Input: root = [2,1,3,null,null,0,1]
// Output: true
// Explanation: The above diagram illustrates the evaluation process.
// The AND node evaluates to False AND True = False.
// The OR node evaluates to True OR False = True.
// The root node evaluates to True, so we return true.

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
    bool solve(TreeNode *root)
    {
        if (root->val == 0 || root->val == 1)
        {
            return root->val == 1;
        }
        else if (root->val == 2)
        {
            return solve(root->left) || solve(root->right);
        }
        else if (root->val == 3)
        {
            return solve(root->left) && solve(root->right);
        }
        return false;
    }
    bool evaluateTree(TreeNode *root)
    {
        return solve(root);
    }
};

signed main()
{
    string s;
    getline(cin, s, '\n');
    TreeNode *root = buildTree(s);
    Solution ob;
    auto ans = ob.solve(root);
    cout << ans;
    return 0;
}