#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class admin
{
    protected:
        char name[100], admin_id[100], gender[10];
    private:
        char username[100], password[100];
    public:
        admin():name("name"),gender("gender"){}
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
        friend void search(char element[]);
};

void upload(admin &ad)
{
    ofstream ofile;
    ofile.open("admin",ios::out|ios::app);
    ofile.write((char*)&ad,sizeof(ad));
    ofile.close(); 
}

void download()
{
    admin ad;
    ifstream ifile;
    ifile.open("admin",ios::in);
    while(ifile.read((char*)&ad,sizeof(ad)))
    {
        ad.display();
    }
    ifile.close();
}
void search(char element[])
{
    cout<<"Key :"<<element<<endl;
    admin ad;
    ifstream ifile;
    ifile.open("admin",ios::in);
    while(ifile.read((char*)&ad,sizeof(ad)))
    {
        if(strcmp(ad.admin_id,element)==0)
        {
            ad.display();
        }
    }
    ifile.close();
}
int main()
{
    admin ad;
    // ad.new_admin();
/* 
    ofstream ofile;
    ofile.open("admin",ios::out|ios::app);
    ofile.write((char*)&ad,sizeof(ad));
    ofile.close(); 

    ifstream ifile;
    ifile.open("admin",ios::in);
    while(ifile.read((char*)&ad,sizeof(ad)))
    {
        ad.display();
    }
    ifile.close();
    cout<<"end"<<endl; */

    char ch[100];
    strcpy(ch,"pop231");
    
    search(ch);
}