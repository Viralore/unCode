//Program to reverse a words in given string
//used vectors because we didn't know the count of words

#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> arr;                     //initializing vector of string type
    string input,temp="";                   //for taking input and temporary variable
    char a = ' ';                           //for checking spaces
    cout<<"Enter the string"<<endl;
    getline(cin,input);                     //taking input from getline because we need multiple words
    int len = input.length();               //getting length
    for(int i=0;i<len;i++)
    {
        if(input[i]!=a) temp+=input[i];     //if current char is not space we insert it in temp var to make a word
        else                                //if space found
        {
            arr.push_back(temp);            //then store it in vector
            temp="";                        //resetting the temp var
        }
        if(i==len-1) arr.push_back(temp);   //when reaching the last index push the last word in vector
    }
    temp="";                                //resetting the temp var
    int size = arr.size();                  //getting the size/words
    for(int i=size-1;i>=0;i--)
    {
        if(i==size-1) temp = arr[i];        //reversing the string
        else temp = temp+" "+arr[i];
    }
    cout<<"Words reversed"<<endl;           //printing the reversed string
    cout<<temp;
	return 0;
}
