// Sum of a 2 Linked List
#include<bits/stdc++.h>
using namespace std;
//------------------------------------------------------------
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
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

/**
 * Definition for singly-linked list.
 
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        int carry = 0;
        while(l1!=NULL || l2!=NULL || carry){
            int sum =0;
            if (l1!=NULL){
                sum+=l1->val;
                l1=l1->next;
            }
            if (l2!=NULL){
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            carry = sum/10;
            ListNode* Node = new ListNode(sum%10);
            temp->next = Node;
            temp = temp->next;
        }
        return dummy->next;
    }
};

signed main()
{  
    
    int n,m;
    cin>>n>>m;
    ListNode* l1 = buildList(n);
    ListNode* l2 = buildList(m);
    Solution ob;
    ListNode* res = ob.addTwoNumbers(l1,l2);
    printList(res);
    return 0;
}