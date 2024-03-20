//Program for Bubble sort (in descending order) using recursion

#include<bits/stdc++.h>
using namespace std;

// Using one loop
void bubbleSort_Rec_Loop(int arr[], int n)
{
    if (n == 1) return;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] < arr[i + 1])
            swap(arr[i], arr[i + 1]);
    }
    bubbleSort_Rec_Loop(arr, n - 1);
}

// Without using a single loop
void bubbleSort_Rec(int arr[], int n, int i) {
    if (n == 1 || n == 0) return;
    if (i == n - 1)
    {
        bubbleSort_Rec(arr, n - 1, 0);
        return;
    }
    if (arr[i] < arr[i + 1])
        swap(arr[i], arr[i + 1]);
    bubbleSort_Rec(arr, n, i + 1);
}

void printArr(int arr[], int n)
{
    cout << "Array : ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {1, 2, 3, 5, 4};
    int n = 5;
    bubbleSort_Rec(arr, n, 0);
    printArr(arr, n);
    return 0;
}
