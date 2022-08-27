#include <bits/stdc++.h>
using namespace std;

// Longest Increasing Subsequence
class Solution
{
public:
    // This is Top-Down Approach
    int solve(vector<int> &nums, int currIndex, int prevIndex, vector<vector<int>> &dp)
    {

        if (currIndex == nums.size())
            return 0;

        if (prevIndex != -1 && dp[currIndex][prevIndex] != -1)
            return dp[currIndex][prevIndex];
        int include = 0;
        int exclude;
        if (prevIndex == -1 || nums[currIndex] > nums[prevIndex])
            include = 1 + solve(nums, currIndex + 1, currIndex, dp);

        exclude = 0 + solve(nums, currIndex + 1, prevIndex, dp);

        return dp[currIndex][prevIndex + 1] = max(include, exclude);
    }

    // This is Bottom Up Approach
    int solveTab(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int curr = n - 1; curr >= 0; curr--)
        {
            for (int prev = curr - 1; prev >= -1; prev--)
            {
                int include = 0;
                int exclude;

                if (prev == -1 || nums[curr] > nums[prev])
                    include = 1 + dp[curr + 1][curr + 1];

                exclude = 0 + dp[curr + 1][prev + 1];

                dp[curr][prev + 1] = max(include, exclude);
            }
        }
        return dp[0][0];
    }

    // This is Space Optimised Approach
    int solveSO(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> currA(n + 1, 0);
        vector<int> nextA(n + 1, 0);

        for (int curr = n - 1; curr >= 0; curr--)
        {
            for (int prev = curr - 1; prev >= -1; prev--)
            {
                int include = 0;
                int exclude;

                if (prev == -1 || nums[curr] > nums[prev])
                    include = 1 + nextA[curr + 1];

                exclude = 0 + nextA[prev + 1];

                currA[prev + 1] = max(include, exclude);
            }
            nextA = currA;
        }
        return currA[0];
    }

    // This is DP + BINARY SEARCH
    int solveOptimal(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 0)
            return 0;

        vector<int> ans;
        ans.push_back(nums[0]);

        for (int i = 1; i < n; i++)
        {
            if (nums[i] > ans.back())
            {
                ans.push_back(nums[i]);
            }
            else
            {
                // Will get index of element which is jusst Bda then nums[i];
                int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();

                ans[index] = nums[i];
            }
        }
        return ans.size();
    }

    int lengthOfLIS(vector<int> &nums)
    {
        // vector<vector<int> > dp(nums.size()+1,vector<int> (nums.size()+1,-1));
        // int ans = solve(nums, 0,-1,dp);
        // return ans;
        // return solveTab(nums);
        // return solveSO(nums);

        return solveOptimal(nums);
    }
};

int main()
{

    return 0;
}