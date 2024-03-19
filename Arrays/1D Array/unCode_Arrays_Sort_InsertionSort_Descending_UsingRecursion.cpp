//Program for insertion sort (in descending order) using recursion

#include <bits/stdc++.h>
using namespace std;

void insert(vector<int>& arr, int n)
{
    if (n <= 1)
        return;
    insert(arr, n - 1);
    int last = arr[n - 1];
    int j = n - 2;

    while (j >= 0 && arr[j] < last)
    {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = last;
}

void insertionSort(vector<int>& arr)
{
    insert(arr, arr.size());
}

int main()
{
    vector<int> arr = {12, 11, 13, 5, 6};
    insertionSort(arr);

    cout << "Sorted array (descending order): ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
