//Program to reverse a given sentence
//Below code will firstly split each word and then reverse the words

//Time Complexity is O(N) where N is total length of Sentence
//Space Complexity is O(M) where M is number of words

#include<bits/stdc++.h>
using namespace std;

//Function to reverse the Sentence
string reverseSentence(string input)
{
    vector<string> arr;                     //taking vector to store words and using vectors because we don't know how many words will be there
    string temp = "";
    char a = ' ';                           //for splitting the words
    int len = input.length();
    for(int i=0;i<len;i++)                  //iterate over the given sentence
    {
        if(input[i]!=a) temp+=input[i];     //if space is not encountered then assign each letter to temp var
        else                                //if space is encountered then push to arr because it becomes a word
        {
            arr.push_back(temp);
            temp="";                        //reset the temp var
        }
        if(i==len-1) arr.push_back(temp);   //for pushing the last word
    }
    temp="";                                //again resetting the temp var
    int size = arr.size();
    for(int i=size-1;i>=0;i--)              //iterating over complete vector
    {
        if(i==size-1) temp = arr[i];        //for first word concatenate as it is
        else temp = temp+" "+arr[i];        //for other words add space in betweeen
    }
    return temp;                            //finally return the reversed sentence
}

int main()
{
    string input,output;                        //declaring variables
    cout<<"Enter the sentence : ";
    getline(cin,input);                         //taking input and getline function will accept multiple words as input

    output = reverseSentence(input);            //calling the function
    cout<<"Reversed Sentence : "<<output;       //printing the reversed sentence
	return 0;
}
