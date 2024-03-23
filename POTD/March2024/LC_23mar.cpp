// Reorder List (Medium)

// You are given the head of a singly linked-list. The list can be represented as:
// L0 -> L1 -> L2 ->. . .  Ln
// Reorder the list to be on the following form:
// L0 -> Ln -> L1 -> Ln-1
// You may not modify the values in the list's nodes. Only nodes themselves may be changed.

// Input: head = [1,2,3,4,5]
// Output: [1,5,2,4,3]

#include<bits/stdc++.h>
using namespace std;

//------------------------------------------------------------

struct ListNode {
    int data;
    struct ListNode* next;
    ListNode(int x) {
        data = x;
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
        cout<<n->data<<" ";
        n = n->next;
    }
    cout<<endl;
}

//------------------------------------------------------------

class Solution{
  public:
    ListNode* reverse(ListNode* head){
        if (head==NULL) return NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr!=NULL){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if (head==NULL || head->next==NULL) return;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = head;
        while(fast!=NULL && fast->next!=NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        ListNode* x = head;
        ListNode* y = reverse(slow);
        while(y!=NULL){
            ListNode* temp = x->next;
            x->next = y;
            x = y;
            y = temp;
        }

       printList(head);  
    }
      
};

signed main(){  
    int n;
    cin>>n;
    ListNode* nums = buildList(n);
    Solution ob;
    ob.reorderList(nums);
     
    return 0;
}