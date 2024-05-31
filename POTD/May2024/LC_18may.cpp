// Distribute Coins in Binary Tree (Medium)
// Topic: Binary Tree
// Expected Time Complexity: O(n)
// Expected Space Complexity: O(h)
// Problem Statement: https://leetcode.com/problems/distribute-coins-in-binary-tree/

// You are given the root of a binary tree with n nodes where each node in the tree has node.val coins. There are n coins in total throughout the whole tree.
// In one move, we may choose two adjacent nodes and move one coin from one node to another. A move may be from parent to child, or from child to parent.
// Return the minimum number of moves required to make every node have exactly one coin.

// Input: root = [3,0,0]
// Output: 2
// Explanation: From the root of the tree, we move one coin to its left child, and one coin to its right child.

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
    int distributeCoins(TreeNode *root)
    {
        deque<pair<TreeNode *, pair<TreeNode *, int>>> dq;
        dq.push_back({root, {NULL, 0}});
        int cnt = 0;
        while (!dq.empty())
        {
            auto it = dq.back();
            TreeNode *node = it.first;
            TreeNode *par = it.second.first;
            int vis = it.second.second;
            dq.pop_back();
            if (!vis)
            {
                dq.push_back({node, {par, 1}});
                if (node->right)
                {
                    dq.push_back({node->right, {node, 0}});
                }
                if (node->left)
                {
                    dq.push_back({node->left, {node, 0}});
                }
            }
            else
            {
                int x = node->val - 1;
                if (par)
                {
                    par->val += x;
                }
                cnt += abs(x);
            }
        }
        return cnt;
    }
};

signed main()
{
    string s;
    getline(cin, s, '\n');
    TreeNode *root = buildTree(s);
    Solution ob;
    auto ans = ob.distributeCoins(root);
    cout << ans;
    return 0;
}