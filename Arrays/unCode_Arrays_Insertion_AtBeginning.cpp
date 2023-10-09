//Program for inserting the elements at the beginning of the Array

#include<bits/stdc++.h>
using namespace std;

int arr[100],x,n;           //defining the variables globally

void insertAtBeginning()
{
    for(int i=n;i>0;i--)
    {
        arr[i] = arr[i-1];  //shifting the elements from the end
    }
    arr[0] = x;             //assigning the element at the first(0th index) position
    n++;                    //incrementing the number of elements
}

void printArray()
{
    cout<<"Array :";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    cout<<"Enter the number of elements in the array"<<endl;
    cin>>n;
    cout<<"Enter the elements in the array"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Before inserting the element"<<endl;
    printArray();

    cout<<"Enter the element to insert"<<endl;
    cin>>x;

    insertAtBeginning();
    cout<<"After inserting the element"<<endl;
    printArray();

	return 0;
}
