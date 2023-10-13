//Program for Searching int the array using Binary Search using Recursion
//For using binary search array should be sorted

#include<bits/stdc++.h>
using namespace std;

int binarySearchRecursion(int ar[],int start,int last,int key)
{
    if(start<=last)                                                         //base condition
    {
        int mid = start + (last - start)/2;                                 //calculating mid index
        if(ar[mid]==key) return mid;                                        //if mid indexed element is the key then return its index
        if(ar[mid]>key) return binarySearchRecursion(ar,start,mid-1,key);   //if mid element is greater than key then recall the function by updating last element
        else return binarySearchRecursion(ar,mid+1,last,key);               //if mid element is less than the key then recall the function by updating the first element
    }
    return -1;                                                              //return -1 if key is not found
}

int main()
{
	int arr[] = {1,9,23,45,54,64,76,89,100,120}; //Defining Static Array because array should be sorted
    int key_1 = 54;
    int key_2 = 111;
    int size_arr = sizeof(arr)/sizeof(int);

    int index_1 = binarySearchRecursion(arr,0,size_arr-1,key_1);          //simulating when key is present
    if(index_1!=-1) cout<<"Key : "<<key_1<<" Index : "<<index_1<<endl;
    else cout<<"Key not found"<<endl;

    int index_2 = binarySearchRecursion(arr,0,size_arr-1,key_2);          //simulating when is is not present
    if(index_2!=-1) cout<<"Key : "<<key_2<<" Index : "<<index_2<<endl;
    else cout<<"Key not found"<<endl;

    return 0;
}
