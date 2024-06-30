// Pairwise swap elements
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
class Solution
{
    public:
    Node* pairWiseSwap(struct Node* head) 
    {
       if (!head || !head->next){
           return head;
       }
       Node* temp = head->next;
       head->next = pairWiseSwap(head->next->next);
       temp->next = head;
       return temp;
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
        
        Solution ob;
        Node* res = ob.pairWiseSwap(nums);
        printList(res);
        
    }
  return 0;
}