//Program for Generating binary numbers from 1 to N using a queue.

#include <bits/stdc++.h>
using namespace std;

void generateBinaryNumbers(int n) 
{
    queue<string> q;
    q.push("1");
    for (int i = 1; i <= n; i++) 
    {
        string binary = q.front();
        q.pop();
        cout << binary << endl;
        q.push(binary + "0");
        q.push(binary + "1");
    }
}

int main() 
{
    int n;
    cin >> n;
    cout << "Binary numbers from 1 to " << n << " are:" << endl;
    generateBinaryNumbers(n);
    return 0;
}
