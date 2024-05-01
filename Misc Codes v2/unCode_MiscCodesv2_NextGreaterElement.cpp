//Program to find next greater element of array elements

#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(const vector<int>& nums) 
{
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> s;
    
    for (int i = 0; i < n; ++i) 
    {
        while (!s.empty() && nums[i] > nums[s.top()]) 
        {
            result[s.top()] = nums[i];
            s.pop();
        }
        s.push(i);
    }
    
    return result;
}

int main() 
{
    vector<int> nums = {4, 2, 6, 8, 1, 5};
    
    vector<int> nextGreater = nextGreaterElement(nums);
    
    cout << "Next Greater Elements: ";
    for (int i = 0; i < nextGreater.size(); ++i) 
    {
        cout << nextGreater[i] << " ";
    }
    cout << endl;
    return 0;
}
