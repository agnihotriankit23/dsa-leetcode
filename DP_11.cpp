#include <bits/stdc++.h>
using namespace std;

// Maximal Square 2D DP
class Solution
{
public:
    // This is TOP-DOWN approach S.C-> O(m*n)
    int solve(vector<vector<char>> &matrix, int i, int j, int &maxi, vector<vector<int>> &dp)
    {
        if (i >= matrix.size() || j >= matrix[0].size())
        {
            return 0;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        int right = solve(matrix, i, j + 1, maxi, dp);
        int down = solve(matrix, i + 1, j, maxi, dp);
        int diag = solve(matrix, i + 1, j + 1, maxi, dp);

        if (matrix[i][j] == '1')
        {
            dp[i][j] = 1 + min(right, min(down, diag));
            maxi = max(maxi, dp[i][j]);
            return dp[i][j];
        }
        else
        {
            return dp[i][j] = 0;
        }
    }
    // This is BOTTOM-UP Approach S.C-> O(m*n)
    int solveTab(vector<vector<char>> &matrix, int &maxi)
    {
        // int maxi =0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                int right = dp[i][j + 1];
                int down = dp[i + 1][j];
                int diag = dp[i + 1][j + 1];

                if (matrix[i][j] == '1')
                {
                    dp[i][j] = 1 + min(right, min(down, diag));
                    maxi = max(maxi, dp[i][j]);
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }

        return dp[0][0];
    }
    int solveSO(vector<vector<char>> &matrix, int &maxi)
    {
        // int maxi =0;
        int n = matrix.size();
        int m = matrix[0].size();
        // vector<vector<int> > dp(n+1,vector<int> (m+1,0));
        vector<int> curr(m + 1, 0);
        vector<int> next(m + 1, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                int right = curr[j + 1];
                int down = next[j];
                int diag = next[j + 1];

                if (matrix[i][j] == '1')
                {
                    curr[j] = 1 + min(right, min(down, diag));
                    maxi = max(maxi, curr[j]);
                }
                else
                {
                    curr[j] = 0;
                }
            }
            next = curr;
        }

        return curr[0];
    }
    // This is more Space Optimised Code S.C-> O(m)
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int maxi = 0;
        //         int n = matrix.size();
        //         int m = matrix[0].size();
        //         vector<vector<int> > dp(n, vector<int> (m,-1));

        //         solve(matrix,0,0,maxi,dp);

        // int ans  = solveTab(matrix,maxi);
        int ans = solveSO(matrix, maxi);
        return maxi * maxi;
    }
};

int main()
{

    return 0;
}