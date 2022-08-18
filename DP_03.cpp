#include <bits/stdc++.h>
using namespace std;

// MAX SUM WITHOUT ADJACENTS
//  House Robbery Problem
class Solution
{
public:
    // calculate the maximum sum with out adjacent
    int solve(int *arr, int n, vector<long long int> &dp)
    {
        if (n < 0)
            return 0;

        if (dp[n] != -1)
            return dp[n];
        int include = solve(arr, n - 2, dp) + arr[n];
        int exclude = solve(arr, n - 1, dp) + 0;

        dp[n] = max(include, exclude);
        return dp[n];
    }
    int findMaxSum(int *arr, int n)
    {
        // code here
        vector<long long int> dp(n + 1, -1);
        dp[0] = arr[0];
        int ans = solve(arr, n - 1, dp);
        return ans;
    }
};

int main()
{

    return 0;
}