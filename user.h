#include<iostream>
#include<string.h>
using namespace std;
class user
{
    protected:
        char name[100], user_id[100], gender[10];
        long phone;
    private:
        char username[100], password[100];
    public:
        user():name(),gender(){}
        void new_user()
        {
            cout<<"Name : ";
            cin.ignore();
            cin.getline(name,100);
            cout<<"User Id : ";
            cin.getline(user_id,100);
            cout<<"Gender : ";
            cin.getline(gender,10);
            cout<<"Phone Number : ";
            cin>>phone;
            cout<<"Username : ";
            cin>>username;
            cout<<"password : ";
            cin.getline(password,100);
        }
        void display()
        {
            cout<<"--------------------------------------"<<endl;
            cout<<"Name : "<<name<<endl
                <<"Username : "<<username<<endl
                <<"User ID : "<<user_id<<endl
                <<"Gender : "<<gender<<endl
                <<"Phone Number : "<<phone<<endl;
            cout<<"--------------------------------------"<<endl;
        }
        char* get_user_id(){return user_id;}
        char* get_username(){return username;}
        char* get_password(){return password;}
        char* get_name(){return name;}
        long get_phone(){return phone;}
};
int main()
{
    user u1;
    u1.new_user();
    u1.display();
}