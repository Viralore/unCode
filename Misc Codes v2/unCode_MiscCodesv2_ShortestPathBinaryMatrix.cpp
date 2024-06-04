//Program for finding the shortest path in Binary Matrix

#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> directions = 
{
    {-1, 0}, {1, 0}, {0, -1}, {0, 1},
    {-1, -1}, {-1, 1}, {1, -1}, {1, 1}
};

bool isValid(int x, int y, int n, vector<vector<int>>& grid) 
{
    return x >= 0 && y >= 0 && x < n && y < n && grid[x][y] == 0;
}

int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
{
    int n = grid.size();
    
    if (grid[0][0] == 1 || grid[n-1][n-1] == 1) 
    {
        return -1;
    }

    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    grid[0][0] = 1;

    int pathLength = 1;
    
    while (!q.empty()) 
    {
        int size = q.size();
        for (int i = 0; i < size; ++i)
        {
            pair<int, int> current = q.front();
            q.pop();
            int x = current.first;
            int y = current.second;
            
            if (x == n-1 && y == n-1) 
            {
                return pathLength;
            }
            
            for (int j = 0; j < directions.size(); ++j) 
            {
                int newX = x + directions[j].first;
                int newY = y + directions[j].second;
                
                if (isValid(newX, newY, n, grid)) 
                {
                    q.push(make_pair(newX, newY));
                    grid[newX][newY] = 1;
                }
            }
        }
        ++pathLength;
    }
    
    return -1;
}

int main() 
{
    vector<vector<int>> grid = { {0, 1, 0, 0, 0},
                                 {0, 1, 0, 1, 0},
                                 {0, 0, 0, 1, 0},
                                 {0, 1, 1, 1, 0},
                                 {0, 0, 0, 0, 0} };
    
    int result = shortestPathBinaryMatrix(grid);
    if (result != -1) 
    {
        cout << "The shortest path length is: " << result << endl;
    } 
    else 
    {
        cout << "There is no valid path." << endl;
    }
    return 0;
}
