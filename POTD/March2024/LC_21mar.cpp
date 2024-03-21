// Reverse Linked List (Easy)
// Given the head of a singly linked list, reverse the list, and return the reversed list.

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
    ListNode* reverseList(ListNode* head){
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
};

signed main(){  
    int n;
    cin>>n;
    ListNode* nums = buildList(n);
    Solution ob;
    ListNode* res = ob.reverseList(nums);
    printList(res);   
    return 0;
}