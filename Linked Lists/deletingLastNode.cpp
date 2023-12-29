// Deleting Last Node from Linked List
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
  void deleteNode(Node* head) {
    if (head->next == NULL){
        delete head;
        head = NULL;
    } 
    else{
        Node* curr = head;
        Node* prev = NULL;
        while(curr->next !=NULL){
            prev = curr;
            curr = curr->next;
        }
        prev->next = NULL;
        delete curr;
    } 
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
        ob.deleteNode(nums);
        printList(nums);
        
    }
  return 0;
}