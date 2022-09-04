#include <bits/stdc++.h>
using namespace std;

// Best Time to Buy and Sell Stock IV
class Solution
{
public:
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

    int maxProfit(int k, vector<int> &prices)
    {
        int buy = 1;
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        int ans = solve(0, buy, k, prices, dp);
        return ans;
    }
};

int main()
{

    return 0;
}