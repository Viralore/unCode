/*
Problem Explanation
Given a list of people with their heights and the number of people in front of them who have a height 
greater than or equal to theirs, reconstruct the queue. The input is given as a list of pairs where 
each pair contains two integers (h, k):

h: the height of the person.
k: the number of people in front of this person who have a height greater than or equal to h.
*/

#include <bits/stdc++.h>
using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b) 
{
    if (a.first == b.first) 
    {
        return a.second < b.second;
    }
    return a.first > b.first;
}

vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) 
{
    sort(people.begin(), people.end(), compare);
    vector<pair<int, int>> result;
    
    for (const auto& person : people) 
    {
        result.insert(result.begin() + person.second, person);
    }
    
    return result;
}

int main() 
{
    vector<pair<int, int>> people = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
    
    vector<pair<int, int>> reconstructedQueue = reconstructQueue(people);
    cout << "Reconstructed Queue: " << endl;
    for (const auto& person : reconstructedQueue) 
    {
        cout << "[" << person.first << ", " << person.second << "] ";
    }
    cout << endl;
    return 0;
}
