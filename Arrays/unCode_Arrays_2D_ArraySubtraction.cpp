//Program to Subtract in 2D array

#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 100;

// Function to perform subtraction of two 2D arrays
void subtractArrays(int arr1[][MAX_SIZE], int arr2[][MAX_SIZE], int rows, int cols)
{
    int result[MAX_SIZE][MAX_SIZE];

    // Subtract corresponding elements and store in result array
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            result[i][j] = arr1[i][j] - arr2[i][j];
        }
    }

    // Displaying the resultant array after subtraction
    cout << "Resultant Array (Subtraction):" << endl;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    int arr1[MAX_SIZE][MAX_SIZE], arr2[MAX_SIZE][MAX_SIZE];

    // Input for the first array
    cout << "Enter elements of first array:" << endl;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cin >> arr1[i][j];
        }
    }

    // Input for the second array
    cout << "Enter elements of second array:" << endl;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cin >> arr2[i][j];
        }
    }
    // Performing subtraction and displaying the result
    subtractArrays(arr1, arr2, rows, cols);

    return 0;
}
