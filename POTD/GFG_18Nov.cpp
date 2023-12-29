// Reverse a Doubly Linked List
//  3 <--> 4 <--> 5
//  5 <--> 4 <--> 3
#include<bits/stdc++.h>
using namespace std;
//------------------------------------------------------------
struct Node {
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
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
    Node* reverseDLL(Node * head)
    {
        //Your code here
        Node* curr = head;
        Node* next = NULL;
        while(curr!=NULL){
            head = curr;
            next = curr->next;
            curr->next = curr->prev;
            curr->prev = next;
            curr = next;
        }
        return head;
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
        Node* res = ob.func(nums);
        printList(res);
        
    }
  return 0;
}