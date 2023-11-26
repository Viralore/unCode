// Program to Reverse an Array using Another Array

// Time Complexity of Reversing the array using another array
// Worst Case    Average Case    Best Case
// O(N)              O(N)          O(N)
// Space Complexity of Reversing the array using another array is O(N)

#include <bits/stdc++.h>
using namespace std;

// Function to reverse an array using another array
void reverseArray(int arr[], int size)
{
    int reversedArray[size];                    // Create a new array to store reversed elements
    for (int i = 0; i < size; i++)
    {
        reversedArray[i] = arr[size - 1 - i];   // Copy elements from the original array to the reversed array in reverse order
    }
    for (int i = 0; i < size; i++)
    {
        arr[i] = reversedArray[i];              // Copy the reversed array back to the original array
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
    int arr[100], N;                                // Defining the variables locally
    cout << "Enter the number of elements: ";       // Input: Number of elements for the array
    cin >> N;


    cout << "Enter the elements" << endl;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];                              // Input: Elements of the array
    }

    cout << "Array before reversing" << endl;       // Output: Array before reversing
    printArray(arr, N);

    reverseArray(arr, N);                           // Reverse the array

    cout << "Array after reversing" << endl;        // Output: Array after reversing
    printArray(arr, N);
    return 0;
}
