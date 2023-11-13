/*
1343. Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold

Given an array of integers arr and two integers k and threshold, return the number
of sub-arrays of size k and average greater than or equal to threshold.

Example 1:
Input: arr = [2,2,2,2,5,5,5,8], k = 3, threshold = 4
Output: 3
Explanation: Sub-arrays [2,5,5],[5,5,5] and [5,5,8] have averages 4, 5 and 6
respectively. All other sub-arrays of size 3 have averages less than 4 (the threshold).
Example 2:

Input: arr = [11,13,17,23,29,31,7,5,2,3], k = 3, threshold = 5
Output: 6
Explanation: The first 6 sub-arrays of size 3 have averages greater than 5.
Note that averages are not integers.


Constraints:
1 <= arr.length <= 105
1 <= arr[i] <= 104
1 <= k <= arr.length
0 <= threshold <= 104
*/

#include<bits/stdc++.h>
using namespace std;

int numOfSubarrays(int arr[], int k, int threshold,int N)
{
    int count = 0;
    int j = -(k-1);
    int sum = 0;
    for(int i=0;i<N;i++)
    {
        sum = sum + arr[i];
        int avg = sum/k;
        if(avg>=threshold && i>=k-1) count++;
        if(j>-1)
        {
            sum = sum - arr[j];
        }
        j++;
    }
    return count;
}

int main()
{
    int N,k,threshold;
    cout<<"Enter the Number of elements : ";
    cin>>N;
    int arr[N];
    cout<<"Enter the Elements"<<endl;
    for(int i=0;i<N;i++) cin>>arr[i];
    cout<<"Enter the value of k : ";
    cin>>k;
    cout<<"Enter the value of threshold : ";
    cin>>threshold;
    int num = numOfSubarrays(arr,k,threshold,N);
    cout<<"Number of Sub-arrays of Size K->"<<k<<" and Average Greater than or Equal to Threshold->"<<threshold<<" is "<<num<<endl;
    return 0;
}
