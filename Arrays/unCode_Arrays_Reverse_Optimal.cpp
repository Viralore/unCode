// Program to Reverse an Array Optimal

// Time Complexity of Reversing an Array
// Worst Case    Average Case    Best Case
// O(N)              O(N)          O(N)
// Space Complexity of Reversing the array O(1)

#include <bits/stdc++.h>
using namespace std;

// Function to reverse an array in-place
void reverseArray(int arr[], int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        swap(arr[i], arr[size - 1 - i]);    // Swap elements symmetrically from both ends
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

int main() {
    int arr[100], N;                                // Defining the variables locally
    cout << "Enter the number of elements: ";       // Input: Number of elements for the array
    cin >> N;


    cout << "Enter the elements" << endl;           // Input: Elements of the array
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    cout << "Array before reversing" << endl;       // Output: Array before reversing
    printArray(arr, N);

    reverseArray(arr, N);                           // Reverse the array in-place

    cout << "Array after reversing" << endl;        // Output: Array after reversing
    printArray(arr, N);
    return 0;
}
