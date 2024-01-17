// Program for Heap Sort (in Ascending order)

// Time Complexity of Heap Sort
// Worst Case    Average Case    Best Case
//   O(n log n)      O(n log n)       O(n log n)
// Space Complexity of Heap Sort is O(1)

#include <bits/stdc++.h>
using namespace std;

// Function to heapify a subtree rooted at index i
void heapify(int arr[], int size, int i)
{
    int largest = i;    // Initialize largest as root
    int left = 2 * i + 1;  // Left child
    int right = 2 * i + 2; // Right child

    // If left child is larger than root
    if (left < size && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < size && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, size, largest);
    }
}

// Function to perform Heap Sort
void heapSort(int arr[], int size)
{
    // Build heap (rearrange array)
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);

    // Extract elements from heap one by one
    for (int i = size - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]); // Move current root to end
        heapify(arr, i, 0);   // Max heapify the reduced heap
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

    heapSort(arr, n);
    cout << "Sorted Array (Ascending Order):" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    delete[] arr;
    return 0;
}
