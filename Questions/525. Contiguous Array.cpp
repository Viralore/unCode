/*
525. Contiguous Array
Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

Example 1:
Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.

Example 2:
Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.

Constraints:
1 <= nums.length <= 10^5
nums[i] is either 0 or 1.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaxLength(vector<int>& nums)
    {
        int ans = 0;
        int prefix = 0;
        unordered_map<int, int> prefixToIndex{{0, -1}};

        for (int i = 0; i < nums.size(); ++i) {
        prefix += nums[i] ? 1 : -1;
        if (const auto it = prefixToIndex.find(prefix);
            it != prefixToIndex.cend())
            ans = max(ans, i - it->second);
        else
            prefixToIndex[prefix] = i;
        }
        return ans;
    }
};
