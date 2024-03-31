//Problem link: https://www.spoj.com/problems/AGGRCOW/

#include<bits/stdc++.h>
using namespace std;

bool canPlace(long long int C,long long int N,vector<long long int> stalls,long long int sep)
{
    long long int cows = 1,last_cow=stalls[0];
    for(long long int i=1;i<N;i++)
    {
        if(stalls[i] - last_cow >= sep)
        {
            cows++;
            last_cow = stalls[i];
            if(cows==C) return true;
        }
    }
    return false;
}

int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int n,c,temp;
        cin>>n>>c;
        vector<long long int> stalls;
        for(long long int i=0;i<n;i++)
        {
            cin>>temp;
            stalls.push_back(temp);
        }
        sort(stalls.begin(),stalls.end());
        long long int ans,s=0,e=stalls[n-1]-stalls[0];
        while(s<=e)   //O(N*log(search space range))
        {
            long long int mid = (s+e)/2;
            if(canPlace(c,n,stalls,mid))
            {
                ans = mid;
                s = mid+1;
            }
            else e = mid - 1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
