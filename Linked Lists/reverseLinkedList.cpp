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
  Node* reverse(Node* head){
      Node* curr = head;
      Node* prev = NULL;
      Node* next = NULL;
      while(curr!=NULL){
          next = curr->next; // storing head ka next
          curr->next = prev; // arrow ko ulti tarf mod dia
          prev = curr; // ab prev jo h wo current ho jayega
          curr = next; // aur current jo tha wo next ho jayega
      }
      // yeh tab tak chalega jab tak current wala NULL na ho jaye
      return prev;
  }
};

signed main()
{  
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n;
		Node* first = buildList(n);
		
		Solution ob;
		Node* res = ob.reverse(first);
		printList(res);
		
	}
  return 0;
}