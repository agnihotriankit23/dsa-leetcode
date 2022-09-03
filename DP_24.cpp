#include <bits/stdc++.h>
using namespace std;

// Unique Binary Search Trees
class Solution
{
public:
    int solve(int n, vector<int> &dp)
    {
        if (n <= 1)
            return 1;
        if (dp[n] != -1)
            return dp[n];
        int ans = 0;

        for (int i = 1; i <= n; i++)
        {
            int temp = 0;
            temp = solve(i - 1, dp) * solve(n - i, dp);
            ans += temp;
        }
        return dp[n] = ans;
    }

    int solveTab(int n)
    {
        vector<int> dp(n + 1);
        dp[0] = dp[1] = 1;

        // i-> number of nodes
        for (int i = 2; i <= n; i++)
        {
            // j->root node
            for (int j = 1; j <= i; j++)
            {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
    int numTrees(int n)
    {
        // if(n<=1) return 1;
        //  vector<int> dp(n+1,-1);
        // return solve(n,dp);

        return solveTab(n);
    }
};

int main()
{

    return 0;
}