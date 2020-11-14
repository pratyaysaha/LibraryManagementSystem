#include<iostream>
#include<fstream>
#include<windows.h>
#include"adminMenu.h"
#include"userMenu.h"

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
        case -1:
        {
            cout<<"Thank you!!!";
            Sleep(1000);
            exit(1);
            break;
        }
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
        {
           cout<<"USER LOGIN : "<<endl;
            cout<<"---------------------------"<<endl;
            cout<<"Username : ";
            cin.ignore();
            cin.getline(uname,100);
            cout<<"Password : ";
            cin.getline(pass,100);
            user_database udb;
            vector<user> login_det=udb.login(uname,pass);
            if(login_det.size()>0)
            {
                system("cls");
                user_menu um;
                um.menu(login_det);
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
        default:
            cout<<"Wrong choice. Try Again!!"<<endl;
            Sleep(1000);
            system("cls");
            login_menu();
    }

}

int main()
{   
    
    login_menu();
}