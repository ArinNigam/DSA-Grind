// using slow and fast pointers
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
  Node* middleNode(Node* head){
        Node* slow=head;
        Node* fast = head;
        
        while (fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
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
        Node* res = ob.middleNode(nums);
        printList(res);
        
    }
  return 0;
}