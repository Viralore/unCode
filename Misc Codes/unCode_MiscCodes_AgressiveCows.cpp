/*

link : https://www.geeksforgeeks.org/problems/aggressive-cows/0

You are given an array consisting of n integers which denote the position of a stall.
You are also given an integer k which denotes the number of aggressive cows. You are given the task of
assigning stalls to k cows such that the minimum distance between any two of them is the maximum possible.
The first line of input contains two space-separated integers n and k.
The second line contains n space-separated integers denoting the position of the stalls.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canPlace(int C,int N,vector<int> stalls,int sep)
    {
        int cows = 1,last_cow=stalls[0];
        for(int i=1;i<N;i++)
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

    int solve(int n, int k, vector<int> &stalls)
    {
        sort(stalls.begin(),stalls.end());
        int ans,s=0,e=stalls[n-1]-stalls[0];
        while(s<=e)
        {
            int mid = (s+e)/2;
            if(canPlace(k,n,stalls,mid))
            {
                ans = mid;
                s = mid+1;
            }
            else e = mid - 1;
        }
        return ans;
    }
};

int main()
{
    int t = 1;
    cout<<"Test Cases : ";
    cin >> t;
    while (t--)
    {
        int n, k;
        cout<<"No of stalls : ";cin >> n;
        cout<<"No of cows   : ";cin >> k;
        vector<int> stalls(n);
        cout<<"Stalls Positions : ";
        for (int i = 0; i < n; i++)
        {
            cin >> stalls[i];
        }
        Solution obj;
        cout<<"Largest minimum possible separation distance : ";
        cout << obj.solve(n, k, stalls) << endl;
    }
    return 0;
}
