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
    ListNode *findMid(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode *merge(ListNode *left, ListNode *right)
    {
        if (left == NULL)
        {
            return right;
        }
        if (right == NULL)
        {
            return right;
        }

        ListNode *ans = new ListNode(-1);
        ListNode *temp = ans;

        while (left != NULL && right != NULL)
        {

            if (left->val < right->val)
            {
                temp->next = left;
                temp = left;
                left = left->next;
            }
            else
            {

                temp->next = right;
                temp = right;
                right = right->next;
            }
        }

        while (left != NULL)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }

        while (right != NULL)
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }

        ans = ans->next;
        return ans;
    }

    ListNode *mergeSort(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *mid = findMid(head);
        ListNode *left = head;
        ListNode *right = mid->next;
        mid->next = NULL;

        left = mergeSort(left);
        right = mergeSort(right);

        ListNode *ans = merge(left, right);

        return ans;
    }

    ListNode *sorted = NULL;
    void sortedInsert(ListNode *node)
    {
        if (sorted == NULL || sorted->val >= node->val)
        {
            node->next = sorted;
            sorted = node;
        }
        else
        {
            ListNode *curr = sorted;
            while (curr->next != NULL && curr->next->val < node->val)
            {
                curr = curr->next;
            }
            node->next = curr->next;
            curr->next = node;
        }
    }
    ListNode *insertionSort(ListNode *head)
    {
        ListNode *curr = head;

        while (curr != NULL)
        {
            ListNode *next = curr->next;
            sortedInsert(curr);
            curr = next;
        }
        head = sorted;

        return sorted;
    }
};

signed main()
{
    int n;
    cin >> n;
    ListNode *nums = buildList(n);
    Solution ob;
    ListNode *res = ob.mergeSort(nums);
    ListNode *ans = ob.insertionSort(nums);
    printList(res);
    printList(ans);
    return 0;
}