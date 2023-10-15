//Program for Bubble Sort(in Ascending Order) to sort the Array

//Time Complexity of Bubble Sort
//Worst Case    Average Case    Best Case
//O(N^2)          O(N^2)          O(N)
//Space Complexity of Bubble Sort is O(1)

#include<bits/stdc++.h>
using namespace std;

void swap(int *a,int *b)                    //utility function to swap the variables [without using the 3rd variable]
{
    *a = *a + *b;                           //Ex- a = 1 & b = 2, then a = 1+2 => a = 3
    *b = *a - *b;                           //b = 3 - 2 => b = 1
    *a = *a - *b;                           //a = 3 - 1 => a = 2
}

void bubbleSortAscending(int arr[],int N)
{
    for(int i=0;i<N-1;i++)                  //loop to traverse the whole array
    {
        for(int j=0;j<N-1;j++)              //loop to compare every element
        {
            if(arr[j]>arr[j+1])             //if the current element is greater than the next element then swap the variable
            {
                swap(arr[j],arr[j+1]);      //swapping the current and next element
            }
        }
    }
}

void printArray(int arr[],int N)            //utility function to print the array
{
    cout<<"Array : ";
    for(int i=0;i<N;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
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
    printArray(arr,N);                   //printing the array before sorting


    bubbleSortAscending(arr,N);
    cout<<"Array after sorting"<<endl;          //printing the sorted array
    printArray(arr,N);
    return 0;
}
