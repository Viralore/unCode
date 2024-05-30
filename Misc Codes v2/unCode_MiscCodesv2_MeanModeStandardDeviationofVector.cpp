//Program to find Mean, Mode, and Standard Deviation of given vector

#include <bits/stdc++.h>
using namespace std;

double calculateMean(const vector<int>& nums) 
{
    double sum = 0;
    for (int num : nums) 
    {
        sum += num;
    }
    return sum / nums.size();
}

int calculateMode(const vector<int>& nums) 
{
    unordered_map<int, int> frequency;
    for (int num : nums) 
    {
        frequency[num]++;
    }

    int mode = nums[0];
    int maxCount = 0;
    for (const auto& pair : frequency) 
    {
        if (pair.second > maxCount) 
        {
            maxCount = pair.second;
            mode = pair.first;
        }
    }

    return mode;
}

double calculateStandardDeviation(const vector<int>& nums) 
{
    double mean = calculateMean(nums);
    double sum = 0;
    for (int num : nums) 
    {
        sum += pow(num - mean, 2);
    }
    return sqrt(sum / nums.size());
}

int main() 
{
    vector<int> nums = {1, 2, 2, 3, 4, 4, 4, 5, 6};

    double mean = calculateMean(nums);
    cout << "Mean: " << mean << endl;

    int mode = calculateMode(nums);
    cout << "Mode: " << mode << endl;

    double stdDev = calculateStandardDeviation(nums);
    cout << "Standard Deviation: " << stdDev << endl;
    return 0;
}
