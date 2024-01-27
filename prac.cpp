#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>&nums,int low,int high,int mid){
    int left = low;
    int right = mid+1;
    vector<int>temp;
    while(left<=mid && right<=high){
        if (nums[left] > nums[right]){
            temp.push_back(nums[right]);
            right++;
        }
        else{
            temp.push_back(nums[left]);
            left++;
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

signed main()
{    
    int n;
    cin>>n;
    vector<int>nums(n);
    for (int i=0;i<n;i++){
        cin>>nums[i];
    }
   
    mergeSort(nums,0,n-1);
    for (auto it:nums){
        cout<<it<<" ";
    }
    return 0;
}