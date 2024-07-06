#include<bits/stdc++.h>
using namespace std;

class QuickSort {
public:
    int findPivot(int low,int high,vector<int>&nums){
        int pivot = nums[low];
        int i = low;
        int j = high;
        while (i<j){
            while(nums[i]<=pivot && i<=high-1){
                i++;
            }
            while(nums[j] >pivot && j>=low+1){
                j--;
            }
            if (i<j){
                swap(nums[i],nums[j]);
            }
        }
        swap(nums[low],nums[j]);
        return j;
    }
    void quickSort(int low,int high,vector<int>& nums){
        if(low < high){
            int pivot = findPivot(low,high,nums);
            quickSort(low,pivot-1,nums);
            quickSort(pivot+1,high,nums);
        }
    }
    void solve(vector<int>&nums){
        int n = nums.size();
        quickSort(0,n-1,nums);
    }
};

class MergeSort {
public:
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
    int solve(vector<int>&nums){
        int n = nums.size();
        mergeSort(nums,0,n-1);
    }
};

signed main()
{    
    int n;
    cin>>n;
    vector<int>nums(n);
    for (int i=0;i<n;i++){
        cin>>nums[i];
    }
    QuickSort ob1;
    auto nums1 = nums;
    ob1.solve(nums1);
    for(auto it:nums1){
        cout<<it<<" ";
    }
    cout<<endl;
    MergeSort ob2;
    ob1.solve(nums);
    for(auto it:nums){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}