//Program to print all the prime factors of the given number

//Time Complexity to check for prime
//Worst Case    Average Case    Best Case
//O(sqrt(N))     O(sqrt(N))     O(sqrt(N))

//Time Complexity to print the prime factors
//Worst Case    Average Case    Best Case
//O(M*sqrt(N))  O(M*sqrt(N))   O(M*sqrt(N))

#include<bits/stdc++.h>
using namespace std;

//To check for prime
bool isPrime(int n)
{
    if(n<2) return false;
    for(int i=2;i<sqrt(n);i++)
    {
        if(n%i==0) return false;
    }
    return true;
}


//Function to print all the prime factors
void primeFactors(int n)
{
    cout<<"Prime Factors of "<<n<<" are : ";
    int i=2;                        //used for iterating till n
    double temp = n;                //for checking
    while((int)temp!=1)             //loop till temp becomes 1 by dividing
    {
        if(!isPrime(i))             //if i is not prime then continue
        {
            i++;
            continue;
        }
        int temp1 = (int)temp/i;    //dividing temp with i in integer
        double temp2 = temp/i;      //dividing temp with i in double
        if((temp2-temp1)==0)        //if temp2-temp1 is zero then i completely divides so it is a factor
        {
            cout<<i<<" ";           //print the i
            temp = temp/i;          //divide the temp with i
        }
        else i++;                   //increment i if not dividing completely
    }
}

int main()
{
    int n;                                              //declaring the num to check
    cout<<"Enter a number to print Prime Factors : ";
    cin>>n;                                             //taking input
    if(n>2) primeFactors(n);                            //printing the prime factors if greater then 2
    else cout<<"Please enter a valid number";           //if not then show error message
    return 0;
}
