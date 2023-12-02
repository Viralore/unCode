//Program for unbounded knapsack
//using recursion

/*
    The Unbounded Knapsack Problem involves selecting items with specific weights and values to maximize the total value, allowing for
    the unlimited repetition of each item. Unlike the 0/1 Knapsack where items are either included or excluded entirely, in the Unbounded
    Knapsack, an item can be chosen multiple times. The goal is to find the optimal combination of items that fits within the knapsack's
    weight capacity, maximizing the total value. This problem is commonly solved using dynamic programming, and its applications range from
    resource allocation to cutting stock problems where items can be divided into fractions for efficiency.
*/

#include<bits/stdc++.h>
using namespace std;

//function to calculate max profit
//in this we take item from last and then check for maximum value
int unboundedKnapsack(int value[],int weight[],int W,int N)
{
    if(N==0 || W==0) return 0;
    if(weight[N-1]>W)
    {
        return unboundedKnapsack(value,weight,W,N-1);
    }
    else return max((value[N-1]+ unboundedKnapsack(value,weight,W-weight[N-1],N)),unboundedKnapsack(value,weight,W,N-1));
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

    cout<<"Maximum value you can get is : "<<unboundedKnapsack(value,weight,W,N);
    return 0;
}
