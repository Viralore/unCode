//Program to Add 2-D array

//Time Complexity of Bubble Sort
//Worst Case    Average Case    Best Case
//O(N*M)          O(N*M)          O(N*M)

#include <bits/stdc++.h>
using namespace std;

// Function to add two 2D arrays
void add2DArrays(int arr1[][100], int arr2[][100], int result[][100], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
}

// Function to print a 2D array row-wise
void print2DArrayRowWise(int arr[][100], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // Define two 2D arrays
    int rows, cols;

    cout << "Enter the number of rows and columns for the 2D arrays: ";
    cin >> rows >> cols;

    int arr1[100][100], arr2[100][100], result[100][100];


    cout << "Enter elements of the first 2D array:" << endl;        // Input elements into the first 2D array
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> arr1[i][j];
        }
    }


    cout << "Enter elements of the second 2D array:" << endl;       // Input elements into the second 2D array
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> arr2[i][j];
        }
    }
    add2DArrays(arr1, arr2, result, rows, cols);

    cout << "Resultant 2D Array (Sum of the two arrays):" << endl;  // Print the result
    print2DArrayRowWise(result, rows, cols);

    return 0;
}
