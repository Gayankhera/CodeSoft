# include<iostream>
# include<cmath>
# include<stdio.h>

using namespace std;
 
 int main()
 {
    string operation;
    double num1,num2;

    cout<<"enter first number:";
    cin>>num1;

    cout<<"enter second number:";
    cin>>num2;
    
     cout<<"enter operation(+,-,*,/):";
    cin>>operation;
    
  

    if (operation == "+")
    {
        cout<< num1+num2;
    } 
     else if (operation == "-")
    {
         cout<< num1-num2;
    }
    else if (operation == "*")
    {
         cout<< num1*num2;
    }
    else if (operation == "/")
    {
         cout<< num1/num2;
    } 
    else{
        cout<<"invalid operation";
    }
    return 0;
 }