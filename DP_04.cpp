#include <bits/stdc++.h>
using namespace std;
// CUT ROD INTO SEGMENTS
int solve(int n, int x, int y, int z, vector<int> &dp)
{
    if (n == 0)
        return 0;
    if (n < 0)
        return INT_MIN;
    if (dp[n] != -1)
        return dp[n];
    int a, b, c;

    a = solve(n - x, x, y, z, dp) + 1;

    b = solve(n - y, x, y, z, dp) + 1;

    c = solve(n - z, x, y, z, dp) + 1;

    dp[n] = max(a, max(b, c));
    return dp[n];
}
int cutSegments(int n, int x, int y, int z)
{
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    int ans = solve(n, x, y, z, dp);
    if (ans < 0)
        return 0;
    return ans;
}

int main()
{

    return 0;
}