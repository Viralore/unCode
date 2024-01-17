// Program for Radix Sort (in Ascending order)

// Time Complexity of Radix Sort
// Worst Case       Average Case     Best Case
// O(d * (n + k))  O(d * (n + k))  O(d * (n + k))
// Space Complexity of Radix Sort is O(n + k)

#include <bits/stdc++.h>
using namespace std;

// Get the maximum value in the array
int getMax(int arr[], int size)
{
    return *max_element(arr, arr + size);
}

// Perform counting sort based on the digit represented by exp
void countingSort(int arr[], int size, int exp)
{
    const int base = 10;  // Radix/base is 10 for decimal numbers
    vector<int> output(size);
    vector<int> count(base, 0);

    // Count the occurrences of each digit at the current place value
    for (int i = 0; i < size; i++)
    {
        count[(arr[i] / exp) % base]++;
    }

    // Modify count to store the position of each element in the sorted array
    for (int i = 1; i < base; i++)
    {
        count[i] += count[i - 1];
    }

    // Build the output array using count and arr
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % base] - 1] = arr[i];
        count[(arr[i] / exp) % base]--;
    }

    // Copy the sorted elements back to the original array
    for (int i = 0; i < size; i++)
    {
        arr[i] = output[i];
    }
}

// Perform Radix Sort
void radixSort(int arr[], int size)
{
    int maxElement = getMax(arr, size);

    // Perform counting sort for every digit place (exp)
    for (int exp = 1; maxElement / exp > 0; exp *= 10)
    {
        countingSort(arr, size, exp);
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int* arr = new int[n];
    cout << "Enter the elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    radixSort(arr, n);
    cout << "Sorted Array (Ascending Order):" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    delete[] arr;
    return 0;
}
