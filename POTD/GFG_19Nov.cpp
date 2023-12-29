// Finding common elements in 2 linked lists
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
    Node* findIntersection(Node* head1, Node* head2)
    {
        Node* head = new Node(-1);
        Node* temp = head;
        while(head1!=NULL && head2!=NULL){
            if (head1->data == head2->data){
                Node* curr = new Node(head1->data);
                temp->next = curr;
                temp = temp->next;
                head1 = head1->next;
                head2 = head2->next;
            }
            else if(head1->data > head2->data){
                head2 = head2->next;
            }
            else{
                head1 = head1->next;
            }
        }
        return head->next;
        
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