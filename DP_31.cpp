#include <bits/stdc++.h>
using namespace std;

// Longest Common Subsequence
class Solution
{
public:
    // This is Top-Down Approach
    int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
    {

        if (i >= s1.size() || j >= s2.size())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s1[i] == s2[j])
            return dp[i][j] = (1 + solve(i + 1, j + 1, s1, s2, dp));
        else
            return dp[i][j] = max(solve(i, j + 1, s1, s2, dp), solve(i + 1, j, s1, s2, dp));
    }

    // This is Bottom-Up Approach
    int solveTAB(string s1, string s2)
    {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (s1[i] == s2[j])
                    dp[i][j] = (1 + dp[i + 1][j + 1]);
                else
                    dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
        return dp[0][0];
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        // int n=text1.size();
        // int m = text2.size();
        // vector<vector<int> > dp(n,vector<int> (m,-1));
        //   int ans = solve(0,0,text1,text2,dp);
        // return ans;

        return solveTAB(text1, text2);
    }
};

int main()
{

    return 0;
}