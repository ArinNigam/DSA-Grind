// Delete Nodes From Linked List Present in Array (Medium)

// You are given an array of integers nums and the head of a linked list. Return the head of the modified linked list after removing all nodes from the linked list that have a value that exists in nums.

// Example 1:
// Input: nums = [1,2,3], head = [1,2,3,4,5]
// Output: [4,5]

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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>st(nums.begin(),nums.end());
        ListNode* curr = head;
        while (curr->next!= NULL){
            if (st.find(curr->next->val)!=st.end()){
                curr->next = curr->next->next;
                continue;
            }
            curr = curr->next;
        }
        if (st.find(head->val)!=st.end()){
            return head->next;
        }
        return head;
    }
};

signed main(){  
    int n,m;
    cin>>n>>m;
    vector<int>nums(m);
    for(int i=0;i<m;i++){
        cin>>nums[i];
    }
    ListNode* head = buildList(n);
    
    Solution ob;
    ListNode* res = ob.modifiedList(nums, head);
    printList(res);   
    return 0;
}