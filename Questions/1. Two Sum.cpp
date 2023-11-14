/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]


Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums,int target)
{
    int size = nums.size();
    for(int i=0;i<size-1;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(nums[i] + nums[j] == target)
            {
                return {i,j};
            }
        }
    }
    return {};
}

int main()
{
    int n,temp,target;
    cout<<"Enter the number of elements : ";
    cin>>n;

    vector<int> nums;
    cout<<"Enter the elements"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        nums.push_back(temp);
    }

    cout<<"Enter the target value for two sum : ";
    cin>>target;
    vector<int> ans;
    ans = twoSum(nums,target);

    cout<<"To get target sum '"<<target<<"' add these 2 index values from the array"<<endl;
    cout<<"index "<<ans[0]<<" and index "<<ans[1]<<endl;
	return 0;
}
