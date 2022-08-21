#include <bits/stdc++.h>
using namespace std;
// MiniMum cost of tickets
class Solution
{
public:
    int solve(int index, vector<int> &days, vector<int> &costs, vector<int> &dp)
    {
        if (index >= days.size())
            return 0;

        if (dp[index] != -1)
            return dp[index];

        int i;
        // To buy 1 day Pass
        int opt1 = costs[0] + solve(index + 1, days, costs, dp);

        // To buy 7 days pass
        for (i = index; i < days.size() && days[i] < days[index] + 7; i++)
            ;

        int op2 = costs[1] + solve(i, days, costs, dp);

        // To buy 30 days Pass

        for (i = index; i < days.size() && days[i] < days[index] + 30; i++)
            ;

        int op3 = costs[2] + solve(i, days, costs, dp);

        int ans = min(opt1, min(op2, op3));

        dp[index] = ans;

        return ans;
    }
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {

        vector<int> dp(days.size() + 1, -1);

        // dp[0]=0;

        int ans = solve(0, days, costs, dp);
        return ans;
    }
};

int main()
{

    return 0;
}