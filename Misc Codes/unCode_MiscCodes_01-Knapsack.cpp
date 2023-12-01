//Program for 0/1 Knapsack Problem
//using Recursion

/*
    The 0/1 Knapsack Problem is a classic optimization challenge where items with specific weights and values must be selected to maximize the
    total value within a knapsack's weight capacity. The term "0/1" signifies that an item can either be included or excluded entirely,
    without fractional selection. The objective is to determine the optimal combination of items that fits within the weight constraint,
    ensuring the highest possible total value. This problem is NP-hard, and dynamic programming techniques are commonly employed to efficiently
    find the optimal solution, making it a fundamental problem in algorithmic optimization and computer science.
*/

#include<bits/stdc++.h>
using namespace std;

//function to calculate max profit
//in this we take item from last and then check for maximum value
int knapsack(int value[],int weight[],int W,int N)
{
    if(N==0 || W==0) return 0;                      //base condition if Number of items left is zero or capacity of knapsack is 0
    if(weight[N-1]>W)                               //if weight of any item is greater than knapsack capacity then ignore that item
    {
        return knapsack(value, weight, W, N-1);
    }
    else return max((value[N-1] + knapsack(value, weight, W-weight[N-1], N-1)), knapsack(value, weight, W, N-1)); //otherwise return maximum of when last item is selected and without selecting that item
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

    cout<<"Maximum value you can get is : "<<knapsack(value,weight,W,N);
    return 0;
}
