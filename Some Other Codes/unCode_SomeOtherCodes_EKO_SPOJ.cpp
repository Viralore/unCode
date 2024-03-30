//Question Link : https://www.spoj.com/problems/EKO/

#include<bits/stdc++.h>
using namespace std;

bool canGetWood(long long int N,long long int M,vector<long long int> heights,long long int height)
{
    long long int c_wood=0;
    for(long long int i=0;i<N;i++)
    {
        if(heights[i]>=height)
        {
            c_wood = c_wood + (heights[i]-height);
        }
    }
    return c_wood>=M;
}

int main()
{
    long long int N,M,temp;
    cin>>N>>M;
    vector<long long int> heights;
    for(long long int i=0;i<N;i++)
    {
        cin>>temp;
        heights.push_back(temp);
    }
    long long int s=1,e=0,ans=0;
    for(long long int i=0;i<N;i++)
    {
        if(e<heights[i]) e = heights[i];
    }
    while(s<=e)
    {
        long long int mid = (e+s)/2;
        if(canGetWood(N,M,heights,mid))
        {
            ans=mid;
            s = mid+1;
        }
        else e = mid-1;
    }
    cout<<ans;
    return 0;
}
