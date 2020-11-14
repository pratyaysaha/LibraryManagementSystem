#include<iostream>
#include<vector>
#include<string>
#include<windows.h>
#include<fstream>

using namespace std;
class user_menu
{
    public:
        void menu(vector<user> log_det)
        {
            int choice;
            cout<<"------------------------------"<<endl;
            cout<<"User Menu"<<endl;
            cout<<"------------------------------"<<endl;
            cout<<"USER : "<<endl<<endl;
            cout<<"1.  Get all of your own details"<<endl
                <<"2.  Search a User By ID"<<endl
                <<"3.  Serach a User By Name"<<endl
                <<"4.  Delete Account"<<endl
                <<"5.  Update your details"<<endl
                <<"------------------------------"<<endl
                <<"BOOK : "<<endl<<endl
                <<"6.  Issue a BOOK"<<endl
                <<"7.  Get all the books"<<endl
                <<"8.  Search books" <<endl;
            cout<<"------------------------------"<<endl;
            cout<<"Option : ";
            cin>>choice;
            user_database adb;
            book_database bdb;
            issue_database idb;
            user a;
            book b;
            issue i;
            int dat;
            char key[100];
            switch(choice)
            {
                case 1:
                {
                    user u=log_det[0];
                    issue i;
                    int flag=0;
                    char *uid=u.get_user_id();
                    char path[]="userfolder/";
                    strcat(uid,".bin");
                    strcat(path,uid);
                    cout<<path<<endl;
                    ifstream ifile(path,ios::in|ios::binary);
                    if(!ifile){cout<<"error file not found!!"<<endl; Sleep(1000); system("cls"); menu(log_det);}
                    system("cls");
                    cout<<"Your Details :"<<endl;
                    u.display();
                    cout<<endl<<endl<<"Book issue History: "<<endl;
                    while(ifile.read((char *)&i, sizeof(i)))
                    {
                        i.display();
                        flag=1;
                    }
                    ifile.close();
                    if(flag==0){cout<<"No History!!!"<<endl;}
                    char choice;
                    cout<<"Return to main menu ? (y/n) : ";
                    cin>>choice;
                    if(choice=='y'||choice=='Y')
                    {
                        system("cls");
                        menu(log_det);
                    }
                    break;
                }
                case 2:
                {
                    system("cls");
                    cout<<"Enter the user ID : ";
                    cin.ignore();
                    cin.getline(key,100);
                    vector<user> info=adb.searchbyUserID(key);
                    if(adb.extract(info)) {system("cls"); menu(log_det);}
                    else{exit(1);}
                    break;
                }
                case 3:
                {
                    system("cls");
                    cout<<"Enter the name of user : ";
                    cin.ignore();
                    cin.getline(key,100);
                    vector<user> info=adb.searchbyName(key);
                    if(adb.extract(info)) {system("cls"); menu(log_det);}
                    else{exit(1);}
                    break;
                }
                case 4:
                {
                    if(adb.user_delete(log_det[0].get_user_id())) {Sleep(1000); system("cls"); menu(log_det);}
                    Sleep(1000);
                    menu(log_det);
                    break;
                }
                case 6:
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
                        menu(log_det);
                        break;
                }
                case 7:
                {
                    system("cls");
                    vector<book> info =bdb.download();
                    if(bdb.extract(info)) {system("cls"); menu(log_det);}
                    else{exit(1);}
                    break;
                }
                case 8:
                {
                    system("cls");
                    if(bdb.searchMenu()){system("cls"); menu(log_det);}
                    break;
                }
                case -1:
                {
                    cout<<"Thank you!!";
                    Sleep(1000);
                    exit(1);
                }
                default: 
                {
                    cout<<"wrong choice!!";
                    Sleep(1000);
                    system("cls");
                    menu(log_det);
                    break;
                }
            }
        }
};
