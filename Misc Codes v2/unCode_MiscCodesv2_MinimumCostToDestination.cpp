//Program to find Minimum Cost to reach to the Destination using queue.
#include <bits/stdc++.h>
using namespace std;


struct Cell 
{
    int x, y, cost;
    bool operator>(const Cell& other) const 
    {
        return cost > other.cost;
    }
};

bool isValid(int x, int y, int rows, int cols) 
{
    return x >= 0 && x < rows && y >= 0 && y < cols;
}

int minCostToReachDestination(vector<vector<int>>& grid) 
{
    int rows = grid.size();
    if (rows == 0) return -1;
    int cols = grid[0].size();

    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    priority_queue<Cell, vector<Cell>, greater<Cell>> pq;
    pq.push({0, 0, grid[0][0]});
    
    vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
    dist[0][0] = grid[0][0];
    
    while (!pq.empty()) 
    {
        Cell current = pq.top();
        pq.pop();
        
        int x = current.x;
        int y = current.y;
        int cost = current.cost;
        
        if (x == rows - 1 && y == cols - 1) 
        {
            return cost;
        }
        
        for (const auto& direction : directions) 
        {
            int nx = x + direction.first;
            int ny = y + direction.second;
            
            if (isValid(nx, ny, rows, cols)) 
            {
                int newCost = cost + grid[nx][ny];
                if (newCost < dist[nx][ny]) 
                {
                    dist[nx][ny] = newCost;
                    pq.push({nx, ny, newCost});
                }
            }
        }
    }
    
    return -1;
}

int main() 
{
    vector<vector<int>> grid = { {1, 3, 1, 2},
                                 {1, 5, 1, 3},
                                 {4, 2, 1, 4},
                                 {2, 1, 5, 3} };

    int result = minCostToReachDestination(grid);
    if (result != -1) 
    {
        cout << "Minimum cost to reach destination is: " << result << endl;
    } 
    else 
    {
        cout << "Destination cannot be reached." << endl;
    }
    return 0;
}
