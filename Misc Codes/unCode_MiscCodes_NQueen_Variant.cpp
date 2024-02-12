//Program for solving N-Queen Problem variant
//Output -> all the possible solutions are printed according to the position of queens
/*
    Example :
    N = 4
    Output : [1, 3, 0, 2]
             [2, 0, 3, 1]
*/

#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<int>& board, int row, int col)
{
    for (int i = 0; i < row; ++i)
    {
        if (board[i] == col || board[i] - i == col - row || board[i] + i == col + row)
        {
            return false;
        }
    }
    return true;
}

void backtrack(vector<vector<int>>& solutions, vector<int>& board, int row, int n)
{
    if (row == n)
    {
        solutions.push_back(board);
        return;
    }
    for (int col = 0; col < n; ++col)
    {
        if (isSafe(board, row, col))
        {
            board[row] = col;
            backtrack(solutions, board, row + 1, n);
            board[row] = -1;
        }
    }
}

vector<vector<int>> solveAllQueens(int n)
{
    vector<vector<int>> solutions;
    vector<int> board(n, -1);
    backtrack(solutions, board, 0, n);
    return solutions;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> output = solveAllQueens(n);
    for (auto& solution : output)
    {
        cout << "[";
        for (int i = 0; i < n; ++i)
        {
            cout << solution[i];
            if (i != n - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    return 0;
}
