// Program for Bucket Sort (in Ascending order)

// Time Complexity of Bucket Sort
// Worst Case       Average Case        Best Case
// O(n^2)         O(n + n^2/k + k)   O(n + n^2/k + k)
// Space Complexity of Bucket Sort is O(n + k) where k is the number of buckets

#include <bits/stdc++.h>
using namespace std;

// Function to perform Insertion Sort on each bucket
void insertionSort(vector<int>& bucket)
{
    int size = bucket.size();
    for (int i = 1; i < size; i++)
    {
        int key = bucket[i];
        int j = i - 1;
        while (j >= 0 && bucket[j] > key)
        {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

// Function to perform Bucket Sort
void bucketSort(vector<int>& arr)
{
    const int numBuckets = 10;  // Number of buckets

    // Create buckets
    vector<vector<int>> buckets(numBuckets);

    // Distribute elements into buckets
    for (int i = 0; i < arr.size(); i++)
    {
        int bucketIndex = arr[i] / numBuckets;
        buckets[bucketIndex].push_back(arr[i]);
    }

    // Sort each bucket using Insertion Sort
    for (int i = 0; i < numBuckets; i++)
    {
        insertionSort(buckets[i]);
    }

    // Concatenate the sorted buckets to get the final sorted array
    int index = 0;
    for (int i = 0; i < numBuckets; i++)
    {
        for (int j = 0; j < buckets[i].size(); j++)
        {
            arr[index++] = buckets[i][j];
        }
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    bucketSort(arr);

    cout << "Sorted Array (Ascending Order):" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
