#include <bits/stdc++.h>
using namespace std;

// Minimum Sideway Jumps
class Solution
{
public:
    // This is Top-Down Approach
    int solve(vector<int> &obstacles, int currLane, int currPos, vector<vector<int>> &dp)
    {
        int n = obstacles.size();
        if (currPos == n - 1)
            return 0; // Target p pahuch gyee

        if (dp[currLane][currPos] != -1)
            return dp[currLane][currPos];
        if (obstacles[currPos + 1] != currLane)
        { // Sidha Sidha chlo
            return dp[currLane][currPos] = solve(obstacles, currLane, currPos + 1, dp);
        }

        int ans = INT_MAX;
        for (int i = 1; i <= 3; i++)
        {
            if (obstacles[currPos] != i && currLane != i)
            { // Shi jump loo
                ans = min(ans, 1 + solve(obstacles, i, currPos + 1, dp));
            }
        }
        return dp[currLane][currPos] = ans;
    }
    // This is Bottom-Up Approach
    int solveTab(vector<int> &obstacles)
    {

        int n = obstacles.size() - 1;
        vector<vector<int>> dp(4, vector<int>(n + 1, 1e9));

        dp[0][n] = 0;
        dp[1][n] = 0;
        dp[2][n] = 0;
        dp[3][n] = 0;

        for (int currPos = n - 1; currPos >= 0; currPos--)
        {
            for (int currLane = 1; currLane <= 3; currLane++)
            {

                if (obstacles[currPos + 1] != currLane)
                {
                    dp[currLane][currPos] = dp[currLane][currPos + 1];
                }
                else
                {
                    int ans = 1e9;
                    for (int i = 1; i <= 3; i++)
                    {
                        if (currLane != i && obstacles[currPos] != i)
                        {
                            ans = min(ans, 1 + dp[i][currPos + 1]); // YHA currPos ki jgah currPos+1 use kiya hai.
                        }
                        dp[currLane][currPos] = ans;
                    }
                }
            }
        }
        return (min(dp[2][0], min(1 + dp[1][0], 1 + dp[3][0])));
    }
    int solveSO(vector<int> &obstacles)
    {
        int n = obstacles.size() - 1;

        vector<int> curr(4, 1e9);
        vector<int> next(4, 0);

        for (int currPos = n - 1; currPos >= 0; currPos--)
        {
            for (int currLane = 1; currLane <= 3; currLane++)
            {
                if (obstacles[currPos + 1] != currLane)
                {
                    curr[currLane] = next[currLane];
                }
                else
                {
                    int ans = 1e9;
                    for (int i = 1; i <= 3; i++)
                    {
                        if (obstacles[currPos] != i && currLane != i)
                        {
                            ans = min(ans, 1 + next[i]);
                        }
                    }
                    curr[currLane] = ans;
                }
            }
            next = curr;
        }
        return min(curr[2], min(1 + curr[1], 1 + curr[3]));
    }
    int minSideJumps(vector<int> &obstacles)
    {
        // vector<vector<int> > dp(4,vector<int> (obstacles.size(),-1));
        // int ans = solve(obstacles,2,0,dp);
        // return ans;
        // return solveTab(obstacles);
        return solveSO(obstacles);
    }
};

int main()
{

    return 0;
}