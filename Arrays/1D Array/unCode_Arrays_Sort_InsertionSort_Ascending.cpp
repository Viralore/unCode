//Program for Insertion Sort(in Ascending Order) to sort the Array

//Time Complexity of Insertion Sort
//Worst Case    Average Case    Best Case
//O(N^2)          O(N^2)          O(N)
//Space Complexity of Insertion Sort is O(1)

#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[],int N)            //utility function to print the array
{
    cout<<"Array : ";
    for(int i=0;i<N;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

//in insertion sort we create 2 portions one is sorted and one unsorted
//we take an item from unsorted part and put to its correct position in sorted part
void insertionSortAscending(int arr[],int N)
{
    for(int i=1;i<N;i++)            //loop to traverse whole array
    {
        int temp = arr[i];          //setting first element as sorted
        int j = i-1;                //var to traverse in unsorted part
        while(j>=0 && temp<arr[j])  //loop to set the selected unsorted item and place it in its correct position
        {
            if(arr[j]>temp)         //if current element is not placed in sorted order than place it
            {
                arr[j+1] = arr[j];
                j--;
            }
        }
        arr[j+1] = temp;
    }
}

int main()
{
    int arr[100],N;                             //defining the variables locally
    cout<<"Enter the number of elements : ";
    cin>>N;                                     //taking the number of elements for the array

    cout<<"Enter the elements"<<endl;
    for(int i=0;i<N;i++)
    {
        cin>>arr[i];                            //taking the elements in the array
    }

    cout<<"Array before sorting"<<endl;
    printArray(arr,N);                          //printing the array before sorting

    insertionSortAscending(arr,N);
    cout<<"Array after sorting"<<endl;          //printing the sorted array
    printArray(arr,N);
    return 0;
}
