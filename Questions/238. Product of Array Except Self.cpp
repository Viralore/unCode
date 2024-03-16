/*
238. Product of Array Except Self

Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.

Example 1:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Example 2:
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]

Constraints:
2 <= nums.length <= 10^5
-30 <= nums[i] <= 30
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        vector<int>res(nums.size(), 1);

        for (int i = 1; i < nums.size(); i++) {
            res[i] = res[i-1] * nums[i-1];
        }

        int tmp = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            res[i] *= tmp;
            tmp *= nums[i];
        }

        return res;
    }
};
