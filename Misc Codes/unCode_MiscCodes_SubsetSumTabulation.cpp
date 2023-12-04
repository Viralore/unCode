//Subset Sum Problem
//using loops

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

// Function to solve the Subset Sum Problem using Dynamic Programming
// Returns true if there is a subset of the given set[] with sum equal to 'sum'
// Otherwise, returns false
bool subsetSumProblem(int set[],int n,int sum)
{
    bool subset[n+1][sum+1];    // Create a 2D array 'subset'
    for(int i=0;i<=n;i++)
    {
        subset[i][0] = true;    // Initialization: If the sum is 0, there is always an empty subset
    }
    for(int i=1;i<=sum;i++)
    {
        subset[0][i] = false;   // Initialization: If the set is empty, there is no subset with a non-zero sum
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            // If the current element 'set[i-1]' is greater than the current sum 'j',
            // copy the value from the row above (excluding the current element)
            if(j<set[i-1]) subset[i][j] = subset[i-1][j];

            // If the current sum 'j' is greater than or equal to the current element 'set[i-1]',
            // set 'subset[i][j]' to true if either:
            // The value in the row above (excluding the current element) is true,
            // The value in the row above (excluding the current element) at position (j - set[i-1]) is true
            if(j>=set[i-1]) subset[i][j] = subset[i-1][j] || subset[i-1][j-set[i-1]];
        }
    }
    return subset[n][sum];
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
    if(chk) cout<<"Subset is 'PRESENT' in the array to get the required sum = "<<sum<<endl;
    else cout<<"There is 'NO' subset present to get the required sum = "<<sum<<endl;
    return 0;
}
