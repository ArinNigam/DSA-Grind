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
    Node* reverse(Node* head){
        Node* dummy = NULL;
        while(head!=NULL){
            Node* next = head->next;
            head->next = dummy;
            dummy = head;
            head = next;
        }
        return dummy;
    }
    bool isPalindrome(Node* head){
       Node* slow = head;
       Node* fast = head;
       while(fast->next!=NULL && fast->next->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
       }
       slow->next = reverse(slow->next);
       slow = slow->next;
       Node* temp = head;
       while(slow!=NULL){
        
         if(slow->data != temp->data){
            return 0;
         }
         slow = slow->next;
         temp = temp->next;
       }
       return 1;
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
        bool res = ob.isPalindrome(nums);
        cout<<res;
        
    }
  return 0;
}