//  Step-By-Step Directions From a Binary Tree Node to Another (Medium)

// Topic: Tree
// Expected Time Complexity: O(N)
// Expected Space Complexity: O(N)
// URL: https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/

//  You are given the root of a binary tree with n nodes. Each node is uniquely assigned a value from 1 to n. You are also given an integer startValue representing the value of the start node s, and a different integer destValue representing the value of the destination node t.
// Find the shortest path starting from node s and ending at node t. Generate step-by-step directions of such path as a string consisting of only the uppercase letters 'L', 'R', and 'U'. Each letter indicates a specific direction:
// 'L' means to go from a node to its left child node.
// 'R' means to go from a node to its right child node.
// 'U' means to go from a node to its parent node.
// Return the step-by-step directions of the shortest path from node s to node t.

// Input: root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
// Output: "UURL"
// Explanation: The shortest path is: 3 → 1 → 5 → 2 → 6.

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
    bool findPath(TreeNode *root, int value, string &ans)
    {
        if (root == NULL)
            return false;
        if (root->val == value)
            return true;

        ans.push_back('L');
        if (findPath(root->left, value, ans))
        {
            return true;
        }
        ans.pop_back();

        ans.push_back('R');
        if (findPath(root->right, value, ans))
        {
            return true;
        }
        ans.pop_back();

        return false;
    }
    TreeNode *LCA(TreeNode *root, int start, int end)
    {
        if (root == NULL)
            return NULL;
        if (root->val == start || root->val == end)
            return root;

        TreeNode *left = LCA(root->left, start, end);
        TreeNode *right = LCA(root->right, start, end);

        if (left == NULL)
        {
            return right;
        }
        if (right == NULL)
        {
            return left;
        }
        return root;
    }
    string getDirections(TreeNode *root, int startValue, int destValue)
    {
        string ans = "";
        TreeNode *lca = LCA(root, startValue, destValue);

        string temp = "";
        findPath(lca, startValue, temp);
        string x(temp.size(), 'U');
        ans += x;

        temp = "";
        findPath(lca, destValue, temp);
        ans += temp;
        return ans;
    }
};

signed main()
{

    string s;
    getline(cin, s, '\n');
    TreeNode *root = buildTree(s);
    int startValue, destValue;
    cin >> startValue >> destValue;
    Solution ob;
    auto ans = ob.getDirections(root, startValue, destValue);
    cout << ans;
    return 0;
}