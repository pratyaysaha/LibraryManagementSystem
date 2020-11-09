
#include<iostream>
#include<fstream>
#include<vector>
#include "user.h"
using namespace std;

class user_database
{
    public:
        void upload(user &ad)
        {
            ofstream ofile;
            ofile.open("user",ios::out|ios::app);
            ofile.write((char*)&ad,sizeof(ad));
            ofile.close();
        }
        vector<user> download()
        {
            vector<user> data;
            user ad;
            ifstream ifile;
            ifile.open("user",ios::in);
            while(ifile.read((char*)&ad,sizeof(ad)))
            {
                data.push_back(ad);
            }
            ifile.close();
            return data;
        }
        bool extract(vector<user> &info)
        {
            if(info.size()==0){cout<<"No data"<<endl;}
            for(int i=0;i<info.size();i++)
            {
                info[i].display();
            }
            cout<<"Total Data : "<<info.size()<<endl;
            cout<<"Return to Menu (y/n) : ";
            char choice;
            cin>>choice;
            if(choice=='y'||choice=='Y')
                return true;
            else
                return false;
        }
        vector<user> searchbyUserID(char element[])
        {
            vector<user> searchRes;
            cout<<"Key :"<<element<<endl; 
            user ad;
            ifstream ifile;
            ifile.open("user",ios::in);
            while(ifile.read((char*)&ad,sizeof(ad)))
            {
                if(strcmp(ad.get_user_id(),element)==0)
                {
                    searchRes.push_back(ad);
                }
            }
            ifile.close();
            return searchRes;
        }

        vector<user> searchbyName(char *Name)
        {
            vector<user> searchRes;
            cout<<"Key : "<<Name<<endl;
            user ad;
            ifstream ifile;
            ifile.open("user",ios::in);
            while(ifile.read((char*)&ad,sizeof(ad)))
            {
                if(strcmp(ad.get_name(),Name)==0)
                {
                    searchRes.push_back(ad);
                }
            }
            ifile.close();
            return searchRes;
            
        }
        bool login(char* uname, char* pass)
        {
            cout<<uname<<" "<<pass<<endl;
            user ad;
            ifstream ifile;
            ifile.open("user",ios::in);
            while(ifile.read((char*)&ad,sizeof(ad)))
            {
                if((strcmp(ad.get_username(),uname)==0) && (strcmp(ad.get_password(),pass)==0))
                {
                    return true;
                }
            }
            ifile.close();
            return false;
        }
};