//Program for selection sort (in ascending order) using recursion

#include <bits/stdc++.h>
using namespace std;

int findMinIndex(int arr[], int start, int end)
{
    int minIndex = start;
    for (int i = start + 1; i <= end; ++i)
    {
        if (arr[i] < arr[minIndex])
        {
            minIndex = i;
        }
    }
    return minIndex;
}

void selectionSortRec(int arr[], int n, int start)
{
    if (start >= n - 1)
        return;

    int minIndex = findMinIndex(arr, start, n - 1);
    if (minIndex != start)
    {
        swap(arr[start], arr[minIndex]);
    }
    selectionSortRec(arr, n, start + 1);
}

void printArray(int arr[], int n)
{
    cout << "Sorted array (ascending order): ";
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSortRec(arr, n, 0);
    printArray(arr, n);
    return 0;
}
