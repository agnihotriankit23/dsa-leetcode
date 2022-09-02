#include <bits/stdc++.h>
using namespace std;

// Minimum Swaps To Make Sequences Increasing

class Solution
{
public:
    // Top- Down Approach
    int solve(int index, bool swapped, vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &dp)
    {
        if (index >= nums1.size())
            return 0;

        if (dp[index][swapped] != -1)
            return dp[index][swapped];

        int prev1 = nums1[index - 1];
        int prev2 = nums2[index - 1];

        if (swapped)
            swap(prev1, prev2);

        int ans = INT_MAX;

        // No Swap Case
        if (nums1[index] > prev1 && nums2[index] > prev2)
        {
            ans = solve(index + 1, 0, nums1, nums2, dp);
        }

        // swap Case

        if (nums1[index] > prev2 && nums2[index] > prev1)
        {
            ans = min(ans, 1 + solve(index + 1, 1, nums1, nums2, dp));
        }
        return dp[index][swapped] = ans;
    }

    // This is Bottom-Up Approach
    int solveTab(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        bool swapped = 0;
        vector<vector<int>> dp(n + 1, vector<int>(3, 0));

        for (int index = n; index >= 1; index--)
        {
            for (int swapped = 1; swapped >= 0; swapped--)
            {

                int prev1 = nums1[index - 1];
                int prev2 = nums2[index - 1];

                if (swapped)
                    swap(prev1, prev2);

                int ans = INT_MAX;

                // No Swap Case
                if (nums1[index] > prev1 && nums2[index] > prev2)
                {
                    ans = solve(index + 1, 0, nums1, nums2, dp);
                }

                // swap Case

                if (nums1[index] > prev2 && nums2[index] > prev1)
                {
                    ans = min(ans, 1 + solve(index + 1, 1, nums1, nums2, dp));
                }
                dp[index][swapped] = ans;
            }
        }
        return dp[1][0];
    }

    // Space Optimised Approach
    int solveSO(vector<int> &nums1, vector<int> &nums2)
    {

        int n = nums1.size();

        vector<int> curr(2, 0);
        vector<int> next(2, 0);
        cout << next[0] << " " << next[1] << endl;

        for (int index = n - 1; index >= 1; index--)
        {
            for (int swapped = 1; swapped >= 0; swapped--)
            {

                int prev1 = nums1[index - 1];
                int prev2 = nums2[index - 1];

                if (swapped)
                    swap(prev1, prev2);

                int ans = INT_MAX;

                // No Swap Case
                if (nums1[index] > prev1 && nums2[index] > prev2)
                {
                    ans = next[0];
                }

                // swap Case

                if (nums1[index] > prev2 && nums2[index] > prev1)
                {

                    ans = min(ans, next[1] + 1);
                }
                curr[swapped] = ans;
            }
            next = curr;
        }

        return curr[0];
    }
    int minSwap(vector<int> &nums1, vector<int> &nums2)
    {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        // int n = nums1.size();
        // bool swapped = 0;
        // vector<vector<int> > dp(n+1,vector<int> (3,-1));
        // return solve(1,swapped,nums1,nums2,dp);

        // eturn solveTab(nums1,nums2);
        return solveSO(nums1, nums2);
    }
};

int main()
{

    return 0;
}