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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        ListNode* curr = head;
        while(curr!=NULL){
            curr = curr->next;
            len++;
        }
        int m = k;
        int mod = len % k;
        k = len / k;
        vector<ListNode*>ans;
       
        curr = head;
        ListNode* node = curr;
        int n = 0;
        while(curr!=NULL){
            n++;
            if ( k!=0 && n / k == 1){
                if (mod > 0){
                    mod--;
                    curr = curr->next;
                    ListNode* temp = curr->next;
                    curr->next = NULL;
                    ans.push_back(node);
                    node = temp;
                    curr = temp;
                }
                else{
                    ListNode* temp = curr->next;
                    curr->next = NULL;
                    ans.push_back(node);
                    node = temp;
                    curr = temp;
                }
                n = 0;
                
            }
            else if(k == 0){
                ListNode* temp = curr->next;
                curr->next = NULL;
                ans.push_back(node);
                node = temp;
                curr = temp;
            }
            else{
                curr = curr->next;
            }
        }
        ListNode* temp = NULL;
        while (ans.size() < m){
            ans.push_back(temp);
        }
        return ans;

    }
};

signed main(){  
    int n;
    cin>>n;
    ListNode* nums = buildList(n);
    Solution ob;
    int k;
    cin>>k;
    auto ans = ob.splitListToParts(nums,k);
    for(auto it:ans){
        printList(it);
    }
    return 0;
}