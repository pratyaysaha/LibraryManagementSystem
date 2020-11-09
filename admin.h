#include<iostream>
#include<string.h>
using namespace std;

class admin
{
    protected:
        char name[100], admin_id[100], gender[10];
    private:
        char username[100], password[100];
    public:
        admin():name(),gender(){}
        void new_admin()
        {
            cout<<"Name : ";
            cin.getline(name,100);
            cout<<"Administration Id : ";
            cin.getline(admin_id,100);
            cout<<"Gender : ";
            cin.getline(gender,10);
            cout<<"Username : ";
            cin.getline(username,100);
            cout<<"password : ";
            cin.getline(password,100);
        }
        void display()
        {
            cout<<"--------------------------------------"<<endl;
            cout<<"Name : "<<name<<endl
                <<"Admin ID : "<<admin_id<<endl
                <<"Gender : "<<gender<<endl<<endl;
            cout<<"--------------------------------------"<<endl;
        }
        char* get_admin_id()
        {
            return admin_id;
        }
        char* get_username()
        {
            return username;
        }
        char* get_password()
        {
            return password;
        }
        char* get_name()
        {
            return name;
        }
};
