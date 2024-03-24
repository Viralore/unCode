//Program for selection sort (in descending order) using recursion

#include <bits/stdc++.h>
using namespace std;

int findMaxIndex(vector<int>& arr, int start, int end)
{
    int maxIndex = start;
    for (int i = start + 1; i <= end; ++i)
    {
        if (arr[i] > arr[maxIndex])
        {
            maxIndex = i;
        }
    }
    return maxIndex;
}

void selectionSortRec(vector<int>& arr, int n, int start)
{
    if (start >= n - 1)
        return;

    int maxIndex = findMaxIndex(arr, start, n - 1);
    if (maxIndex != start)
    {
        swap(arr[start], arr[maxIndex]);
    }
    selectionSortRec(arr, n, start + 1);
}

void printArray(const vector<int>& arr)
{
    cout << "Sorted array (descending order): ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {64, 11, 12, 22, 25};
    int n = arr.size();
    selectionSortRec(arr, n, 0);
    printArray(arr);
    return 0;
}
