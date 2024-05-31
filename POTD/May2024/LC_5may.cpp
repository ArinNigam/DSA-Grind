// Delete Node in a Linked List (Medium)
// Topic: Linked List
// Expected Time Complexity: O(1)
// Expected Space Complexity: O(1)
// Problem Statement: https://leetcode.com/problems/delete-node-in-a-linked-list/

// There is a singly-linked list head and we want to delete a node node in it.
// You are given the node to be deleted node. You will not be given access to the first node of head.
// All the values of the linked list are unique, and it is guaranteed that the given node node is not the last node in the linked list.
// Delete the given node. Note that by deleting the node, we do not mean removing it from memory. We mean:

// The value of the given node should not exist in the linked list.
// The number of nodes in the linked list should decrease by one.
// All the values before node should be in the same order.
// All the values after node should be in the same order.
// Custom testing:

// For the input, you should provide the entire linked list head and the node to be given node. node should not be the last node of the list and should be an actual node in the list.
// We will build the linked list and pass the node to your function.
// The output will be the entire list after calling your function.

// Input: head = [4,5,1,9], node = 5
// Output: [4,1,9]
// Explanation: You are given the second node with value 5, the linked list should become 4 -> 1 -> 9 after calling your function.

#include <bits/stdc++.h>
using namespace std;

//------------------------------------------------------------

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x)
    {
        val = x;
        next = NULL;
    }
};

struct ListNode *buildList(int size)
{
    int val;
    cin >> val;

    ListNode *head = new ListNode(val);
    ListNode *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new ListNode(val);
        tail = tail->next;
    }
    return head;
}

void printList(ListNode *n)
{
    while (n)
    {
        cout << n->val << " ";
        n = n->next;
    }
    cout << endl;
}

//------------------------------------------------------------

class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

signed main()
{
    int n;
    cin >> n;
    ListNode *nums = buildList(n);
    Solution ob;
    ob.deleteNode(nums);
    return 0;
}