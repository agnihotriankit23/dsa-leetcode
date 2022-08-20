#include <bits/stdc++.h>
using namespace std;

// COMBINATION SUM IV
class Solution
{
public:
    int solve(vector<int> &nums, int target, vector<int> &dp)
    {
        if (target < 0)
            return 0;

        if (target == 0)
            return 1;

        if (dp[target] != -1)
            return dp[target];

        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            ans += solve(nums, target - nums[i], dp);
        }
        dp[target] = ans;
        return ans;
    }
    int combinationSum4(vector<int> &nums, int target)
    {
        vector<int> dp(target + 1, -1);
        dp[0] = 0;
        return solve(nums, target, dp);
    }
};

int main()
{

    return 0;
}