#include <bits/stdc++.h>
using namespace std;

// Min Cost Climbing Stairs
class Solution
{
public:
    int solve(vector<int> &cost, int n, vector<int> &dp)
    {
        if (n == 0)
            return cost[0];
        if (n == 1)
            return cost[1];
        if (dp[n] != -1)
        {
            return dp[n];
        }

        int ans = cost[n] + min(solve(cost, n - 1, dp), solve(cost, n - 2, dp));
        dp[n] = ans;
        return ans;
    }
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        // vector<int> dp(n+1,-1);
        //  dp[0]=cost[0];
        //  dp[1]=cost[1];
        // int ans = min( solve(cost,n-1,dp) , solve(cost,n-2,dp));
        //  return ans;

        int p1 = cost[0];
        int p2 = cost[1];
        for (int i = 2; i < n; i++)
        {
            int curr = min(p1, p2) + cost[i];
            p1 = p2;
            p2 = curr;
        }
        return min(p1, p2);
    }
};

int main()
{

    return 0;
}