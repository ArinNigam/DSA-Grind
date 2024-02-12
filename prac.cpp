// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;
// Declare a vector to store prefix sum values
vector<long long> preSum;

// Define the helper function that takes in a vector of
// integers nums, an integer k, and an integer index as
// input
int helper(vector<int>& nums, int k, int index)
{
    // Initialize variables low, high, and res to store the
    // lower index, higher index, and the result index
    int low = 0;
    int high = index;
    int res = index;
    // Perform binary search to find the maximum frequency
    // of the current element by varying the element to its
    // left
    while (low <= high) {
        int mid = low + (high - low) / 2;
        // Calculate the sum of the elements from mid to
        // index
        long long s = preSum[index + 1] - preSum[mid];
        // Check if the sum can be increased by at most k by
        // replacing the elements from mid to index with the
        // current element nums[index]
        if (s + k
            >= (long long)(index - mid + 1) * nums[index]) {
            // If yes, update the result to mid and search
            // for a better solution to the left of mid
            res = mid;
            high = mid - 1;
        }
        else {
            // If no, search for a better solution to the
            // right of mid
            low = mid + 1;
        }
    }
    // Return the frequency of the current element
    return index - res + 1;
}

// Define the maxFrequency function that takes in a vector
// of integers nums and an integer k as input
int maxFrequency(vector<int>& nums, int k)
{
    // Sort the input vector in non-decreasing order
    sort(nums.begin(), nums.end());
    // Get the size of the input vector
    int n = nums.size();
    // Resize the prefix sum vector to size n+1
    preSum.resize(n + 1);
    // Calculate the prefix sum values and store them in the
    // prefix sum vector
    for (int i = 0; i < n; i++) {
        preSum[i + 1] = preSum[i] + nums[i];
    }
    // Initialize a variable ans to store the maximum
    // frequency
    int ans = 0;
    // Iterate over each element of the input vector
    for (int i = 0; i < n; i++) {
        // Update the maximum frequency by taking the
        // maximum of the current maximum frequency and the
        // frequency of the current element
        ans = max(ans, helper(nums, k, i));
    }
    // Return the maximum frequency
    return ans;
}

// Driver code
int main()
{
    vector<int> arr = { 1,3};
    int K = 1;
    cout << "Frequency of the Most Frequent Element : "
        << maxFrequency(arr, K);
    return 0;
}
//this code is contributed by Ravi Singh
