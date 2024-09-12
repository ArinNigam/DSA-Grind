// Spiral Matrix IV (Medium)

// You are given two integers m and n, which represent the dimensions of a matrix.
// You are also given the head of a linked list of integers.
// Generate an m x n matrix that contains the integers in the linked list presented in spiral order (clockwise), starting from the top-left of the matrix. If there are remaining empty spaces, fill them with -1.
// Return the generated matrix.

// Input: m = 3, n = 5, head = [3,0,2,6,8,1,7,9,4,2,5,5,0]
// Output: [[3,0,2,6,8],[5,0,-1,-1,1],[5,2,4,9,7]]
// Explanation: The diagram above shows how the values are printed in the matrix.
// Note that the remaining spaces in the matrix are filled with -1.

#include<bits/stdc++.h>
using namespace std;

//------------------------------------------------------------

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

struct ListNode* buildList(int size){
    int val;
    cin>>val;
    
    ListNode* head = new ListNode(val);
    ListNode* tail = head;
    
    for (int i=0;i<size-1;i++){
        cin>>val;
        tail->next = new ListNode(val);
        tail = tail->next;
    }
    return head;
}

void printList(ListNode *n){
    while(n){
        cout<<n->val<<" ";
        n = n->next;
    }
    cout<<endl;
}

//------------------------------------------------------------

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>ans(m,vector<int>(n,-1));
      
        ListNode* curr = head;
        vector<vector<int>>dirn = {{0,1},{1,0},{0,-1},{-1,0}};
        int x = 0;
        int y = 0;
        int ptr = 0;

        for (; head != NULL; head = head->next) {
            cout << x << " " << y << endl;
            ans[x][y] = head->val;
            int nx = x + dirn[ptr][0];
            int ny = y + dirn[ptr][1];

            if (nx < 0 || ny < 0 || nx >= m || ny >= n || ans[nx][ny] != -1){
                ptr = (ptr + 1) % 4;
            }
                
            x += dirn[ptr][0];
            y += dirn[ptr][1];
        }
        return ans;
       

        
    }
};

signed main(){  
    int m,n;
    cin>>n>>m;
    int k;
    cin>>k;
    ListNode* nums = buildList(k);
    Solution ob;
    auto ans = ob.spiralMatrix(nums,m,n);
    for (auto i:ans){
      for (auto j:i){
        cout<<j<<" ";
      }
      cout<<endl;
    }
    return 0;
}