//Program to find the Max Sliding Window using dequeue.

#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) 
{
    deque<int> dq;
    vector<int> result;

    for (int i = 0; i < nums.size(); i++) 
    {
        if (!dq.empty() && dq.front() == i - k) 
        {
            dq.pop_front();
        }
        while (!dq.empty() && nums[dq.back()] <= nums[i]) 
        {
            dq.pop_back();
        }

        dq.push_back(i);
        if (i >= k - 1) 
        {
            result.push_back(nums[dq.front()]);
        }
    }
    return result;
}

int main() 
{
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> result = maxSlidingWindow(nums, k);

    cout << "The maximum values in each sliding window are: ";
    for (int max_val : result) 
    {
        cout << max_val << " ";
    }
    return 0;
}
