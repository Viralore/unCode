/*
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation:
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]


Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
0 <= k <= 105
*/

#include<bits/stdc++.h>
using namespace std;

void printArray(int nums[],int n)
{
    cout<<"Array : ";
    for(int i=0;i<n;i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}

void rev(int nums[],int i,int j)
{
    for(int a=i;a<=j;a++)
    {
        int temp = nums[a];
        nums[a] = nums[j];
        nums[j] = temp;
        j--;
    }
}

void rotate(int nums[], int k,int n)
{
    k = k%n;
    rev(nums,0,n-k-1);
    rev(nums,n-k,n-1);
    rev(nums,0,n-1);
}

int main()
{
    int n,k;
    cout<<"Enter the number of elements : ";
    cin>>n;
    int nums[n];

    cout<<"Enter the elements"<<endl;
    for(int i=0;i<n;i++) cin>>nums[i];

    cout<<"Array before rotation"<<endl;
    printArray(nums,n);

    cout<<"Enter the number of rotations : ";
    cin>>k;

    cout<<"Array after rotation"<<endl;
    rotate(nums,k,n);
    printArray(nums,n);
    return 0;
}
