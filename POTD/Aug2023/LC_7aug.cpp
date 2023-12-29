// Search a 2D Matrix ( Medium )
// You are given an m x n integer matrix matrix with the following two properties:

// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.

// You must write a solution in O(log(m * n)) time complexity.

// Input: matrix = 
    // [[1,3,5,7],
    // [10,11,16,20],
    // [23,30,34,60]], target = 3
// Output: true

// Input: matrix = 
    // [[1,3,5,7],
    // [10,11,16,20],
    // [23,30,34,60]], target = 13
// Output: false

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
bool searchMatrix(vector<vector<int>>& matrix,int target){
    int m = matrix.size(); 
    int n = matrix[0].size(); 
    int left = 0;
    int right = m*n-1;
    while(left<=right){
        int mid = (left+right)/2;
        if (matrix[mid/n][mid%n] == target){
            return true;
        }
        else if (matrix[mid/n][mid%n]>target){
            right = mid-1;
        }
        else{
            left = mid+1;
        }
    }
    return false;
    
    
}   
};
signed main()
{    
    int n,target;
    cin>>n>>target;
    vector<vector<int>>matrix(n,vector<int>(n));
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
    Solution ob;
    auto ans = ob.searchMatrix(matrix,target);
    cout<<((ans==1)? "YES" : "NO");
    return 0;
}