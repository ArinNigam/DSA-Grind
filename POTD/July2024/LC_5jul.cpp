// Find the Minimum and Maximum Number of Nodes Between Critical Points (Medium)

// A critical point in a linked list is defined as either a local maxima or a local minima.
// A node is a local maxima if the current node has a value strictly greater than the previous node and the next node.
// A node is a local minima if the current node has a value strictly smaller than the previous node and the next node.
// Note that a node can only be a local maxima/minima if there exists both a previous node and a next node.
// Given a linked list head, return an array of length 2 containing [minDistance, maxDistance] where minDistance is the minimum distance between any two distinct critical points and maxDistance is the maximum distance between any two distinct critical points. If there are fewer than two critical points, return [-1, -1]

// Input: head = [5,3,1,2,5,1,2]
// Output: [1,3]
// Explanation: There are three critical points:
// - [5,3,1,2,5,1,2]: The third node is a local minima because 1 is less than 3 and 2.
// - [5,3,1,2,5,1,2]: The fifth node is a local maxima because 5 is greater than 2 and 1.
// - [5,3,1,2,5,1,2]: The sixth node is a local minima because 1 is less than 5 and 2.
// The minimum distance is between the fifth and the sixth node. minDistance = 6 - 5 = 1.
// The maximum distance is between the third and the sixth node. maxDistance = 6 - 3 = 3.

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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (head==NULL) return {};
        int minDist = -1;
        int maxDist = -1;
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        
        int i = 0;
        int ind = -1;
        int minInd = -1;
        int prevInd = -1;
        while(curr->next!=NULL){
            if((prev->val > curr->val && curr->val < curr->next->val) 
                || (prev->val < curr->val && curr->val > curr->next->val)){
                prevInd = ind;
                ind = i;
                if(minInd==-1){
                    minInd = i;
                }
                
                if (prevInd!=-1){
                    if (minDist==-1){
                        minDist = ind-prevInd;
                    }
                    else{
                        minDist = min(minDist,ind-prevInd);
                    }
                    maxDist = ind-minInd;
                }
            }
            prev = curr;
            curr = curr->next;
            i++;
        }
        return {minDist,maxDist};
        
    }
};

signed main(){  
    int n;
    cin>>n;
    ListNode* nums = buildList(n);
    Solution ob;
    auto res = ob.nodesBetweenCriticalPoints(nums);
    for(auto it:res){
        cout<<it<<" ";
    }
    return 0;
}