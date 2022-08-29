#include <bits/stdc++.h>
using namespace std;

// MAXIMUM HIEGHT BY STACKING CUBOID
class Solution
{
public:
    bool check(vector<int> base, vector<int> newBox)
    {
        if (newBox[0] <= base[0] && newBox[1] <= base[1] && newBox[2] <= base[2])
        {
            return true;
        }
        else
            return false;
    }
    int LIS(vector<vector<int>> &a)
    {
        int n = a.size();

        vector<int> currA(n + 1, 0);
        vector<int> nextA(n + 1, 0);

        for (int curr = n - 1; curr >= 0; curr--)
        {
            for (int prev = curr - 1; prev >= -1; prev--)
            {
                int include = 0;
                int exclude;

                if (prev == -1 || check(a[curr], a[prev]))
                    include = a[curr][2] + nextA[curr + 1];

                exclude = 0 + nextA[prev + 1];

                currA[prev + 1] = max(include, exclude);
            }
            nextA = currA;
        }
        return currA[0];
    }

    int maxHeight(vector<vector<int>> &cuboids)
    {

        for (auto &row : cuboids)
        {
            sort(row.begin(), row.end());
        }

        sort(cuboids.begin(), cuboids.end());

        int ans = LIS(cuboids);
        return ans;
    }
};

int main()
{

    return 0;
}