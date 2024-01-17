// Program for Merging Two Sorted Arrays

// Time Complexity of Merging Two Sorted Arrays
// Worst Case    Average Case    Best Case
// O(M+N)           O(M+N)         O(M+N)
// Space Complexity of Merging Two Sorted Arrays is O(M+N)

#include <iostream>
using namespace std;

// Function to merge two sorted arrays
void mergeArrays(int arr1[], int size1, int arr2[], int size2, int result[])
{
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2)      // Traverse both arrays
    {
        if (arr1[i] <= arr2[j])         //inserting in sorted order into the resultant array
        {
            result[k++] = arr1[i++];
        }
        else
        {
            result[k++] = arr2[j++];
        }
    }

    while (i < size1)                   // If there are remaining elements in arr1, copy them to result
    {
        result[k++] = arr1[i++];
    }
    while (j < size2)                   // If there are remaining elements in arr2, copy them to result
    {
        result[k++] = arr2[j++];
    }
}

// Utility function to print the array
void printArray(int arr[], int size)
{
    cout << "Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr1[100], arr2[100], result[200], size1, size2;                            //declaring the variables

    cout << "Enter the size of the first array: ";                                  // Input: Size of the first array
    cin >> size1;
    cout << "Enter the elements of the first array (in sorted order):" << endl;     // Input: Elements of the first array
    for (int i = 0; i < size1; i++)
    {
        cin >> arr1[i];
    }

    cout << "Enter the size of the second array: ";                                 // Input: Size of the second array
    cin >> size2;
    cout << "Enter the elements of the second array (in sorted order):" << endl;    // Input: Elements of the second array
    for (int i = 0; i < size2; i++)
    {
        cin >> arr2[i];
    }

    mergeArrays(arr1, size1, arr2, size2, result);                                  // Merge the two sorted arrays
    cout << "Merged array: " << endl;                                               // Output: Merged array
    printArray(result, size1 + size2);
    return 0;
}
