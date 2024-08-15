// Lemonade Change (Easy)

// At a lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy from you and order one at a time (in the order specified by bills). Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. You must provide the correct change to each customer so that the net transaction is that the customer pays $5.
// Note that you do not have any change in hand at first.
// Given an integer array bills where bills[i] is the bill the ith customer pays, return true if you can provide every customer with the correct change, or false otherwise.

// Input: bills = [5,5,5,10,20]
// Output: true
// Explanation: 
// From the first 3 customers, we collect three $5 bills in order.
// From the fourth customer, we collect a $10 bill and give back a $5.
// From the fifth customer, we give a $10 bill and a $5 bill.
// Since all customers got correct change, we output true.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int bill5 = 0, bill10 = 0 , bill20 = 0;

        int i = 0 ;
        while (i < n){
            if (bills[i] == 5){
                bill5++;
            }
            else if (bills[i]==10){
                if (bill5 > 0){
                    bill10++;
                    bill5--;
                }   
                else{
                    return false;
                }
            }
            else{
                if (bill10 > 0 && bill5 > 0){
                    bill10--;
                    bill5--;
                    bill20++;
                }
                else if (bill5 > 2){
                    bill5-=3;
                    bill20++;
                }
                else{
                    return false;
                }
            }
            i++;
        }
        return true;
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
  Solution ob;
  auto ans = ob.lemonadeChange(nums);
  cout<<ans;
  return 0;
}