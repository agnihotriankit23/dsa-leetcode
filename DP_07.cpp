#include <bits/stdc++.h>
using namespace std;

// 0-1 KNAPSACK PROBLEM
int solve(vector<int> &weight, vector<int> &value, int index, int W, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (weight[index] <= W)
        {
            return value[0];
        }
        else
        {
            return 0;
        }
    }
    if (dp[index][W] != -1)
    {
        return dp[index][W];
    }
    int include = 0;
    if (weight[index] <= W)
    {
        include = value[index] + solve(weight, value, index - 1, W - weight[index], dp);
    }
    int exclude = 0 + solve(weight, value, index - 1, W, dp);

    dp[index][W] = max(include, exclude);
    return dp[index][W];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    return solve(weight, value, n - 1, maxWeight, dp);
}

int main()
{

    return 0;
}