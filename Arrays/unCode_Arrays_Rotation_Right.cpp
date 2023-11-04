//Program for Rotation(Right Rotation) of the array

//Time Complexity
//Worst Case    Average Case    Best Case
//O(N*M)          O(N*M)          O(N*M)
//Space Complexity O(1)

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

void rotationRight(int arr[],int N,int n)
{
    for(int i=0;i<n;i++)            //loop for number of rotations
    {
        int temp = arr[N-1];        //storing the last element
        for(int j=N-1;j>0;j--)      //loop to traverse whole array from last
        {
            arr[j] = arr[j-1];      //shifting the positions
        }
        arr[0] = temp;              //assigning the last element to first(oth) index
    }
}

int main()
{
	int arr[100],N,n;                           //defining the variables locally
    cout<<"Enter the number of elements : ";
    cin>>N;                                     //taking the number of elements for the array

    cout<<"Please Enter the elements"<<endl;
    for(int i=0;i<N;i++)
    {
        cout<<"Enter the element "<<(i+1)<<" : ";
        cin>>arr[i];                            //taking the elements in the array
    }
	cout<<"Array before Right Rotation"<<endl;  //printing before rotation(right)
	printArray(arr,N);

	cout<<"Enter the number of rotations : ";   //taking input for number of rotations
	cin>>n;
	rotationRight(arr,N,n);

    cout<<"Array after Right Rotation"<<endl;   //printing after the rotation(right)
    printArray(arr,N);
    return 0;
}
