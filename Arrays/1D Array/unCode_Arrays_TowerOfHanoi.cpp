//Program for printing the steps of Tower of Hanoi
//using recursion

#include<bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n,char src,char help,char dest)
{
    if(n==0) return;
    towerOfHanoi(n-1,src,dest,help);
    cout<<"Moving disk "<<n<<" from "<<src<<" to "<<dest<<"."<<endl;
    towerOfHanoi(n-1,help,src,dest);
}

int main()
{
    int n;
    cout<<"Enter number of disks";
    cin>>n;
    towerOfHanoi(n,'A','B','C');
	return 0;
}
