//Program to find the Union of sets

#include <bits/stdc++.h>
using namespace std;


set<int> unionOfSets(const set<int>& set1, const set<int>& set2) 
{
    set<int> resultSet;

    for (int elem : set1) 
    {
        resultSet.insert(elem);
    }

    for (int elem : set2) 
    {
        resultSet.insert(elem);
    }

    return resultSet;
}

void printSet(const set<int>& s) 
{
    for (int elem : s) 
    {
        cout << elem << " ";
    }
    cout << endl;
}

int main() 
{
    set<int> set1 = {1, 2, 3, 4, 5};
    set<int> set2 = {4, 5, 6, 7, 8};
    set<int> resultSet = unionOfSets(set1, set2);

    cout << "Example 1:" << endl;
    cout << "Set 1: ";
    printSet(set1);
    cout << "Set 2: ";
    printSet(set2);
    cout << "Union: ";
    printSet(resultSet);
    cout << endl;

    return 0;
}
