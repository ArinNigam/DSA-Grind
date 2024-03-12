// Remove Zero Sum Consecutive Nodes from Linked List (Medium)

// Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences.
// After doing so, return the head of the final linked list.  You may return any such answer.

// Input: head = [1,2,-3,3,1]
// Output: [3,1]
// Note: The answer [1,2,1] would also be accepted.

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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        int preSum = 0;
        unordered_map<int,ListNode*>pre;
        pre[0] = dummy;
        
        ListNode* curr = head;
        
        while(curr!=NULL){
            preSum+=curr->val;
            if (pre.find(preSum)!=pre.end()){
                ListNode* del = pre[preSum]->next;
                int temp = preSum + del->val;
                while(del!=curr){
                    pre.erase(temp);
                    del = del->next;
                    temp+=del->val;
                }
                pre[preSum]->next = curr->next;
            }
            else{
                pre[preSum] = curr;
            }
            curr=curr->next;
        }
        
    }
};

signed main(){  
    int n;
    cin>>n;
    ListNode* nums = buildList(n);
    Solution ob;
    ListNode* res = ob.removeZeroSumSublists(nums);
    printList(res);   
    return 0;
}