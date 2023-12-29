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
  bool searchInLinkedList(Node* list,int newValue){
        Node* head = list;
        while(head!=NULL){
            // jab tak head jo value ko point kar rha wo given value ke equal nahi hoti
            if (head->data==newValue){
                return 1;
            }
            head = head->next;
        }
        return 0;
    }
    
};

signed main()
{  
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        Node* nums = buildList(n);
        
        Solution ob;
        bool res = ob.searchInLinkedList(nums,x);
        cout<<res<<endl;
        
    }
  return 0;
}