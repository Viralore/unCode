//Program to find the Intersection of Vectors

#include <bits/stdc++.h>
using namespace std;

vector<int> intersectionOfVectors(const vector<int>& vec1, const vector<int>& vec2) 
{
    unordered_set<int> set1(vec1.begin(), vec1.end());
    vector<int> result;

    for (int elem : vec2) 
    {
        if (set1.find(elem) != set1.end()) 
        {
            result.push_back(elem);
            set1.erase(elem);
        }
    }

    return result;
}

void printVector(const vector<int>& vec) 
{
    for (int elem : vec) 
    {
        cout << elem << " ";
    }
    cout << endl;
}

int main() 
{
    vector<int> vec1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> vec2 = {5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

    vector<int> resultVector = intersectionOfVectors(vec1, vec2);

    cout << "Example:" << endl;
    cout << "Vector 1: ";
    printVector(vec1);
    cout << "Vector 2: ";
    printVector(vec2);
    cout << "Intersection: ";
    printVector(resultVector);

    return 0;
}
