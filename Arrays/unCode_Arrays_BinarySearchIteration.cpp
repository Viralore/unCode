//Program for Searching int the array using Binary Search
//For using binary search array should be sorted

#include<bits/stdc++.h>
using namespace std;

int binarySearchIteration(int ar[],int key,int n)
{
    int start = 0,last = n-1;           //assigning first and last index initally
    int mid = (start+last)/2;           //getting mid element
    while(start<=last)                  //loop termination when last index is smaller than first index
    {
        if(ar[mid]==key) return mid;    //if mid element is key then return the index
        else if(ar[mid]>key)            //if mid element is greater than the key
        {
            last = mid-1;               //setting the last index less than the mid index
            mid = (start+last)/2;       //recalculating the mid element
        }
        else                            //if mid element is less than the key
        {
            start = mid+1;              //setting the start index as greater than mid index
            mid = (start+last)/2;       //recalculating the mid element
        }
    }
    return -1;                          //if key is not found than return -1
}

int main()
{
	int arr[] = {1,9,23,45,54,64,76,89,100,120}; //Defining Static Array because array should be sorted
    int key_1 = 54;
    int key_2 = 111;
    int size_arr = sizeof(arr)/sizeof(int);

    int index_1 = binarySearchIteration(arr,key_1,size_arr);          //simulating when key is present
    if(index_1!=-1) cout<<"Key : "<<key_1<<" Index : "<<index_1<<endl;
    else cout<<"Key not found"<<endl;

    int index_2 = binarySearchIteration(arr,key_2,size_arr);          //simulating when is is not present
    if(index_2!=-1) cout<<"Key : "<<key_2<<" Index : "<<index_2<<endl;
    else cout<<"Key not found"<<endl;

    return 0;
}
