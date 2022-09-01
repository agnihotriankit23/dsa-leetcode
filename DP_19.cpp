#include <bits/stdc++.h>
using namespace std;

// Number of Dice Rolls With Target Sum
#define M 1000000007
class Solution
{
public:
    // This Top-down Approach

    int solve(int dices, int faces, int target, vector<vector<int>> &dp)
    {
        if (dices == 0 && target != 0)
            return 0;

        if (dices != 0 && target == 0)
            return 0;

        if (target < 0)
            return 0;

        if (dices == 0 && target == 0)
            return 1;

        if (dp[dices][target] != -1)
            return dp[dices][target];
        long long int ans = 0;

        for (int i = 1; i <= faces; i++)
        {
            ans = ans + solve(dices - 1, faces, target - i, dp);
        }
        return dp[dices][target] = ans % M;
    }

    int numRollsToTarget(int n, int k, int target)
    {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        int ans = solve(n, k, target, dp);
        return ans;
    }
};

int main()
{

    return 0;
}