#include <bits/stdc++.h>
using namespace std;

// Partition Equal Subset Sum
class Solution
{
public:
    // This is Top-Down Approach
    bool solve(int index, int target, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (target == 0)
            return true;
        if (target < 0)
            return false;

        if (index >= nums.size())
            return false;

        if (dp[index][target] != -1)
            return dp[index][target];

        bool take = solve(index + 1, target - nums[index], nums, dp);
        bool notTake = solve(index + 1, target, nums, dp);

        return dp[index][target] = (take || notTake);
    }

    // This is Bottom-Up Approach
    bool solveTab(vector<int> &nums, int target)
    {
        int n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 1;
        }

        for (int index = n - 1; index >= 0; index--)
        {
            for (int sum = 0; sum <= target; sum++)
            {

                bool take = 0;

                if (sum - nums[index] >= 0)
                    take = dp[index + 1][sum - nums[index]];

                bool notTake = dp[index + 1][sum];

                dp[index][sum] = (take || notTake);
            }
        }
        return dp[0][target];
    }

    // This is S[ace Optimised Approach

    bool solveSO(vector<int> &nums, int target)
    {
        int n = nums.size();

        vector<int> curr(target + 1, 0);
        vector<int> next(target + 1, 0);

        next[0] = 1;
        for (int index = n - 1; index >= 0; index--)
        {
            for (int sum = 0; sum <= target; sum++)
            {

                bool take = 0;

                if (sum - nums[index] >= 0)
                    take = next[sum - nums[index]];

                bool notTake = next[sum];

                curr[sum] = (take || notTake);
            }
            next = curr;
        }
        return curr[target];
    }

    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (auto i : nums)
        {
            sum += i;
        }
        if (sum % 2 != 0)
            return 0;
        // int n = nums.size();
        int target = sum / 2;
        // vector<vector<int> > dp(n+1,vector<int> (target+1,-1));
        // bool ans = solve(0,target,nums,dp);
        // return ans;

        // return solveTab(nums,target);
        return solveSO(nums, target);
    }
};

int main()
{

    return 0;
}