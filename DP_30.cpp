#include <bits/stdc++.h>
using namespace std;

// Best Time to Buy and Sell Stock with Transaction Fee
class Solution
{
public:
    int solve(int index, int buy, vector<int> &prices, int fee, vector<vector<int>> &dp)
    {
        if (index >= prices.size())
            return 0;
        if (dp[index][buy] != -1)
            return dp[index][buy];
        int profit = 0;

        if (buy)
        {
            profit = max(-prices[index] + solve(index + 1, 0, prices, fee, dp), 0 + solve(index + 1, 1, prices, fee, dp));
        }
        else
        {
            profit = max(+prices[index] + solve(index + 1, 1, prices, fee, dp) - fee, 0 + solve(index + 1, 0, prices, fee, dp));
        }
        return dp[index][buy] = profit;
    }
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        int buy = 1;
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        int ans = solve(0, buy, prices, fee, dp);
        return ans;
    }
};

int main()
{

    return 0;
}