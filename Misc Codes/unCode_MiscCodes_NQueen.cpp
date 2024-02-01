//Program to solve N-Queen Problem

#include<bits/stdc++.h>
using namespace std;

void printBoard(vector<vector<int>>& board, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

bool canPlace(vector<vector<int>>& board, int row, int col, int N)
{
    for(int i = 0; i < row; i++)
    {
        if(board[i][col] == 1)
            return false;
    }

    //left diagonal
    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if(board[i][j] == 1)
            return false;
    }
    //right diagonal
    for(int i = row, j = col; i >= 0 && j < N; i--, j++)
    {
        if(board[i][j] == 1)
            return false;
    }

    return true;
}

// Print all configurations
void nQueen(vector<vector<int>>& board, int N, int row)
{
    if(row == N)
    {
        printBoard(board, N);
        return;
    }

    for(int col = 0; col < N; col++)
    {
        if(canPlace(board, row, col, N))
        {
            board[row][col] = 1;
            nQueen(board, N, row + 1);
            board[row][col] = 0;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    nQueen(board, n, 0);
    return 0;
}
