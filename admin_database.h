#include<iostream>
#include<fstream>
#include<vector>
#include"admin.h"
using namespace std;

class admin_database
{
    public:
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
        bool extract(vector<admin> &info)
        {
            if(info.size()==0){cout<<"No data"<<endl; return false;}
            for(int i=0;i<info.size();i++)
            {
                info[i].display();
            }
            cout<<"Return to Menu (y/n) : ";
            char choice;
            cin>>choice;
            if(choice=='y'||choice=='Y')
                return true;
            else
                return false;
        }
        vector<admin> searchbyAdminID(char element[])
        {
            vector<admin> searchRes;
            cout<<"Key :"<<element<<endl; 
            admin ad;
            ifstream ifile;
            ifile.open("admin",ios::in);
            while(ifile.read((char*)&ad,sizeof(ad)))
            {
                if(strcmp(ad.get_admin_id(),element)==0)
                {
                    searchRes.push_back(ad);
                }
            }
            ifile.close();
            return searchRes;
        }

        vector<admin> searchbyName(char *Name)
        {
            vector<admin> searchRes;
            cout<<"Key : ";
            admin ad;
            ifstream ifile;
            ifile.open("admin",ios::in);
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
            admin ad;
            ifstream ifile;
            ifile.open("admin",ios::in);
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