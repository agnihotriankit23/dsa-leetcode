#include <bits/stdc++.h>
using namespace std;

// Longest Arithmetic SUbSequence
class Solution
{
public:
    // Top-Down Will give TLE
    int solve(int index, int diff, vector<int> &nums, unordered_map<int, int> dp[])
    {
        if (index < 0)
            return 0;
        if (dp[index].count(diff))
            return dp[index][diff];
        int ans = 0;

        for (int j = index - 1; j >= 0; j--)
        {
            if (nums[index] - nums[j] == diff)
            {
                ans = max(ans, 1 + solve(j, diff, nums, dp));
            }
        }
        return dp[index][diff] = ans;
    }

    // Bottom-Up solution
    int solveTab(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> dp[n + 1];
        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                int diff = nums[i] - nums[j];
                int cnt = 1;

                if (dp[j].count(diff))
                    cnt = dp[j][diff];

                dp[i][diff] = 1 + cnt;
                ans = max(ans, dp[i][diff]);
            }
        }
        return ans;
    }

    int longestArithSeqLength(vector<int> &nums)
    {
        if (nums.size() <= 2)
            return nums.size();

        return solveTab(nums);

        //         int ans=0;
        //         int n= nums.size();

        //         unordered_map<int,int> dp[n+1];

        //         for(int i=0;i<nums.size()-1;i++){
        //             for(int j=i+1;j<nums.size();j++){

        //                 ans = max(ans, 2 + solve(i,nums[j]-nums[i],nums,dp));
        //             }
        //         }

        //         return ans;
    }
};

int main()
{

    return 0;
}