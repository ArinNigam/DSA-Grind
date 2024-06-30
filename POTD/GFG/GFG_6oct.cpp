//Given a linked list, you have to perform the following task:

// Extract the alternative nodes starting from second node.
// Reverse the extracted list.
// Append the extracted list at the end of the original list.

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
    Node* reverse(struct Node *head){
        Node* curr = head;
        Node* prev = NULL;
        while(curr!=NULL){
            Node* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    void rearrange(struct Node *odd)
    {
        //add code here
        Node* head1 = odd;
        Node* head2 = odd->next;
        Node* first =odd;
        Node* second = odd;
        while(odd!=NULL && first->next!=NULL && second->next!=NULL){
            first->next = second->next;
            first = second->next;
            second->next = second->next->next;
            second = first->next;
        }
        first->next = NULL;
        odd = head1;
        
        while(head1->next!=NULL){
            head1= head1->next;
        }
        head1->next = reverse(head2);
        
        
       
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
        Node* res = ob.rearrange(nums);
        printList(res);
        
    }
  return 0;
}