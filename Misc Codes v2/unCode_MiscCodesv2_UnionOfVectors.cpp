//Program to find Union of Vectors

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Function to find the union of two vectors
vector<int> unionOfVectors(const vector<int>& vec1, const vector<int>& vec2) {
    unordered_set<int> resultSet;

    // Insert all elements of the first vector into the resultSet
    for (int elem : vec1) {
        resultSet.insert(elem);
    }

    // Insert all elements of the second vector into the resultSet
    for (int elem : vec2) {
        resultSet.insert(elem);
    }

    // Convert the resultSet to a vector
    vector<int> resultVector(resultSet.begin(), resultSet.end());
    return resultVector;
}

// Function to print a vector
void printVector(const vector<int>& vec) {
    for (int elem : vec) {
        cout << elem << " ";
    }
    cout << endl;
}

int main() 
{
    vector<int> vec1 = {15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
    vector<int> vec2 = {20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30};

    vector<int> resultVector = unionOfVectors(vec1, vec2);

    cout << "Vector 1: ";
    printVector(vec1);
    cout << "Vector 2: ";
    printVector(vec2);
    cout << "Union: ";
    printVector(resultVector);

    return 0;
}
