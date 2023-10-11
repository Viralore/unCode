//Program for searching linearly in an array

#include<bits/stdc++.h>
using namespace std;

int arr[10], key, N;            //defining the variables globally

int linearSearch(int Key)       //This linear search function will return the index value of the key if found otherwise will return -1
{
    for(int i=0;i<N;i++)
    {
        if(arr[i]==key) return i;   //returning the index of the key if found
    }
    return -1;                      //returning -1 if index is not found
}

int main()
{
	cout<<"Enter the number of elements in the array"<<endl;
    cin>>N;

    cout<<"Enter the elements in the array"<<endl;
    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
    }

    cout<<"Enter the Key to search"<<endl;
    cin>>key;

    int idx = linearSearch(key);

    if(idx!=-1) cout<<"Index of the key : "<<key<<" is "<<idx<<endl;
    else cout<<"Key : "<<key<<" not found"<<endl;

	return 0;
}
