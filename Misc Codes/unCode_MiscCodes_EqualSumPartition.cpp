//Equal Sum Partition
//using recursion

/*
    Description :-
    The Equal Sum Partition Problem is a combinatorial optimization challenge where the goal is to determine whether a given
    set of numbers can be partitioned into two subsets with equal sums. The task is to find a way to divide the set into two
    parts such that the sum of elements in each subset is the same. This problem is NP-complete and has applications in various
    fields, including resource allocation and scheduling. Efficient solutions typically involve dynamic programming or recursive
    approaches. The Equal Sum Partition Problem highlights the complexity of achieving a balanced distribution of elements in a set.
*/

#include<bits/stdc++.h>
using namespace std;

//utility function to calculate the sum of the array
int sumArray(int nums[],int N)
{
    int sum = 0;
    for(int i=0;i<N;i++)
    {
        sum+=nums[i];
    }
    return sum;
}

// Recursive function to solve the Equal Sum Partition Problem
// Returns true if the given set 'nums' can be partitioned into two subsets with equal sums
// 'N' is the number of elements in the set, and 'Sum' is the target sum for each subset
bool equalSumPartitionProblem(int nums[],int N,int Sum)
{
    if(Sum==0) return true; //If the target sum becomes 0, we have found a valid partition
    if(N==0) return false;  //If there are no more elements to consider and Sum is not 0, partition is not possible

    // If the current element  is greater than the target sum ,
    // exclude the current element and consider the remaining elements
    if(Sum<nums[N-1]) return equalSumPartitionProblem(nums,N-1,Sum);

    // Check if it's possible to achieve the target sum by either:
    // 1. Including the current element in the partition and reducing the target sum
    // 2. Excluding the current element and considering the remaining elements
    return (equalSumPartitionProblem(nums,N-1,Sum-nums[N-1]) || equalSumPartitionProblem(nums,N-1,Sum));
}

int main()
{
    int N;
    cout<<"Enter the number of elements : ";
    cin>>N;
    int nums[N];
    cout<<"Now enter the elements"<<endl;
    for(int i=0;i<N;i++) cin>>nums[i];

    int Sum = sumArray(nums,N);
    if(Sum%2==0)
    {
        bool chk = equalSumPartitionProblem(nums,N,Sum/2);
        if(chk) cout<<"Equal Sum Partition is 'Possible' from the given set of numbers"<<endl;
        else cout<<"Equal Sum Partition is 'Not Possible' from the given set of numbers"<<endl;
    }
    else cout<<"No partition is possible for the given sum '"<<Sum<<"' as sum is 'ODD'"<<endl;
    return 0;
}
