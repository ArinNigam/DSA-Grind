// Merge In Between Linked Lists (Medium)
// You are given two linked lists: list1 and list2 of sizes n and m respectively.
// Remove list1's nodes from the ath node to the bth node, and put list2 in their place.


// Input: list1 = [10,1,13,6,9,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
// Output: [10,1,13,1000000,1000001,1000002,5]
// Explanation: We remove the nodes 3 and 4 and put the entire list2 in their place. The blue edges and nodes in the above figure indicate the result.


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

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* base = list1;
        ListNode* head1 = list1;
        ListNode* head2 = list2;
        while(a>1){
            head1 = head1->next;
            a--;
            b--;
        }
        ListNode* curr = head1;
        while(b>-1){
            curr = curr->next;
            b--;
        }
        ListNode* back = curr;
        head1->next = head2;
        while(head2->next!=NULL){
            head2 = head2->next;
        }
        head2->next = back;
        return base;
    }
};
signed main(){  
    int n,m;
    cin>>n>>m;
    ListNode* nums1 = buildList(n);
    ListNode* nums2 = buildList(m);
    int l,r;
    cin>>l>>r;
    Solution ob;
    ListNode* res = ob.mergeInBetween(nums1,l,r,nums2);
    printList(res);   
    return 0;
}