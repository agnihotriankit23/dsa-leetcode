#include <bits/stdc++.h>
using namespace std;

// COUNT DERANGEMENTS
#include <bits/stdc++.h>
#define MOD 1000000007
long long int solve(int n, vector<long long int> &dp)
{
    if (n == 1 || n == 0)
        return 0;
    if (n == 2)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    int ans = ((n - 1) % MOD) * ((solve(n - 1, dp) % MOD) + ((solve(n - 2, dp) % MOD))) % MOD;
    dp[n] = ans;
    return dp[n];
}
long long int countDerangements(int n)
{

    vector<long long int> dp(n + 1, -1);
    dp[1] = 0;
    dp[2] = 1;
    return solve(n, dp);
    // return ans;
}

int main()
{

    return 0;
}