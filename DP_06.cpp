#include <bits/stdc++.h>
using namespace std;

// PAINTING FENCE ALGORITHM
#define MOD 1000000007
int add(int a, int b)
{
    return ((a % MOD) + (b % MOD)) % MOD;
}
int multiply(int a, int b)
{
    return ((a % MOD) * 1LL * (b % MOD)) % MOD;
}
int solve(int n, int k, vector<int> &dp)
{

    if (n == 1)
        return k;
    if (n == 2)
        return add(k, multiply(k, k - 1));

    if (dp[n] != -1)
        return dp[n];
    // DIFFERENT + SAME
    int a = solve(n - 1, k, dp);
    int diff = multiply(a, (k - 1));
    int b = solve(n - 2, k, dp);
    int same = multiply(b, (k - 1));

    dp[n] = add(diff, same);
    return dp[n];
}
int numberOfWays(int n, int k)
{
    vector<int> dp(n + 1, -1);

    int ans = solve(n, k, dp);
    return ans;
}

int main()
{

    return 0;
}