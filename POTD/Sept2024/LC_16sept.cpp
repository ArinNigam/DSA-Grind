// Minimum Time Difference (Medium)
// Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list. 

// Input: timePoints = ["23:59","00:00"]
// Output: 1

// Input: timePoints = ["00:00","23:59","00:00"]
// Output: 0

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        sort(timePoints.begin(),timePoints.end());
        int hr1 = stoi(timePoints[0].substr(0,2));
        int minutes1 = stoi(timePoints[0].substr(3));
        hr1 += 24;
        string temp = to_string(hr1) + ":" + to_string(minutes1);
        timePoints.push_back(temp);        
        int mini = INT_MAX;
        for(int i=1;i<=n;i++){
            int minutes1 = stoi(timePoints[i-1].substr(3));
            int minutes2 = stoi(timePoints[i].substr(3));
            int hr1 = stoi(timePoints[i-1].substr(0,2));
            int hr2 = stoi(timePoints[i].substr(0,2));          
            if (minutes1 > minutes2){
                minutes2+=60;
                hr2-=1;
            }
            mini = min(mini,60 * (hr2 - hr1) + minutes2 - minutes1);
            hr1+=24;
            mini = min(mini,60 * (hr1 - hr2) + minutes2 - minutes1);
            minutes1+=60;
            
            hr1-=1;
            mini = min(mini,60 * (hr1 - hr2) + minutes1 - minutes2);
        }
       
        return mini;
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
    auto ans = ob.findMinDifference(nums);
    cout<<ans;
    return 0;
}