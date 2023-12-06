//Coin Change Problem
//using recursion

/*
    Description :-
    The Coin Change Problem is a classic dynamic programming problem focused on determining the number of ways to make change for a
    given target amount using a given set of coin denominations. The objective is to find the total number of combinations to make
    the target amount using various coins, considering unlimited quantities of each coin. This problem is commonly solved using
    dynamic programming techniques, where a 2D array is utilized to store and update the number of ways to make change for varying
    sub-amounts. The Coin Change Problem has applications in currency systems, vending machines, and optimization scenarios involving
    resource allocation.
*/

#include<bits/stdc++.h>
using namespace std;

// Recursive function to solve the Coin Change Problem
// Returns the total number of ways to make change for 'Sum' using coins of 'money[]'
// 'N' is the number of different coin denominations available
int coinChangeProblem(int money[],int N,int Sum)
{
    if(Sum==0) return 1;//If the target sum 'Sum' is 0, there is one way (no change)

    if(N==0) return 0;//If there are no coin denominations left, and 'Sum' is not 0, there is no way

    // If the current coin denomination 'money[N-1]' is greater than the target sum 'Sum',
    // exclude the current coin and consider the remaining denominations
    if(Sum<money[N-1]) return coinChangeProblem(money,N-1,Sum);

    // Summing the total ways by considering two possibilities:
    // 1. Include the current coin denomination and reduce the target sum  by the coin value
    // 2. Exclude the current coin denomination and consider the remaining denominations
    return (coinChangeProblem(money,N,Sum-money[N-1]) + coinChangeProblem(money,N-1,Sum));
}

int main()
{
    int N,sum;
    cout<<"Enter the number of coin denominations : ";
    cin>>N;
    int money[N];
    cout<<"Now enter the denominations"<<endl;
    for(int i=0;i<N;i++) cin>>money[i];

    cout<<"Enter the sum to check for total ways : ";
    cin>>sum;

    int num = coinChangeProblem(money,N,sum);
    if(num!=0) cout<<"Total number of ways to get the given sum '"<<sum<<"' are : "<<num<<endl;
    else cout<<"There is not a single way to get the given sum '"<<sum<<"' from the given denominations"<<endl;
    return 0;
}
