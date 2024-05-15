//Program for Perfect Squares: Finding the least number of perfect square numbers which sum up to a given number using BFS with a queue.

#include <bits/stdc++.h>
using namespace std;

int numSquares(int n) 
{
    queue<pair<int, int>> bfsQueue;
    bfsQueue.push({n, 0});

    unordered_set<int> visited;

    while (!bfsQueue.empty()) 
    {
        int num = bfsQueue.front().first;
        int level = bfsQueue.front().second;
        bfsQueue.pop();

        int sqrtNum = sqrt(num);
        if (sqrtNum * sqrtNum == num) 
        {
            return level + 1;
        }

        for (int i = 1; i * i <= num; i++) 
        {
            int nextNum = num - i * i;
            if (visited.find(nextNum) == visited.end()) 
            {
                bfsQueue.push({nextNum, level + 1}); 
                visited.insert(nextNum);
            }
        }
    }

    return -1;
}

int main() 
{
    int n = 12;
    int result = numSquares(n);
    cout << "The least number of perfect square numbers which sum up to " << n << " is: " << result << endl;
    return 0;
}
