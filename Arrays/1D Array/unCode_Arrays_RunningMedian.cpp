/*
    Running Median
    Print median after every insertion
*/

/*
input :
7
2 1 5 9 7 6 10
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> runningMedian(vector<int> nums,int n)
{
    priority_queue<int,vector<int>> max_h;
    priority_queue<int,vector<int>,greater<int>> min_h;
    vector<int> ans(n);
    ans[0] = nums[0];
    max_h.push(nums[0]);
    int median = nums[0];
    for(int i=1;i<n;i++)
    {
        if(nums[i]<median)
        {
            max_h.push(nums[i]);
        }
        else min_h.push(nums[i]);
        int x = max_h.size();
        int y = min_h.size();
        if(abs(x-y)>1)
        {
            if(x>y)
            {
                min_h.push(max_h.top());
                max_h.pop();
            }
            else
            {
                max_h.push(min_h.top());
                min_h.pop();
            }
        }
        if(max_h.size()==min_h.size())
        {
            median = max_h.top();
        }
        else if(max_h.size()>min_h.size())
        {
            median = max_h.top();
        }
        else median = min_h.top();
        ans[i] = median;
    }
    return ans;
}

void printVec(vector<int> nums)
{
    for(int x : nums)
    {
        cout<<x<<" ";
    }
    cout<<endl;
}

int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    vector<int> ans = runningMedian(nums,n);
    printVec(ans);
    return 0;
}
