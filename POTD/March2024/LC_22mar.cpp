// Palindrome Linked List (Medium)
// Given the head of a singly linked list, return true if it is a 
// palindrome or false otherwise.

// Input: head = [1,2,2,1]
// Output: true

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
    bool isPalindrome(ListNode* head){
       ListNode* slow = head;
       ListNode* fast = head;
       while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
       }
       slow->next = reverseList(slow->next);
       slow = slow->next;
       
       while(slow!=NULL){
        if (slow->val != head->val){
            return 0;
        }
        slow = slow->next;
        head = head->next;
       }
       return 1;
    }
};

signed main(){  
    int n;
    cin>>n;
    ListNode* nums = buildList(n);
    Solution ob;
    auto res = ob.isPalindrome(nums);
    cout<<res;
    return 0;
}