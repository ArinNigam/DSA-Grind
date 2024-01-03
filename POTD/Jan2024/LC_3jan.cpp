// Number of Laser Beams in a Bank ( Medium)
// Anti-theft security devices are activated inside a bank. You are given a 0-indexed binary string array bank representing the floor plan of the bank, which is an m x n 2D matrix. bank[i] represents the ith row, consisting of '0's and '1's. '0' means the cell is empty, while'1' means the cell has a security device.

// There is one laser beam between any two security devices if both conditions are met:

// The two devices are located on two different rows: r1 and r2, where r1 < r2.
// For each row i where r1 < i < r2, there are no security devices in the ith row.
// Laser beams are independent, i.e., one beam does not interfere nor join with another.

// Return the total number of laser beams in the bank.

// Input: bank = ["011001","000000","010100","001000"]
// Output: 8

// Input: bank = ["000","111","000"]
// Output: 0

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int m = bank.size();
        int n = bank[0].size();
        string t(n,'0');
        int sum = 0;
        for (int i=0;i<m;i++){
            string t= bank[i];
            int cnt1 = count(t.begin(),t.end(),'1');
            for (int j=i+1;j<m;j++){
                string temp = bank[j];
                int cnt2 =count(temp.begin(),temp.end(),'1');
                if (cnt2!=0){
                    sum+=(cnt1*cnt2);
                    break;
                }
            }
        }
        return sum;
        
    }
};

signed main()
{    
    int n;
    cin>>n;
    vector<string>nums(n);
    for (int i=0;i<n;i++){
        cin>>nums[i];
    }
    Solution ob;
    auto ans = ob.numberOfBeams(nums);
    cout<<ans;
    return 0;
}