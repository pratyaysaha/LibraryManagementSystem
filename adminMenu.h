#include<iostream>
#include<string>
#include<vector>
#include<windows.h>
#include"admin_database.h"
#include"book_database.h"

using namespace std;

class admin_menu
{
    public:
        void menu()
        {
            int choice;
            cout<<"------------------------------"<<endl;
            cout<<"Administration Menu"<<endl;
            cout<<"------------------------------"<<endl;
            cout<<"ADMIN : "<<endl<<endl;
            cout<<"1.  Add an admin"<<endl
                <<"2.  Get all details of admin"<<endl
                <<"3.  Search an Admin By ID"<<endl
                <<"4.  Serach an Admin By Name"<<endl
                <<"5.  Delete an Admin"<<endl
                <<"6.  Update an Admin"<<endl
                <<"------------------------------"<<endl
                <<"BOOK : "<<endl<<endl
                <<"7.  Add a BOOK"<<endl
                <<"8.  Add mutiple BOOK"<<endl
                <<"9.  Get all BOOK Data"<<endl
                <<"10. Search" <<endl
                <<"11. Delete a BOOK"<<endl
                <<"12. Update a BOOK"<<endl
                //user part to be added
                <<"-1. Exit"<<endl;
            cout<<"-----------------------------"<<endl;
            cout<<"Option : ";
            cin>>choice;
            admin_database adb;
            book_database bdb;
            admin a;
            book b;
            int dat;
            char key[100];
            
            switch(choice)
            {
                case -1:
                {
                    cout<<"Thank you !!";
                    Sleep(1000);
                    exit(1);
                }
                case 1:   
                {
                    if(!adb.masterLogin()){Sleep(1000); system("cls"); menu();}
                    a.new_admin();
                    adb.upload(a);
                    Sleep(1000);
                    system("cls");
                    menu();
                    break;
                }

                case 2:
                {
                    vector<admin> info=adb.download();
                    system("cls");
                    if(adb.extract(info)) {system("cls"); menu();}
                    else{exit(1);}
                    break;
                }
                case 3:
                {
                    cout<<"Admin ID: ";
                    cin.ignore();
                    cin.getline(key,100);
                    vector<admin> info= adb.searchbyAdminID(key);
                    system("cls");
                    if(adb.extract(info)) {system("cls"); menu();}
                    else{exit(1);}
                    break;
                }
                case 4:
                {
                    cout<<"Admin Name : ";
                    cin.ignore();
                    cin.getline(key,100);
                    vector<admin> info= adb.searchbyName(key);
                    if(adb.extract(info)) {system("cls"); menu();}
                    else{exit(1);}
                    break;
                }
                case 5:
                {
                    if(!adb.masterLogin()){Sleep(1000); system("cls"); menu();}
                    cout<<"Admin ID : ";
                    cin.ignore();
                    cin.getline(key,100);
                    // delete function to be added
                    break;
                }
                case 6:
                {
                    if(!adb.masterLogin()){Sleep(1000); system("cls"); menu();}
                    cout<<"Admin ID : ";
                    cin.ignore();
                    cin.getline(key,100);
                    //update function to be added
                    break;
                }
                case 7:
                {
                    b.new_book();
                    if(bdb.upload(b)){cout<<"Uploaded succesfully !!"<<endl;}
                    else{ cout<<"Error!!!!"<<endl;}
                    Sleep(1000);
                    system("cls");
                    menu();
                    break;
                }
                case 8:
                {
                    system("cls");
                    cout<<"Number of data to be uploaded : ";
                    cin>>dat;
                    bdb.upload(dat);
                    menu();
                    break;
                }
                case 9:
                {
                    system("cls");
                    vector<book> info =bdb.download();
                    if(bdb.extract(info)) {system("cls"); menu();}
                    else{exit(1);}
                    break;
                }
                case 10:
                {
                    system("cls");
                    if(bdb.searchMenu()){system("cls"); menu();}
                    break;
                }
                case 11:
                {
                    cout<<"Enter the BOOK ID to be deleted : ";
                    cin>>dat;
                    if(bdb.deleteRecord(dat)) {Sleep(1000); system("cls"); menu();}
                    break;
                }
                case 12:
                {
                    system("cls");
                    cout<<"Enter the BOOK ID to be Updated : ";
                    cin>>dat;
                    bdb.modify(dat);
                    Sleep(1000);
                    system("cls");
                    menu();
                    break;
                }
                case 100:
                {
                    adb.open_log();
                    Sleep(1000);
                    system("cls");
                    menu();
                }
                    
            } 
        }
        

};