 // Merge Nodes in Between Zeros (Medium)

// You are given the head of a linked list, which contains a series of integers separated by 0's. The beginning and end of the linked list will have Node.val == 0.
// For every two consecutive 0's, merge all the nodes lying in between them into a single node whose value is the sum of all the merged nodes. The modified list should not contain any 0's.
// Return the head of the modified linked list.

// Input: head = [0,3,1,0,4,5,2,0]
// Output: [4,11]
// Explanation: 
// The above figure represents the given linked list. The modified list contains
// - The sum of the nodes marked in green: 3 + 1 = 4.
// - The sum of the nodes marked in red: 4 + 5 + 2 = 11.

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
    ListNode* mergeNodes(ListNode* head) {
        if (head==NULL){
            return head;
        }
        ListNode* curr = head->next;
        ListNode* ans = NULL;
        ListNode* root = ans;
        int sum = 0;
        while(curr!=NULL){
            if(curr->val==0){
                ListNode* node = new ListNode(sum);
                if (ans==NULL){
                    ans = node;
                    root = node;
                }
                else{
                    ans->next = node;
                    ans = ans->next;
                }
                sum = 0;
            }
            else{
                sum+=curr->val;
            }
            curr = curr->next;
        }
        return root;
    }
};

signed main(){  
    int n;
    cin>>n;
    ListNode* nums = buildList(n);
    Solution ob;
    ListNode* res = ob.mergeNodes(nums);
    printList(res);   
    return 0;
}