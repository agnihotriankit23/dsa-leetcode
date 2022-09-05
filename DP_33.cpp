#include <bits/stdc++.h>
using namespace std;

// Edit Distance

class Solution
{
public:
    // This is Top-Down Approach
    int solve(string &a, string &b, int i, int j, vector<vector<int>> &dp)
    {

        if (i == a.size())
        {
            return b.size() - j;
        }
        if (j == b.size())
        {
            return a.size() - i;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;

        if (a[i] == b[j])
        {
            return dp[i][j] = (0 + solve(a, b, i + 1, j + 1, dp));
        }
        else
        {

            // Delete
            int del = 1 + solve(a, b, i + 1, j, dp);

            // Insert
            int ins = 1 + solve(a, b, i, j + 1, dp);

            // Replace
            int rep = 1 + solve(a, b, i + 1, j + 1, dp);

            ans = min(del, min(rep, ins));
        }
        return dp[i][j] = ans;
    }

    // This is Bottom-Up Approach
    int solveTab(string &a, string &b)
    {
        int n = a.size();
        int m = b.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int j = 0; j <= m; j++)
        {
            dp[n][j] = m - j;
        }

        for (int i = 0; i <= n; i++)
        {
            dp[i][m] = n - i;
        }

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (a[i] == b[j])
                {
                    dp[i][j] = 0 + dp[i + 1][j + 1];
                }
                else
                {

                    // Delete
                    int del = 1 + dp[i + 1][j];

                    // Insert
                    int ins = 1 + dp[i][j + 1];

                    // Replace
                    int rep = 1 + dp[i + 1][j + 1];

                    dp[i][j] = min(del, min(ins, rep));
                }
            }
        }
        return dp[0][0];
    }

    // Space Optimised Approach
    int solveSO(string &a, string &b)
    {
        int n = a.size();
        int m = b.size();
        if (n == 0)
            return m;
        if (m == 0)
            return n;
        vector<int> curr(m + 1, 0);
        vector<int> next(m + 1, 0);

        for (int i = 0; i <= m; i++)
        {
            next[i] = m - i;
        }

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {

                curr[m] = n - i; // Important Part

                if (a[i] == b[j])
                {
                    curr[j] = 0 + next[j + 1];
                }
                else
                {

                    // Delete
                    int del = 1 + next[j];

                    // Insert
                    int ins = 1 + curr[j + 1];

                    // Replace
                    int rep = 1 + next[j + 1];

                    curr[j] = min(del, min(ins, rep));
                }
            }
            next = curr;
        }
        return curr[0];
    }

    int minDistance(string word1, string word2)
    {
        // int n = word1.size();
        // int m = word2.size();
        // vector<vector<int> > dp(n+1,vector<int> (m+1,-1));
        // int ans = solve(word1,word2,0,0,dp);
        // return ans;

        // return solveTab(word1,word2);

        return solveSO(word1, word2);
    }
};

int main()
{

    return 0;
}