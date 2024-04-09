// Number of Students Unable to Eat Lunch (Easy)
// The school cafeteria offers circular and square sandwiches at lunch break, referred to by numbers 0 and 1 respectively. All students stand in a queue. Each student either prefers square or circular sandwiches.
// The number of sandwiches in the cafeteria is equal to the number of students. The sandwiches are placed in a stack. At each step:

// If the student at the front of the queue prefers the sandwich on the top of the stack, they will take it and leave the queue.
// Otherwise, they will leave it and go to the queue's end.
// This continues until none of the queue students want to take the top sandwich and are thus unable to eat.

// You are given two integer arrays students and sandwiches where sandwiches[i] is the type of the ith sandwich in the stack (i = 0 is the top of the stack) and students[j] is the preference of the jth student
// in the initial queue (j = 0 is the front of the queue). Return the number of students that are unable to eat.
// Example 2:
// Input: students = [1,1,1,0,0,1], sandwiches = [1,0,0,0,1,1]
// Output: 3


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int counter(vector<int>& students, vector<int>& sandwiches,int num){
        return max(0,(int)(count(students.begin(),students.end(),num) - count(sandwiches.begin(),sandwiches.end(),num)));
    }
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        int top = sandwiches[0];
        int front = students[0];
        int remaining = n;
        vector<int>cnt(2,0);
        for (auto it:students){
            cnt[it]++;
        }
        for (auto it:sandwiches){
            if (cnt[it]==0){
                break;
            }
            remaining--;
            if (remaining==0){
                break;
            }
            cnt[it]--;
        }
        return remaining;
    }
};

signed main()
{    
    int n;
    cin>>n;
    vector<int>students(n);
    for (int i=0;i<n;i++){
        cin>>students[i];
    }
    vector<int>sandwiches(n);
    for (int i=0;i<n;i++){
        cin>>sandwiches[i];
    }
    Solution ob;
    auto ans = ob.countStudents(students,sandwiches);
    cout<<ans;
    return 0;
}