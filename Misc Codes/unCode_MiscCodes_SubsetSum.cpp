//Subset Sum Problem
//using recursion

/*
    Description :-
    The Subset Sum Problem is a combinatorial optimization challenge where the goal is to determine whether a subset of a given set of
    numbers can sum up to a specific target value. This NP-complete problem has applications in resource allocation, cryptography, and
    partitioning. The task is to find a subset whose elements add up to the target, or to confirm that no such subset exists. Dynamic
    programming or recursive approaches are commonly used to efficiently explore the solution space. The problem's computational complexity
    makes it significant in algorithmic studies, demonstrating the challenges of solving optimization problems.
*/

#include<bits/stdc++.h>
using namespace std;

//function to check whether sum can be obtained from the array or not
//we checking from the end of the array
//we subtracting the elements from the sum to get the sum = 0 if sum is zero we return true
bool subsetSumProblem(int arr[],int N,int Sum)
{
    if(Sum==0) return true;                                                             //if sum becomes 0 return true that subset is present to get the required sum
    if(N==0) return false;                                                              //if no element is there in the array then return false
    if(Sum<arr[N-1]) return subsetSumProblem(arr,N-1,Sum);                              //if any element is greater than sum then ignore that element
    return (subsetSumProblem(arr,N-1,Sum-arr[N-1]) || subsetSumProblem(arr,N-1,Sum));   //check by taking the element or without that element that we can get the required sum or not
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

    bool chk = subsetSumProblem(arr,N,sum);
    if(chk) cout<<"Subset is present in the array to get the required sum = "<<sum<<endl;
    else cout<<"There is no subset present to get the required sum = "<<sum<<endl;
    return 0;
}
