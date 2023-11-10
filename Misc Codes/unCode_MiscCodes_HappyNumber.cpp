//Program to check whether given number is Happy Number or not
//Using recursion
/*
    Happy Number
    19 is a Happy Number,
    1^2 + 9^2 = 82
    8^2 + 2^2 = 68
    6^2 + 8^2 = 100
    1^2 + 0^2 + 0^2 = 1
    As we reached to 1,
    19 is a Happy Number.
*/

#include<bits/stdc++.h>
using namespace std;

//Function to calculate the sum of squares of the digit of the given number
int returnSquare(int num)
{
    int temp=0;             //for storing the sum of squares of the digit
    while(num!=0)           //loop to traverse the digits of the given number
    {
        int x = num%10;     //getting the least significant digit
        temp = temp + x*x;  //updating the sum
        num = num/10;       //dividing the given number by 10 to remove the least significant digit
    }
    return temp;            //return square
}

bool isHappyNumber(int num)
{
    if(num==1 || num==7 || num==10) return true;    //setting base condition for recursion
    if(num<10) return false;                        //base conditions as they are pre-calculated
    return isHappyNumber(returnSquare(num));        //calling the function to check
}

int main()
{
    int num;                                                            //declaring variable
    cout<<"Enter a number to check for Happy Number : ";
    cin>>num;                                                           //taking input

    if(isHappyNumber(num)) cout<<num<<" is a Happy Number"<<endl;       //printing the result true if happy number
    else cout<<num<<" is not a Happy Number"<<endl;                     //if not print not a happy number
    return 0;
}
