/*
769. Max Chunks To Make Sorted

You are given an integer array arr of length n that represents a permutation of the integers in the range [0, n - 1].

We split arr into some number of chunks (i.e., partitions), and individually sort each chunk. After concatenating
them, the result should equal the sorted array.

Return the largest number of chunks we can make to sort the array.
Example 1:

Input: arr = [4,3,2,1,0]
Output: 1
Explanation:
Splitting into two or more chunks will not return the required result.
For example, splitting into [4, 3], [2, 1, 0] will result in [3, 4, 0, 1, 2], which isn't sorted.
Example 2:

Input: arr = [1,0,2,3,4]
Output: 4
Explanation:
We can split into two chunks, such as [1, 0], [2, 3, 4].
However, splitting into [1, 0], [2], [3], [4] is the highest number of chunks possible.

*/

#include<bits/stdc++.h>
using namespace std;

int maxChunksToSorted(vector<int>& arr)
{
    int count = 0;
    int N = arr.size();
    if(arr[N-1]==0) return 1;
    for(int i=0;i<N;i++)
    {
        if(arr[i] == i) count++;
        else
        {
            int j,temp=arr[i];
            for(j=i;j<=temp;j++)
            {
                if(arr[j]>temp) temp=arr[j];
            }
            i=j-1;
            count++;
        }
    }
    return count;
}

int main()
{
    cout<<"Please enter the number of elements : ";
    int n,temp;
    cin>>n;
    cout<<"Enter the elements"<<endl;
    vector<int> arr;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        arr.push_back(temp);
    }
    temp = maxChunksToSorted(arr);
    cout<<"Max number of chunks are required to make the array sorted is : "<<temp;
    return 0;
}
