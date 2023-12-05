//Subset Sum Problem - Count of total subset
//using recursion

/*
    Description :-
    The Count of Subset Sum Problem is a combinatorial optimization challenge aiming to find the total number of subsets within
    a given set of numbers that sum up to a specific target value. Unlike the Subset Sum Problem, this task focuses on counting
    the possible subsets rather than identifying them. It is often solved using dynamic programming, where a 2D array is employed
    to store the count of valid subsets for varying subset sizes and target sums. This problem finds applications in areas such as
    cryptography and resource allocation, providing insights into the count of feasible combinations within a set.
*/

#include<bits/stdc++.h>
using namespace std;

//function to determine the total possible subsets
//we are subtracting the last element of array form the sum if sum reaches zero then a particular subset is present
//we going from last element to first element
int countOfSubsetSumProblem(int value[],int N,int Sum)
{
    if(Sum==0) return 1;    //if sum reaches zero we get a subset so return 1

    if(N==0) return 0;      //if no element is present then return 0

    if(Sum<value[N-1]) return countOfSubsetSumProblem(value,N-1,Sum);   //if any element is greater then sum then ignore it

    //here we are considering every possibility so we add both cases i) taking that particular element ii) without taking that
    //element we are able to find the required sum or not
    return (countOfSubsetSumProblem(value,N-1,Sum-value[N-1]) + countOfSubsetSumProblem(value,N-1,Sum));
}

int main()
{
    int N,sum;
    cout<<"Enter the number of Elements : ";
    cin>>N;
    int arr[N];
    cout<<"Now enter the elements"<<endl;
    for(int i=0;i<N;i++) cin>>arr[i];

    cout<<"Enter the sum to check : ";
    cin>>sum;

    int num = countOfSubsetSumProblem(arr,N,sum);
    if(num!=0) cout<<"Total number of subset for given sum '"<<sum<<"' are : "<<num<<endl;
    else cout<<"There is no subset present for the given sum '"<<sum<<"'"<<endl;
    return 0;
}
