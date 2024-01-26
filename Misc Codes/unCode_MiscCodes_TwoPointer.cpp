/*
    Count the total pair of element such that arr[j]-arr[i] = k
    From given sorted array

    Example : Arr : -3 0 1 3 6 8 11 14 18 25 Target : 5
    Output  : 3
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,temp,target;
    cout<<"Enter total elements : ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements : ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    temp=0;
    cout<<"Enter the value of K : ";
    cin>>target;
    int s=0,e=1;
    while(e<n)
    {
        if(arr[e]-arr[s]==target)
        {
            temp++;
            e++;
            s++;
        }
        else if(arr[e]-arr[s]>target) s++;
        else e--;
    }
    cout<<"Total Pairs is : "<<temp;
    return 0;
}
