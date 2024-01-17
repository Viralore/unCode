//Program to traverse 2-D array

//Time Complexity of Bubble Sort
//Worst Case    Average Case    Best Case
//O(N*M)          O(N*M)          O(N*M)

#include <bits/stdc++.h>
using namespace std;

// Function to print a 2D array row-wise
void print2DArrayRowWise(int arr[][100], int rows, int cols)
{
    cout << "2D Array (Row-wise):" << endl;
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

    int rows, cols;

    cout << "Enter the number of rows: ";
    cin >> rows;

    cout << "Enter the number of columns: ";
    cin >> cols;

    int arr[100][100];
    cout << "Enter elements of the 2D array:" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> arr[i][j];
        }
    }
    print2DArrayRowWise(arr, rows, cols);
    return 0;
}
