/*
    Find unique element in sorted array having 2N(Duplicate Elements) + 1(Unique element)

    Input  : 1 1 2 2 3 5 5 7 7  N : 9
    Output : 3
*/

#include<bits/stdc++.h>
using namespace std;

//returns index
int uniqueElement(int N,vector<int> arr)
{
    if(arr[0]!=arr[1]) return 0;
    if(arr[N-1]!=arr[N-2]) return N-1;
    int s=0,e=N-1;
    int mid;
    while(s<=e)
    {
        mid = (s+e)/2;
        if(arr[mid]!=arr[mid+1] && arr[mid]!=arr[mid-1]) return mid;
        if(mid%2!=0)
        {
            if(arr[mid]==arr[mid+1]) e = mid-1;
            if(arr[mid]==arr[mid-1]) s = mid+1;
        }
        else
        {
            if(arr[mid]==arr[mid+1]) s = mid+2;
            if(arr[mid]==arr[mid-1]) e = mid-2;
        }
    }
    return mid;
}

int main()
{
    int N,temp;
    cin>>N;
    vector<int> arr;
    for(int i=0;i<N;i++)
    {
        cin>>temp;
        arr.push_back(temp);
    }
    cout<<arr[uniqueElement(N,arr)];
    return 0;
}
