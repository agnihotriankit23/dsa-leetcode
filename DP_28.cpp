#include <bits/stdc++.h>
using namespace std;

// Best Time to Buy and Sell Stock III
class Solution
{
public:
    // This is Top-Down
    int solve(int index, int buy, int limit, vector<int> &prices, vector<vector<vector<int>>> &dp)
    {
        if (index >= prices.size() || limit == 0)
            return 0;
        if (dp[index][buy][limit] != -1)
            return dp[index][buy][limit];
        int profit = 0;

        if (buy)
        {
            profit = max(-prices[index] + solve(index + 1, 0, limit, prices, dp), 0 + solve(index + 1, 1, limit, prices, dp));
        }
        else
        {
            profit = max(+prices[index] + solve(index + 1, 1, limit - 1, prices, dp), 0 + solve(index + 1, 0, limit, prices, dp));
        }
        return dp[index][buy][limit] = profit;
    }

    // This is Bottom-Up
    int solveTab(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        for (int index = n - 1; index >= 0; index--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int limit = 1; limit <= 2; limit++)
                {
                    int profit = 0;
                    if (buy)
                    {
                        profit = max(-prices[index] + dp[index + 1][0][limit], 0 + dp[index + 1][1][limit]);
                    }
                    else
                    {
                        profit = max(+prices[index] + dp[index + 1][1][limit - 1], 0 + dp[index + 1][0][limit]);
                    }
                    dp[index][buy][limit] = profit;
                }
            }
        }
        return dp[0][1][2];
    }
    int maxProfit(vector<int> &prices)
    {
        // bool buy=1;
        // int limit = 2;
        // int n=prices.size();
        // vector<vector<vector<int> > > dp(n+1,vector<vector<int> > (2,vector<int> (3,-1)));
        // int ans =solve(0,buy,limit,prices,dp);
        // return ans;

        return solveTab(prices);
    }
};

int main()
{

    return 0;
}