//Program for Selection Sort(in Ascending Order) to sort the Array

//Time Complexity of Selection Sort
//Worst Case    Average Case    Best Case
//O(N^2)          O(N^2)          O(N^2)
//Space Complexity of Selection Sort is O(1)

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

void swap(int *a,int *b)                    //utility function to swap the variables [without using the 3rd variable]
{
    *a = *a + *b;                           //Ex- a = 1 & b = 2, then a = 1+2 => a = 3
    *b = *a - *b;                           //b = 3 - 2 => b = 1
    *a = *a - *b;                           //a = 3 - 1 => a = 2
}

//In selection sort we assume 1st element to be minimum and store its index and then traverse the array
//if any other element is found less than the assumed element then assign its index to temp var
//we traverse till last element and at last we swap the minimum element with the first element
//we make 2 parts in array sorted and unsorted
void selectionSortAscending(int arr[],int n)
{
    int min;                                //defining temporary var
    for(int i = 0;i<n-1;i++)                //traversing whole array
    {
        min = i;                            //assigning given element's index as minimum to the temp var
        for(int j=i+1;j<n;j++)              //traversing the array ahead of the taken element
        {
            if(arr[j]<arr[min])             //if other element found less than the current element then assign its index to temp var
            {
                min = j;
            }
        }
        swap(arr[i],arr[min]);              //lastly swap the current element with the minimum element in sorted part of array
    }
}

int main()
{
    int arr[100],N;                             //defining the variables locally
    cout<<"Enter the number of elements : ";
    cin>>N;                                     //taking the number of elements for the array

    cout<<"Please Enter the elements"<<endl;
    for(int i=0;i<N;i++)
    {
        cout<<"Enter the element "<<(i+1)<<" : ";
        cin>>arr[i];                            //taking the elements in the array
    }

    cout<<endl<<"Array before sorting"<<endl;
    printArray(arr,N);                          //printing the array before sorting

    selectionSortAscending(arr,N);
    cout<<endl<<"Array after sorting"<<endl;    //printing the sorted array
    printArray(arr,N);
    return 0;
}
