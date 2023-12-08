//Rod Cutting Problem
//using Recursion

/*
    Description :-
    The Rod Cutting Problem involves maximizing the total value obtained by strategically cutting a rod with associated
    values for each length. The objective is to find the optimal combination of cuts to achieve the highest total value
    without exceeding the original rod length. This classic dynamic programming problem has applications in various industries,
    such as resource allocation and stock cutting, illustrating the principles of optimization through sequential decision-making.
    The challenge lies in determining the lengths of the cut pieces to achieve the maximum value, making the Rod Cutting Problem a
    fundamental example in algorithmic problem-solving.
*/

#include<bits/stdc++.h>
using namespace std;

// Returns the maximum value obtainable by cutting the rod with lengths 'lengths[]'
// and corresponding values 'value[]' such that the total length doesn't exceed 'maxLength'
// 'N' is the number of available lengths and values
int rodCuttingProblem(int value[],int lengths[],int maxLength,int N)
{
    if(N==0 || maxLength==0) return 0;//If there are no available lengths or the maximum length is 0, the value is 0

    // If the current rod length 'lengths[N-1]' is greater than the maximum length 'maxLength',
    // exclude the current length and consider the remaining lengths
    if(lengths[N-1]>maxLength)
    {
        return rodCuttingProblem(value,lengths,maxLength,N-1);
    }

    // Maximize the value by either:
    // 1. Including the current rod length 'lengths[N-1]' and recursively solving for the remaining length
    // 2. Excluding the current rod length and considering the remaining lengths
    else return max((value[N-1]+ rodCuttingProblem(value, lengths, maxLength-lengths[N-1],N)),rodCuttingProblem(value,lengths,maxLength,N-1));
}

int main()
{
    int N,maxLength;
    cout<<"Enter the number of lengths of small rod : ";
    cin>>N;
    int value[N],lengths[N];
    cout<<"Now enter the different lengths of rods to be cut"<<endl;
    for(int i=0;i<N;i++) cin>>lengths[i];
    cout<<"Now enter the value of each length of rods"<<endl;
    for(int i=0;i<N;i++)
    {
        cout<<"Value of rod of length : "<<lengths[i]<<" : ";
        cin>>value[i];
    }
    cout<<"Enter the max length of the main rod : ";
    cin>>maxLength;
    int maxValue = rodCuttingProblem(value,lengths,maxLength,N);
    cout<<"Max value obtained from cutting the rod : "<<maxValue<<endl;
    return 0;
}
