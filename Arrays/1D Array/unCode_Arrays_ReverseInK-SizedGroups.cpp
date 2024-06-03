//Program to reverse in K-Sized groups

#include <bits/stdc++.h>
#include <vector>
using namespace std;

void reverseInGroups(vector<int>& arr, int k) 
{
    int n = arr.size();
    for (int i = 0; i < n; i += k) 
    {
        int left = i;
        int right = min(i + k - 1, n - 1);
        while (left < right) 
        {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
}

void printArray(const vector<int>& arr) 
{
    for (int num : arr) 
    {
        cout << num << " ";
    }
    cout << endl;
}

int main() 
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int k = 3;

    cout << "Original array: ";
    printArray(arr);
    reverseInGroups(arr, k);

    cout << "Array after reversing in groups of " << k << ": ";
    printArray(arr);

    return 0;
}
