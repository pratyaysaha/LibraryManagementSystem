#include<iostream>
#include<string>
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
                <<"8.  Get all BOOK Data"<<endl
                <<"9.  Search" <<endl
                <<"10. Delete a BOOK"<<endl
                <<"11. Update a BOOK"<<endl;
                //user part to be added
            cout<<"-----------------------------"<<endl;
            cout<<"Option : ";
            cin>>choice;
            admin_database adb;
            book_database bdb;
            admin a;
            char key[100];
            
            switch(choice)
            {
                case 1:   
                    a.new_admin();
                    adb.upload(a);
                    break;

                case 2:
                    //extract function to be added
                    break;
                case 3:
                    cout<<"Admin ID: ";
                    cin.ignore();
                    cin.getline(key,100);
                    adb.searchbyAdminID(key);
                    
                    break;
                case 4:
                    cout<<"Admin Name : ";
                    cin.ignore();
                    cin.getline(key,100);


                    
            } 
        }
        

};