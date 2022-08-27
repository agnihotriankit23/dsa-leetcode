#include <bits/stdc++.h>
using namespace std;

// Russian Doll Envelopes
class Solution
{
public:
    bool static comp(vector<int> &a, vector<int> &b)
    {
        if (a[0] == b[0])
        {
            return a[1] > b[1];
        }
        else
        {
            return a[0] < b[0];
        }
    }
    int solve(vector<int> &LIS)
    {
        int n = LIS.size();
        if (n == 0)
            return 0;

        vector<int> ans;
        ans.push_back(LIS[0]);
        for (int i = 1; i < n; i++)
        {
            if (LIS[i] > ans.back())
            {
                ans.push_back(LIS[i]);
            }
            else
            {
                int index = lower_bound(ans.begin(), ans.end(), LIS[i]) - ans.begin();
                ans[index] = LIS[i];
            }
        }
        // for(int i=0;i<ans.size();i++){
        //     cout<<ans[i]<<" ";
        // }cout<<endl;
        return ans.size();
    }
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        sort(envelopes.begin(), envelopes.end(), comp);

        int n = envelopes.size();

        for (int i = 0; i < n - 1; i++)
        {
            if (envelopes[i][0] == envelopes[i + 1][0])
            {
                if (envelopes[i][1] < envelopes[i + 1][1])
                {
                    swap(envelopes[i][1], envelopes[i + 1][1]);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << envelopes[i][0] << " " << envelopes[i][1] << endl;
        }

        vector<int> LIS;
        for (int i = 0; i < n; i++)
        {

            LIS.push_back(envelopes[i][1]);
        }
        return solve(LIS);
    }
};

int main()
{

    return 0;
}