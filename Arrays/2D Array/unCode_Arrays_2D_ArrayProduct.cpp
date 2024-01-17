#include <bits/stdc++.h>
using namespace std;

// Function to find the product of two 2D arrays
void multiply2DArrays(int arr1[][100], int arr2[][100], int result[][100], int rows1, int cols1, int rows2, int cols2)
{
    // Check if multiplication is possible
    if (cols1 != rows2)
    {
        cout << "Multiplication is not possible as the number of columns in the first array is not equal to the number of rows in the second array.";
        return;
    }

    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++)
            {
                result[i][j] += arr1[i][k] * arr2[k][j];
            }
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

int main()
{
    int rows1, cols1, rows2, cols2;

    cout << "Enter the number of rows and columns for the first 2D array: ";
    cin >> rows1 >> cols1;

    cout << "Enter the number of rows and columns for the second 2D array: ";
    cin >> rows2 >> cols2;

    int arr1[100][100], arr2[100][100], result[100][100]; // Assuming a maximum size for simplicity

    // Input elements into the first 2D array
    cout << "Enter elements of the first 2D array:" << endl;
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols1; j++)
        {
            cin >> arr1[i][j];
        }
    }

    // Input elements into the second 2D array
    cout << "Enter elements of the second 2D array:" << endl;
    for (int i = 0; i < rows2; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            cin >> arr2[i][j];
        }
    }
    multiply2DArrays(arr1, arr2, result, rows1, cols1, rows2, cols2);
    cout << "Resultant 2D Array (Product of the two arrays):" << endl;
    print2DArrayRowWise(result, rows1, cols2);
    return 0;
}
