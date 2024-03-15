/*
930. Binary Subarrays With Sum

Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.
A subarray is a contiguous part of the array.

Example 1:
Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]

Example 2:
Input: nums = [0,0,0,0,0], goal = 0
Output: 15

Constraints:
1 <= nums.length <= 3 * 10^4
nums[i] is either 0 or 1.
0 <= goal <= nums.length
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSubarraysWithSum(vector<int>& nums, int goal)
    {
        vector<int> cnt(nums.size() + 1);
        int sum = 0, res = 0;
        for (int num : nums) {
            sum += num;
            if (sum == goal) ++res;
            if (sum - goal >= 0) res += cnt[sum - goal];
            ++cnt[sum];
        }
        return res;
    }
};
