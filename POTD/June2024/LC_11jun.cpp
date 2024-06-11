// Relative Sort Array (Easy)

// Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.
// Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2. Elements that do not appear in arr2 should be placed at the end of arr1 in ascending order.

// Example 1:
// Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
// Output: [2,2,2,1,4,3,3,9,6,7,19]
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int,int>mp;
    bool cmp(int a,int b){
        int a1 = (mp.find(a)==mp.end()) ? INT_MAX : mp[a];
        int b1 = (mp.find(b)==mp.end()) ? INT_MAX : mp[b];
        
        if (a1 < b1){
            return true;
        }
        if (a1==b1){
            return a < b;
        }
        return false;
        
    }
    void merge(vector<int>&nums,int low,int high,int mid){
        int left = low;
        int right = mid+1;
        vector<int>temp;
        while(left<=mid && right<=high){
            if (cmp(nums[left],nums[right])){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left<=mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(nums[right]);
            right++;
        }
        for (int i=low;i<=high;i++){
            nums[i] = temp[i-low];
        }
    }
    void mergeSort(vector<int>&nums,int low,int high){
        if (low>=high) return;
        int mid = (low+high)/2;
        mergeSort(nums,low,mid);
        mergeSort(nums,mid+1,high);
        merge(nums,low,high,mid);
    }
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        for (int i=0;i<arr2.size();i++){
            mp[arr2[i]] = i;
        }
        mergeSort(arr1,0,arr1.size()-1);
        return arr1;
    }
};

signed main()
{    
    int n,m;
    cin>>n>>m;
    vector<int>nums1(n),nums2(m);
    for (int i=0;i<n;i++){
        cin>>nums1[i];
    }
    for (int i=0;i<m;i++){
        cin>>nums2[i];
    }
    Solution ob;
    auto ans = ob.relativeSortArray(nums1,nums2);
    for (auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}