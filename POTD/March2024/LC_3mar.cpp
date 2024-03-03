// Remove Nth Node From End of List (Medium)

// Given the head of a linked list, remove the nth node from the end of the list and return its head.
// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]

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

class Solution{
  public:
    ListNode* removeNthFromEnd(ListNode* head,int n){
       int cnt = 0;
       ListNode* curr = head;
       while(curr!=NULL){
        curr = curr->next;
        cnt++;
       }
       
       int k = cnt-n-1;
       curr = head;
       int i = 0;
       
       if (k==-1){
            head = head->next;
            delete curr;
            return head;
       }
       
       while(i<k){
            curr = curr->next;
            i++;
       }
       
       ListNode* temp = curr->next;
       curr->next = curr->next->next;
       delete temp;
       return head;
    }
};

signed main(){  
    int n,k;
    cin>>n>>k;
    ListNode* nums = buildList(n);
    Solution ob;
    ListNode* res = ob.removeNthFromEnd(nums,k);
    printList(res);
  return 0;
}