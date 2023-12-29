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
    bool hasCycle(Node* head){
        unordered_set<Node*> st;
        while(head!=NULL){
            if (st.find(head)!=st.end()){
                return 1;
            }
            st.insert(head);
            head = head->next;
        }
        return 0;
    }
    Node* detectCycle(Node* head){
        if (head==NULL || head->next == NULL) return NULL;
        
        // saare pointers head yaani 0th index par hai
        Node* slow = head;
        Node* fast = head;
        Node* entry= head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;// slow ko 1 badha
            fast = fast->next->next; // fast ko 2 badha
            if (slow== fast){ // jab fast aur slow aaps me mil jaye
                while(slow!=entry){ // tab tak chala jab tak entry aur slow equal na ho jaye
                    slow = slow->next;
                    entry= entry->next;
                }
                return slow;
            }
        }
        return NULL;
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
        Node* res = ob.detectCycle(nums);
        printList(res);
        
    }
  return 0;
}