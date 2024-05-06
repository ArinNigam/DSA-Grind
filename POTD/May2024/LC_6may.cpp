//Remove Nodes From Linked List(Medium)

// You are given the head of a linked list.
// Remove every node which has a node with a greater value anywhere to the right side of it.
// Return the head of the modified linked list.

// Input: head = [5,2,13,3,8]
// Output: [13,8]
// Explanation: The nodes that should be removed are 5, 2 and 3.
// - Node 13 is to the right of node 5.
// - Node 13 is to the right of node 2.
// - Node 8 is to the right of node 3.
#include<bits/stdc++.h>
using namespace std;

//------------------------------------------------------------

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

struct ListNode* buildList(int size){
    int val;
    cin>>val;
    
    ListNode* head = new ListNode(val);
    ListNode* tail = head;
    
    for (int i=0;i<size-1;i++){
        cin>>val;
        tail->next = new ListNode(val);
        tail = tail->next;
    }
    return head;
}

void printList(ListNode *n){
    while(n){
        cout<<n->val<<" ";
        n = n->next;
    }
    cout<<endl;
}

//------------------------------------------------------------

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if (head==NULL){
            return NULL;
        }
        
        ListNode* node = head;
        ListNode* next = removeNodes(node->next);
        
        node->next = next;
        
        if (next==NULL || node->val >= next->val){
            return node;
        }
        
        return next;
    }
};

signed main(){  
    int n;
    cin>>n;
    ListNode* nums = buildList(n);
    Solution ob;
    ListNode* res = ob.removeNodes(nums);
    printList(res);   
    return 0;
}