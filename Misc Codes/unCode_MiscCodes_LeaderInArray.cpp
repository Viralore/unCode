//Leaders in Array
//a[i] is a leader if it is strictly > than element on right

/*
Input
15 -1 7 2 5 4 2 3
Output
5
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int leaders=0,maxx=0;
    for(int i=n-1;i>=0;i--)
    {
        int temp = arr[i];
        if(temp>maxx)
        {
            maxx=temp;
            leaders++;
        }
    }
    cout<<leaders;
    return 0;
}
