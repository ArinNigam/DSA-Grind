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
    Node* func(Node* head){
        Node* curr = head->next;
        Node* prev = head;
        
        while(curr!=NULL){
            if (curr->data < prev->data){
                prev->next = curr->next;
                curr->next = head;
                head = curr;
                curr = prev;
            }
            else{
                prev = curr;
            }
            
            curr = curr->next;
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