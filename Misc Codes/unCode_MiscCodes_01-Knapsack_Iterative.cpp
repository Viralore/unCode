//0/1 Knapsack Problem
//without using recursion

#include<bits/stdc++.h>
using namespace std;

// Function to solve the 0/1 Knapsack Problem iteratively
int knapsack(int weights[], int values[], int capacity, int n)
{
    // Initialize a 2D vector to store results of subproblems
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Iterate over each item
    for (int i = 1; i <= n; ++i)
    {
        // Iterate over each capacity value
        for (int w = 0; w <= capacity; ++w)
        {
            // If the current item can be included in the knapsack
            if (weights[i - 1] <= w)
            {
                // Choose the maximum value between including and excluding the current item
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            }
            else
            {
                // If the current item's weight is greater than the capacity, exclude it
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    // The result is stored in the bottom-right cell of the dp table
    return dp[n][capacity];
}

int main()
{
    int N,W;
    cout<<"Enter the number of Items : ";
    cin>>N;
    int value[N],weight[N];
    cout<<"Now enter the weights of the items"<<endl;
    for(int i=0;i<N;i++) cin>>weight[i];

    cout<<"Now enter the value of item corresponding to the weights"<<endl;
    for(int i=0;i<N;i++)
    {
        cout<<"Weight : "<<weight[i]<<" : ";
        cin>>value[i];
    }

    cout<<"Enter the maximum capacity of Knapsack : ";
    cin>>W;

    cout<<"Maximum value you can get is : "<<knapsack(weight,value,W,N);
    return 0;
}
