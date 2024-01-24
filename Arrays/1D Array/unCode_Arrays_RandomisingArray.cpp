//Program to Randomising Array
//Use of Randomized Array is to prevent worst case for sorting the array
//As we know Time Complexity to sort sorted array using quick sort is O(n^2)
//which is quite high as compared to O(N*logN)

#include<bits/stdc++.h>
using namespace std;

//function to get random int value in range [a,b]
int getRandom(int a,int b)
{
    srand(time(0));                 //for changing the seed value of rand function otherwise it will generate same set of numbers
    return (rand()%(b-a+1)) + a;
}

void printVec(int n,vector<int> nums)
{
    cout<<"Array : ";
    for(int i=0;i<n;i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}

//for shuffling the array elements and shuffling in such a way that no element remains in its original place
void shuffleVec(vector<int>& arr,int n)
{
    for(int i=n-1;i>0;i--)
    {
        int random_idx = getRandom(0,i-1);
        swap(arr[i],arr[random_idx]);
    }
}

//input :  1 83 3 30 67 45 5 221  n : 8
int main()
{
    int n,temp;
    cout<<"No. of elements : ";cin>>n;
    vector<int> nums;
    cout<<"Elements : ";
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        nums.push_back(temp);
    }
    cout<<"Before Shuffling"<<endl;
    printVec(n,nums);
    shuffleVec(nums,n);
    cout<<"After Shuffling"<<endl;
    printVec(n,nums);
    return 0;
}
