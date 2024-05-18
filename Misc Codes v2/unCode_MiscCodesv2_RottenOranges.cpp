//Program to solve the problem Rotting Oranges

#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) 
{
    int rows = grid.size();
    if (rows == 0) return -1;
    int cols = grid[0].size();

    queue<pair<int, int>> rotten;
    int freshCount = 0;

    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            if (grid[i][j] == 2) 
            {
                rotten.push({i, j});
            } 
            else if (grid[i][j] == 1) 
            {
                freshCount++;
            }
        }
    }

    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int time = 0;

    while (!rotten.empty() && freshCount > 0) 
    {
        int size = rotten.size();
        for (int i = 0; i < size; i++) {
            pair<int, int> pos = rotten.front();
            int x = pos.first;
            int y = pos.second;
            rotten.pop();
            for (const auto& direction : directions) 
            {
                int dx = direction.first;
                int dy = direction.second;
                int nx = x + dx;
                int ny = y + dy;
                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] == 1) 
                {
                    grid[nx][ny] = 2;
                    freshCount--;
                    rotten.push({nx, ny});
                }
            }
        }
        time++;
    }

    return freshCount == 0 ? time : -1;
}

int main() 
{
    vector<vector<int>> grid = { {2, 1, 1},
                                 {1, 1, 0},
                                 {0, 1, 1} };

    int result = orangesRotting(grid);

    if (result == -1) 
    {
        cout << "All oranges cannot be rotten." << endl;
    } 
    else 
    {
        cout << "Minimum time required to rot all oranges is: " << result << " units." << endl;
    }
    return 0;
}
