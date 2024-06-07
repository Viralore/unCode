//Program to find the Intersection of Sets

#include <bits/stdc++.h>
using namespace std;

set<int> intersectionOfSets(const set<int>& set1, const set<int>& set2) 
{
    set<int> resultSet;

    for (int elem : set1) 
    {
        if (set2.find(elem) != set2.end()) 
        {
            resultSet.insert(elem);
        }
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
    set<int> set1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                     11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
                     21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
                     31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
                     41, 42, 43, 44, 45, 46, 47, 48, 49, 50};

    set<int> set2 = {25, 26, 27, 28, 29, 30,
                     31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
                     41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
                     51, 52, 53, 54, 55, 56, 57, 58, 59, 60,
                     61, 62, 63, 64, 65, 66, 67, 68, 69, 70};

    set<int> resultSet = intersectionOfSets(set1, set2);

    cout << "Example:" << endl;
    cout << "Set 1: ";
    printSet(set1);
    cout << "Set 2: ";
    printSet(set2);
    cout << "Intersection: ";
    printSet(resultSet);

    return 0;
}
