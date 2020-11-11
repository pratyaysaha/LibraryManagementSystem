#include<iostream>
#include<string>
#include<vector>
#include<windows.h>
#include"admin_database.h"
#include"issue_database.h"
//#include"user_database.h" // already included in issue.h
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
                <<"12. Update a BOOK"<<endl<<endl
                <<"13. Issue a Book"<<endl
                <<"14. Get all Issues"<<endl 
                <<"15. Return a book"<<endl
                <<"16. Get all Un-returned issues"<<endl
                <<"------------------------------"<<endl
                <<"USER : "<<endl<<endl
                <<"17. Add a user"<<endl
                <<"18. Add Multiple USER"<<endl
                <<"19. Get all Users"<<endl
                <<"20. Search user by UserID"<<endl
                <<"21. Search user by UserName"<<endl
                <<"------------------------------"<<endl
                <<"-1. Exit"<<endl;
            cout<<"-----------------------------"<<endl;
            cout<<"Option : ";
            cin>>choice;
            admin_database adb;
            book_database bdb;
            issue_database idb;
            user_database udb;
            admin a;
            book b;
            issue i;
            user u;
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
                case 13:
                {
                    if(i.new_issue())
                    {
                        if(idb.upload(i))
                        {
                            cout<<"Added!!!"<<endl;
                        }
                        else
                        {
                            cout<<"error!!"<<endl;
                        }
                    }
                    else 
                        cout<<"error!!";
                    Sleep(1000);
                    system("cls");
                    menu();
                    break;
                }
                case 14:
                {
                    system("cls");
                    vector<issue> info =idb.download();
                    if(idb.extract(info)) {system("cls"); menu();}
                    else{exit(1);}
                    break;
                }
                case 15:
                {
                    cout<<"Enter the issueID : ";
                    cin>>dat;
                    if(idb.return_a_book(dat))
                        cout<<"Successful"<<endl;
                    else
                        cout<<"Error"<<endl;
                    Sleep(1000);
                    system("cls");
                    menu();
                    break;
                }
                case 16 :
                {
                    system("cls");
                    vector<issue> info =idb.all_unreturn_book();
                    if(idb.extract(info)) {system("cls"); menu();}
                    else{exit(1);}
                    break;
                }
                case 17:
                {
                    u.new_user();
                    if(udb.upload(u)){cout<<"User added"<<endl;}
                    else
                    {
                        cout<<"Not uploaded!!"<<endl;
                    }
                    Sleep(1000);
                    system("cls");
                    menu();
                    break;
                    
                }
                case 18:
                {
                    system("cls");
                    menu();
                    break;
                }
                case 19:
                {
                    system("cls");
                    vector<user> info=udb.download();
                    if(udb.extract(info)) {system("cls"); menu();}
                    else{exit(1);}
                    break;

                }
                case 20:
                {
                    system("cls");
                    cout<<"Enter the user ID : ";
                    cin.getline(key,100);
                    vector<user> info=udb.searchbyUserID(key);
                    if(udb.extract(info)) {system("cls"); menu();}
                    else{exit(1);}
                    break;
                }
                case 21:
                {
                    system("cls");
                    cout<<"Enter the user name : ";
                    cin.getline(key,100);
                    vector<user> info=udb.searchbyName(key);
                    if(udb.extract(info)) {system("cls"); menu();}
                    else{exit(1);}
                    break;
                }
                case 100:
                {
                    adb.open_log();
                    Sleep(1000);
                    system("cls");
                    menu();
                }
                case 101:
                {
                    remove("issue.bin");
                    system("cls");
                    menu();
                }
                case 102:
                {
                    remove("user.bin");
                    system("cls");
                    menu();
                }
                case 103:
                {
                    remove("admin.bin");
                    system("cls");
                    menu();
                }
                case 104:
                {
                    remove("book.bin");
                    system("cls");
                    menu();
                }
                default:
                {
                    cout<<"wrong choice!!";
                    Sleep(1000);
                    system("cls");
                    menu();
                }  
            } 
        }
        

};