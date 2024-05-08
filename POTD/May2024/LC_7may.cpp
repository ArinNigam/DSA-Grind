// Double a Number Represented as a Linked List (Medium)
// You are given the head of a non-empty linked list representing a non-negative integer without leading zeroes.
// Return the head of the linked list after doubling it.

// Input: head = [1,8,9]
// Output: [3,7,8]
// Explanation: The figure above corresponds to the given linked list which represents the number 189. Hence, the returned linked list represents the number 189 * 2 = 378.

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
    ListNode* reverse(ListNode* head){
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
    ListNode* doubleIt(ListNode* head){
       
       ListNode* curr = reverse(head);
       head = curr;
       ListNode* prev = NULL;
       int carry = 0;
       while(curr!=NULL){
            int updateValue = curr->val*2 + carry;
            
            curr->val = updateValue%10;
            
            if (updateValue > 9){
                carry= 1;
            }
            else{
                carry = 0;
            }
            prev = curr;
            curr = curr->next;
       }
       
       if (carry > 0){
            prev->next = new ListNode(carry);
       }
       
       return reverse(head);
       
    }
};

signed main(){  
    int n;
    cin>>n;
    ListNode* nums = buildList(n);
    Solution ob;
    ListNode* res = ob.doubleIt(nums);
    printList(res);   
    return 0;
}