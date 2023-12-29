// Reverse a Linked List between any 2 points
#include<bits/stdc++.h>
using namespace std;
//------------------------------------------------------------
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size){
    int val;
    cin>>val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for (int i=0;i<size-1;i++){
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    return head;
}
void printList(Node *n){
    while(n){
        cout<<n->data<<" ";
        n = n->next;
    }
    cout<<endl;
}
//------------------------------------------------------------

class Solution {
public:
    Node* reverseBetween(Node* head, int left, int right) {
        Node* dummy = new Node(0);
        dummy->next = head;
        Node* prev = dummy;

        for (int i=0;i<left-1;i++){
            prev = prev->next;
        }

        Node * curr =prev->next;

        for (int i=left;i<right;i++){
            Node* next = curr->next;
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }
        return dummy->next;
    }
};

signed main()
{  
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Node* nums = buildList(n);
        int l,r;
        cin>>l>>r;
        Solution ob;
        Node* res = ob.reverseBetween(nums,l,r);
        printList(res);
        
    }
  return 0;
}