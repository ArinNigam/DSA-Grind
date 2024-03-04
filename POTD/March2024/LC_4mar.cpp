// Bag of Tokens (Medium)

// You start with an initial power of power, an initial score of 0, and a bag of tokens given as an integer array tokens, where each tokens[i] donates the value of tokeni.

// Your goal is to maximize the total score by strategically playing these tokens. In one move, you can play an unplayed token in one of the two ways (but not both for the same token):

// Face-up: If your current power is at least tokens[i], you may play tokeni, losing tokens[i] power and gaining 1 score.
// Face-down: If your current score is at least 1, you may play tokeni, gaining tokens[i] power and losing 1 score.
// Return the maximum possible score you can achieve after playing any number of tokens.

// Input: tokens = [100,200,300,400], power = 200
// Output: 2

// Explanation: Play the tokens in this order to get a score of 2:
// Play token0 (100) face-up, reducing power to 100 and increasing score to 1.
// Play token3 (400) face-down, increasing power to 500 and reducing score to 0.
// Play token1 (200) face-up, reducing power to 300 and increasing score to 1.
// Play token2 (300) face-up, reducing power to 0 and increasing score to 2.
// The maximum score achievable is 2.
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int n = tokens.size();
        int maxi =0;
        int score = 0;
        int i = 0,j = n-1;
        
        while(i<=j){
            if (power>=tokens[i]){
                power-=tokens[i];
                score++;
                maxi = max(maxi,score);
                i++;
            }
            else if (score > 0){
                power+=tokens[j];
                score--;
                j--;
            }
            else{
                break;
            }
        }
        
        return maxi;
    }
};

signed main()
{    
    int n,k;
    cin>>n>>k;
    vector<int>nums(n);
    for (int i=0;i<n;i++){
        cin>>nums[i];
    }
    Solution ob;
    auto ans = ob.bagOfTokensScore(nums,k);
    cout<<ans;
    return 0;
}