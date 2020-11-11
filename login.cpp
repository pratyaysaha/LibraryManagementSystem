#include<iostream>
#include<fstream>
#include"adminMenu.h"

using namespace std;
void login_menu()
{
    int choice;
    cout<<endl<<endl<<endl;
    cout<<"=============================="<<endl;
    cout<<"\t  LibSys"<<endl;
    cout<<"=============================="<<endl;
    cout<<"1. ADMIN"<<endl;
    cout<<"2. USER"<<endl;
    cout<<"------------------------------"<<endl;
    cout<<"Option : ";
    cin>>choice;
    char uname[100];
    char pass[100];
    switch(choice)
    {
        case 1:
        {
            cout<<"ADMIN LOGIN : "<<endl;
            cout<<"---------------------------"<<endl;
            cout<<"Username : ";
            cin.ignore();
            cin.getline(uname,100);
            cout<<"Password : ";
            cin.getline(pass,100);
            admin_database adb;
            
            if(adb.login(uname,pass))
            {
                system("cls");
                admin_menu ad;
                ad.menu();
            }
            else
            {
                cout<<" Wrong Username or Password!!!"<<endl;
                Sleep(1000);
                system("cls");
                login_menu();
            }
            break;
        }
        case 2:
            system("cls");
            //not yet done
            cout<<"not yet added"<<endl;
            Sleep(1000);
            login_menu();
            break;
            
    }

}




int main()
{   
    
    login_menu();
}