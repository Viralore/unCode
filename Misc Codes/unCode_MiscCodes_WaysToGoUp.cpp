/*
    Ways to go up
    'A' wants to go  up the stairs by jumping 1 or 2 or 3 steps at a time
    Find total ways to go up
*/

#include<bits/stdc++.h>
using namespace std;

void printVec(vector<int> v)
{
    int n = v.size();
    for(int i=0;i<n-1;i++)
    {
        cout<<v[i]-v[i+1]<<" ";
    }
    cout<<endl;
}

int countWaysToG0Up(int n)
{
    if(n==0) return 1;
    if(n<0) return 0;
    return countWaysToG0Up(n-1)+countWaysToG0Up(n-2)+countWaysToG0Up(n-3);
}

//Count as well as print the ways to go up
int printWaysToGoUp(int n, vector<int>& v)
{
    if(n==0)
    {
        v.push_back(0);
        printVec(v);
        v.pop_back();
        return 1;
    }
    if(n<0) return 0;
    v.push_back(n);//top down
    int ans = printWaysToGoUp(n-1,v) + printWaysToGoUp(n-2,v) + printWaysToGoUp(n-3,v);
    v.pop_back();//bottom up
    return ans;
}

int main()
{
    int n,ans;
    cin>>n;
    vector<int> v;
    ans = printWaysToGoUp(n,v);
    cout<<"Total ways : "<<ans;
    return 0;
}
