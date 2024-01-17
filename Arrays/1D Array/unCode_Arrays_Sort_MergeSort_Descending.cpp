// Program for Merge Sort (in Descending Order) to sort the Array

// Time Complexity of Merge Sort
// Worst Case    Average Case    Best Case
// O(N log N)    O(N log N)       O(N log N)
// Space Complexity of Merge Sort is O(N)

#include <iostream>
using namespace std;

// Merge function to merge two halves of the array
void merge(int arr[], int left, int middle, int right)
{
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int leftArray[n1], rightArray[n2];      // Create temporary arrays

    // Copy data to temporary arrays leftArray[] and rightArray[]
    for (int i = 0; i < n1; i++)
        leftArray[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArray[j] = arr[middle + 1 + j];


    int i = 0, j = 0, k = left;             // Merge the temporary arrays back into arr[left...right]
    while (i < n1 && j < n2)
    {
        if (leftArray[i] >= rightArray[j])
        {
            arr[k] = leftArray[i];
            i++;
        }
        else
        {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }


    while (i < n1)                          // Copy the remaining elements of leftArray[], if there are any
    {
        arr[k] = leftArray[i];
        i++;
        k++;
    }


    while (j < n2)                          // Copy the remaining elements of rightArray[], if there are any
    {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

// Merge Sort function
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2; // Same as (left+right)/2, but avoids overflow for large left and right

        mergeSort(arr, left, middle);           // Recursively sort the first and second halves
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);        // Merge the sorted halves
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

    mergeSort(arr, 0, N - 1);
    cout << "Array after sorting in descending order" << endl;  // Printing the sorted array
    printArray(arr, N);

    return 0;
}
