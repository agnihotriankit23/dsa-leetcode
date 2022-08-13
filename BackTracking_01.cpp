#include <bits/stdc++.h>
using namespace std; 


// Rat in a Maze
// TC - O(4^(n^2)) SC- O(n*m)
class Solution
{
public:
    bool isSafe(vector<vector<int>> &visited, int x, int y, int n, vector<vector<int>> &m)
    {
        if ((x >= 0 && x < n) && (y >= 0 && y < n) && (m[x][y] == 1) && visited[x][y] != 1)
            return true;
        else
            return false;
    }
    void solve(vector<string> &ans, vector<vector<int>> &visited, int x, int y, string path, vector<vector<int>> &m, int n)
    {
        if (x == n - 1 && y == n - 1)
        {
            ans.push_back(path);
            return;
        }
        visited[x][y] = 1;

        // For Down
        int xnew = x + 1;
        int ynew = y;
        if (isSafe(visited, xnew, ynew, n, m))
        {
            path.push_back('D');

            solve(ans, visited, xnew, ynew, path, m, n);
            path.pop_back();
        }

        // For Left
        xnew = x;
        ynew = y - 1;
        if (isSafe(visited, xnew, ynew, n, m))
        {
            path.push_back('L');

            solve(ans, visited, xnew, ynew, path, m, n);
            path.pop_back();
        }

        // For Right
        xnew = x;
        ynew = y + 1;
        if (isSafe(visited, xnew, ynew, n, m))
        {
            path.push_back('R');

            solve(ans, visited, xnew, ynew, path, m, n);
            path.pop_back();
        }

        // For Up

        xnew = x - 1;
        ynew = y;
        if (isSafe(visited, xnew, ynew, n, m))
        {
            path.push_back('U');

            solve(ans, visited, xnew, ynew, path, m, n);
            path.pop_back();
        }

        visited[x][y] = 0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        // Your code goes here
        vector<vector<int>> visited(n, vector<int>(n, 0));
        // visited[0][0]=1;
        string path = "";
        vector<string> ans;
        if (m[0][0] == 0)
        {
            return ans;
        }
        solve(ans, visited, 0, 0, path, m, n);
        return ans;
    }
};

int main(){
     

    return 0;
}