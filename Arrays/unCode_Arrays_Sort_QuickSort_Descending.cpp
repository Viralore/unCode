// Program for Quick Sort (in Descending Order) to sort the Array

// Time Complexity of Quick Sort
// Worst Case    Average Case    Best Case
// O(N^2)          O(N log N)       O(N log N)
// Space Complexity of Quick Sort is O(log N) - O(N)

#include <bits/stdc++.h>
using namespace std;

// Partition function to partition the array and return the pivot index
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];                  // Choose the rightmost element as the pivot
    int i = low - 1;                        // Index of smaller element
    for (int j = low; j < high; j++)
    {
        if (arr[j] >= pivot)
        {
            i++;
            swap(arr[i], arr[j]);           // Swap arr[i] and arr[j]
        }
    }
    swap(arr[i + 1], arr[high]);            // Swap arr[i+1] and arr[high] (pivot)
    return i + 1;
}

// Quick Sort function
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);     // Partition the array and get the pivot index

        quickSort(arr, low, pivotIndex - 1);            // Recursively sort the sub-arrays on both sides of the pivot
        quickSort(arr, pivotIndex + 1, high);
    }
}

// Utility function to print the array
void printArray(int arr[], int N)
{
    cout << "Array: ";
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[100], N;                                            // Defining the variables locally
    cout << "Enter the number of elements: ";
    cin >> N;                                                   // Taking the number of elements for the array

    cout << "Enter the elements" << endl;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];                                          // Taking the elements in the array
    }

    cout << "Array before sorting" << endl;
    printArray(arr, N);                                         // Printing the array before sorting

    quickSort(arr, 0, N - 1);
    cout << "Array after sorting in descending order" << endl; // Printing the sorted array
    printArray(arr, N);
    return 0;
}
