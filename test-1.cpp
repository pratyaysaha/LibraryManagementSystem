#include<iostream>
#include"admin_database.h"

using namespace std;

int main()
{
    char a[100];
    strcpy(a,"tat343");

    char b[100];
    strcpy(b,"erte23");

    admin_database db;
    cout<<db.login(a,b);

}