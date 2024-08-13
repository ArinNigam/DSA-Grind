// Kth Largest Element in a Stream (Easy)

// Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.
// Implement KthLargest class:
// KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of integers nums.
// int add(int val) Appends the integer val to the stream and returns the element representing the kth largest element in the stream.

// ["KthLargest", "add", "add", "add", "add", "add"]
// [[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
// Output
// [null, 4, 5, 5, 8, 8]

#include<bits/stdc++.h>
using namespace std;

class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>minHeap;
    int kth;
    KthLargest(int k, vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            minHeap.push(nums[i]);
            if (minHeap.size() > k){
                minHeap.pop();
            }
        }
        kth = k;
        
    }
    
    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > kth){
            minHeap.pop();
        }
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

signed main()
{  
  int n;
  cin>>n;
  vector<int>nums(n);
  for (int i=0;i<n;i++){
    cin>>nums[i];
  }
  KthLargest ob(n,nums);
  int m;
  cin>>m;
  for(int i=0;i<n;i++){
      int x;
      cin>>x;
      cout<<ob.add(x);
  }
  
  
  return 0;
}