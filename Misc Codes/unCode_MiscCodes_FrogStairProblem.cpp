/*
    Frog Stairs Problem
    frog can jump i+1 or i+2 to reach the last stair
    energy loss = | Hi - Hj|
    Minimize total energy loss
*/

/*
input:
4
10 20 30 10
output:
20
*/

#include<bits/stdc++.h>
using namespace std;

int energyLoss(int n,vector<int> height)
{
    //base case
    if(n==1) return 0;
    //Rec case
    int cost_1=INT16_MAX, cost_2 = INT16_MAX;
    cost_1 = energyLoss(n-1,height) + abs(height[n-1]-height[n-2]);
    if(n-2>0) cost_2 = energyLoss(n-2,height) + abs(height[n-1] - height[n-3]);
    return min(cost_1,cost_2);
}

int main()
{
    int n;
    cin>>n;
    vector<int> heights(n);
    for(int i=0;i<n;i++) cin>>heights[i];
    cout<<energyLoss(n,heights);
    return 0;
}
