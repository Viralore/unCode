// Program for Counting Sort (in Descending order)

// Time Complexity of Counting Sort
// Worst Case    Average Case    Best Case
// O(N+K)          O(N+K)          O(N+K)
// Space Complexity of Counting Sort is O(N)

#include <bits/stdc++.h>
using namespace std;

void countingSortDescending(int arr[], int size)
{
    // Find the maximum element in the array
    int maxElement = *max_element(arr, arr + size);

    // Create a count array to store the count of each element
    int* count = new int[maxElement + 1]();

    // Count the occurrences of each element in the input array
    for (int i = 0; i < size; i++)
    {
        count[arr[i]]++;
    }

    // Modify the count array to store the position of each element in the sorted array
    for (int i = maxElement - 1; i >= 0; i--)
    {
        count[i] += count[i + 1];
    }

    // Create the output array
    int* output = new int[size];

    // Build the output array using the count array
    for (int i = 0; i < size; i++)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the sorted elements back to the original array
    for (int i = 0; i < size; i++)
    {
        arr[i] = output[i];
    }

    // Free the dynamically allocated memory
    delete[] count;
    delete[] output;
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

    countingSortDescending(arr, n);

    cout << "Sorted Array (Descending Order):" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    delete[] arr;
    return 0;
}
