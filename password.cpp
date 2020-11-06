#include <iostream>
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
using namespace std;
void askForSecretPassword(void)
{
    string password;
    cout<<"Enter your password: ";
    cin>>password;
    int len=password.length();
    system("CLS");
    cout<<"Entered Password: ";
    for(int i=0;i<len;i++){
    	cout<<"*";
    }cout<<endl;
}
int main()
{
    askForSecretPassword();
}

