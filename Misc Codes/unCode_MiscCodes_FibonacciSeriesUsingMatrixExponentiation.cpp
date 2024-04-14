//Program to find Nth Fibonacci Number using Matrix Exponentiation

#include<bits/stdc++.h>
using namespace std;

// Define a matrix class
class Matrix 
{
public:
    vector<vector<long long>> mat;
    int rows, cols;

    Matrix(int r, int c) : rows(r), cols(c) 
    {
        mat.resize(rows, vector<long long>(cols, 0));
    }

    Matrix operator*(const Matrix& other) const 
    {
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i) 
        {
            for (int j = 0; j < other.cols; ++j) 
            {
                for (int k = 0; k < cols; ++k) 
                {
                    result.mat[i][j] += mat[i][k] * other.mat[k][j];
                }
            }
        }
        return result;
    }
};

// Function to raise a matrix to a power using matrix exponentiation
Matrix power(Matrix m, int n) 
{
    int size = m.rows;
    Matrix result(size, size);
    for (int i = 0; i < size; ++i) 
    {
        result.mat[i][i] = 1;
    }
    while (n > 0) 
    {
        if (n % 2 == 1) {
            result = result * m;
        }
        m = m * m;
        n /= 2;
    }
    return result;
}

// Function to calculate the nth Fibonacci number using matrix exponentiation
long long fibonacci(int n) 
{
    if (n <= 0) return 0;
    Matrix base(2, 2);
    base.mat[0][0] = 1;
    base.mat[0][1] = 1;
    base.mat[1][0] = 1;
    base.mat[1][1] = 0;
    Matrix result = power(base, n - 1);
    return result.mat[0][0];
}

int main() 
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "The " << n << "th Fibonacci number is: " << fibonacci(n) << endl;
    return 0;
}
