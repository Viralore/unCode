//Program to check whether a number is Full Prime or not
//Full prime is a number which is prime and its digits are also prime

//Time Complexity to check for prime
//Worst Case    Average Case    Best Case
//O(sqrt(N))     O(sqrt(N))     O(sqrt(N))

//Time Complexity to check for Full Prime
//Worst Case    Average Case    Best Case
//O(N*sqrt(M))  O(N*sqrt(M))   O(N*sqrt(M))

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

//Function to check for full prime
void isFullPrime(int num)
{
    bool chk=true;                  //for checking a condition
    if(isPrime(num))                //if number is prime then check for full prime
    {
        int temp = num;             //temporary var to hold input number
        while(temp!=0 && chk)       //loop to traverse the digits
        {
            int temp2 = temp%10;    //getting digits one by one
            if(isPrime(temp2))      //checking if that digit is prime or not
            {
                temp = temp/10;     //if prime then divide temp var by 10 to get next digit
            }
            else                    //if not then make condition false
            {
                chk=false;
                break;              //and break the loop
            }
        }
    }
    else return;                    //if not prime then simply return
    if(!chk) cout<<"'"<<num<<"' is Prime but not Full Prime";   //if number is prime and also full prime
    else cout<<"'"<<num<<"' is Full Prime";                     //if number is prime but not full prime
}

int main()
{
    int num;                                                //declaring a variable
    cout<<"Enter a number to check for Full Prime : ";
    cin>>num;                                               //taking input

    if(isPrime(num))                                        //checking if prime
    {
        isFullPrime(num);                                   //checking if full prime
    }
    else cout<<"Number : "<<num<<" is not Prime";           //if not prime
    return 0;
}
