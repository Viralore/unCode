// Program to find the nth Fibonacci number using recursion

#include <bits/stdc++.h>
using namespace std;

int fibonacci(int n)
{
    if (n <= 1)
    {
        return n;                                   // Base case: return n for 0 and 1
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2); // Recursion to find the nth Fibonacci number
    }
}

int main()
{
    int n;
    cout << "Enter the value of n: "; // Input: Value of n
    cin >> n;

    cout << "The " << n << "th Fibonacci number is: " << fibonacci(n) << endl; // Output: nth Fibonacci number

    return 0;
}
