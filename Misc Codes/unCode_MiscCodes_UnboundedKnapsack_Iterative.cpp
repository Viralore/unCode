//Unbounded Knapsack Problem
//without using recursion

#include<bits/stdc++.h>
using namespace std;

// Function to solve the Unbounded Knapsack Problem iteratively
int unboundedKnapsack(int weights[], int values[], int capacity, int n)
{
    // Initialize a vector 'dp' to store the maximum value for each capacity value
    vector<int> dp(capacity + 1, 0);

    // Iterate over each item
    for (int i = 0; i < n; ++i)
    {
        // Iterate over each capacity value
        for (int w = weights[i]; w <= capacity; ++w)
        {
            // Update the maximum value at the current capacity considering the current item
            dp[w] = max(dp[w], values[i] + dp[w - weights[i]]);
        }
    }
    // The result is stored in the last element of the dp array
    return dp[capacity];
}

int main()
{
    int N,Capacity;
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
    cin>>Capacity;

    cout<<"Maximum value you can get is : "<<unboundedKnapsack(weight,value,Capacity,N);
    return 0;
}
