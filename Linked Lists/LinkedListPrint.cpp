#include<bits/stdc++.h>
using namespace std;

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

class Solution
{
  public:
  Node* list(vector<int>&nums){
    int n = nums.size();
    Node* head = new Node(nums[0]);
    for (int i=1;i<n;i++){
        Node* node = new Node(nums[i]);
        node->next = head;
        head = node;
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
        vector<int>nums(n);
        for (int i=0;i<n;i++){
            cin>>nums[i];
        }
        
        Solution ob;
        Node* res = ob.list(nums);
        printList(res);
        
    }
  return 0;
}