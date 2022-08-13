#include <bits/stdc++.h>
using namespace std;

// SUDOKU PROBLEM
// TC- O(9^m)
// SC - O(1)
class Solution
{
public:
    bool isSafe(int row, int col, vector<vector<char>> &board, char value)
    {
        for (int i = 0; i < 9; i++)
        {
            // row check
            if (board[row][i] == value)
            {
                return false;
            }
            // col check
            if (board[i][col] == value)
            {
                return false;
            }

            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == value)
            {
                return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>> &board)
    {
        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++)
            {
                if (board[row][col] == '.')
                {
                    for (char ch = 49; ch <= 57; ch++)
                    {
                        if (isSafe(row, col, board, ch))
                        {
                            board[row][col] = ch;
                            bool flag = solve(board);
                            if (flag)
                            {
                                return true;
                            }
                            else
                                board[row][col] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board);
    }
};

int main()
{

    return 0;
}