/*
    N - wines
    prices given
    in one year you can sell only one either from left or right
    cannot change the order
    price increases as year increases
    maximize the profit
*/

#include<bits/stdc++.h>
using namespace std;

int maxProfit_Rec_DP(vector<int> price,int s,int e,int y,vector<vector<int>>& dp)
{
    if(s>e) return 0;
    if(dp[s][e]!=-1) return dp[s][e];

    int opt1 = price[s]*y + maxProfit_Rec_DP(price,s+1,e,y+1,dp);
    int opt2 = price[e]*y + maxProfit_Rec_DP(price,s,e-1,y+1,dp);
    return dp[s][e] = max(opt1,opt2);
}


/*
input:
3
5 1 4
output:
21

input:
5
2 3 5 1 4
output:50
*/
int main()
{
    int n=4;cout<<"Enter number of elements : ";cin>>n;
    vector<int> price(n);
    cout<<"Elements : ";
    for(int i=0;i<n;i++) cin>>price[i];
    vector<vector<int>> dp(n,vector<int>(n,-1));
    cout<<maxProfit_Rec_DP(price,0,n-1,1,dp);
    return 0;
}
