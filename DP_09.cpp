#include <bits/stdc++.h>
using namespace std;

// Perfect Squares Problem
class Solution
{
public:
    int solve(int n, vector<int> &dp)
    {
        if (n == 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];
        int ans = n;
        for (int i = 1; i * i <= n; i++)
        {
            ans = min(ans, 1 + solve(n - i * i, dp));
        }
        dp[n] = ans;
        return ans;
    }
    int numSquares(int n)
    {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j * j <= i; j++)
            {
                int temp = j * j;
                if (i - temp >= 0)
                    dp[i] = min(dp[i], 1 + dp[i - temp]);
            }
        }
        return dp[n];
    }
};

int main()
{

    return 0;
}