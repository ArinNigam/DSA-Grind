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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int gcd (int a,int b ) {
        if (b == 0){
            return a;
        }
        return gcd(b,a%b);
    }
    ListNode* addNode(ListNode* head){
        ListNode* curr = head;
        ListNode* nxt = curr->next;
        ListNode* newNode = new ListNode(gcd(head->val,nxt->val));
        curr->next = newNode;
        newNode->next = nxt;
        curr = newNode->next;
        return curr;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr = head;
        while(curr->next!=NULL){
            curr = addNode(curr);
        }
        return head;
    }
};

signed main(){  
    int n;
    cin>>n;
    ListNode* nums = buildList(n);
    Solution ob;
    ListNode* res = ob.insertGreatestCommonDivisors(nums);
    printList(res);   
    return 0;
}