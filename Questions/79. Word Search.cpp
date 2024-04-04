/*
79. Word Search

Given an m x n grid of characters board and a string word, return true if word exists in the grid.
The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally 
or vertically neighboring. The same letter cell may not be used more than once.

Example 1:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

Example 2:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true

Example 3:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false

Constraints:
m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    bool isPossible(vector<vector<char>>& board,string& word,int len,int i,int j,int m,int n)
    {
        if(len==-1) return true;
        if(i<0 || j<0 || j>=n || i>=m) return false;
        if(word[len]==board[i][j])
        {
            char temp = board[i][j];
            board[i][j] = '#';
            bool chk = isPossible(board,word,len-1,i-1,j,m,n) || 
                       isPossible(board,word,len-1,i+1,j,m,n) || 
                       isPossible(board,word,len-1,i,j-1,m,n) || 
                       isPossible(board,word,len-1,i,j+1,m,n);
            board[i][j] = temp;
            return chk;
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) 
    {
        int m = board.size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(isPossible(board,word,word.length()-1,i,j,m,board[i].size())) return true;
            }
        }
        return false;
    }
};