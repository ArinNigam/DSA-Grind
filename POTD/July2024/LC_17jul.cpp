// Delete Nodes And Return Forest (Medium)

// Topic: Tree
// Expected Time Complexity: O(N)
// Expected Space Complexity: O(N)
// URL: https://leetcode.com/problems/delete-nodes-and-return-forest/

// Given the root of a binary tree, each node in the tree has a distinct value.

// After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).

// Return the roots of the trees in the remaining forest. You may return the result in any order.

// Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
// Output: [[1,2,null,4],[6],[7]]

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
    vector<TreeNode *> ans;
    TreeNode *deleteNode(TreeNode *root, unordered_set<int> &st)
    {
        if (root == NULL)
            return NULL;
        root->left = deleteNode(root->left, st);
        root->right = deleteNode(root->right, st);
        if (st.find(root->val) != st.end())
        {
            if (root->left)
            {
                ans.push_back(root->left);
            }
            if (root->right)
            {
                ans.push_back(root->right);
            }
            delete (root);
            return NULL;
        }
        return root;
    }
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
    {
        unordered_set<int> st(to_delete.begin(), to_delete.end());
        TreeNode *x = deleteNode(root, st);
        if (x)
        {
            ans.push_back(x);
        }
        return ans;
    }
};

signed main()
{
    string s;
    getline(cin, s, '\n');
    TreeNode *root = buildTree(s);
    Solution ob;
    int m;
    cin >> m;
    vector<int> to_delete(m);
    for (int i = 0; i < m; i++)
    {
        cin >> to_delete[i];
    }
    auto ans = ob.delNodes(root, to_delete);
    for (auto it : ans)
    {
        printInorder(it);
        cout << endl;
    }
    return 0;
}