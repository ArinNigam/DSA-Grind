// Number of Good Leaf Nodes Pairs( Medium)

// Topic: Tree
// Expected Time Complexity: O(N)
// Expected Space Complexity: O(N)
// URL: https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/

// You are given the root of a binary tree and an integer distance. A pair of two different leaf nodes of a binary tree is said to be good if the length of the shortest path between them is less than or equal to distance.
// Return the number of good leaf node pairs in the tree.

// Input: root = [1,2,3,4,5,6,7], distance = 3
// Output: 2
// Explanation: The good pairs are [4,5] and [6,7] with shortest path = 2. The pair [4,6] is not good because the length of ther shortest path between them is 4.

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
    vector<int> dfs(TreeNode *node, int distance, int &cnt)
    {
        if (node == NULL)
            return {};
        if (node->left == NULL && node->right == NULL)
            return {1};

        vector<int> left = dfs(node->left, distance, cnt);
        vector<int> right = dfs(node->right, distance, cnt);

        for (auto x : left)
        {
            for (auto y : right)
            {
                if (x + y <= distance)
                {
                    cnt++;
                }
            }
        }

        vector<int> ans;
        for (auto x : left)
        {
            if (x < distance)
            {
                ans.push_back(x + 1);
            }
        }
        for (auto y : right)
        {
            if (y < distance)
            {
                ans.push_back(y + 1);
            }
        }
        return ans;
    }
    int countPairs(TreeNode *root, int distance)
    {
        int cnt = 0;
        dfs(root, distance, cnt);
        return cnt;
    }
};

signed main()
{
    string s;
    getline(cin, s, '\n');
    TreeNode *root = buildTree(s);
    int distance;
    cin >> distance;
    Solution ob;
    auto ans = ob.countPairs(root, distance);
    cout << ans;
    return 0;
}