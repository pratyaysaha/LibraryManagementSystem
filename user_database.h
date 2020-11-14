
#include<iostream>
#include<fstream>
#include<vector>
#include "user.h"
using namespace std;

class user_database
{
    public:
        bool upload(user &ad)
        {
            ofstream ofile;
            ofile.open("user.bin",ios::out|ios::app|ios::binary);
            if(!ofile){cout<<"Error!!"<<endl; return false;}
            ofile.write((char*)&ad,sizeof(ad));
            ofile.close();
            create_user(ad.get_user_id());
            return true;
        }
        vector<user> download()
        {
            vector<user> data;
            user ad;
            ifstream ifile;
            ifile.open("user.bin",ios::in|ios::binary);
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
            ifile.open("user.bin",ios::in|ios::binary);
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
            ifile.open("user.bin",ios::in|ios::binary);
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
        vector<user> login(char* uname, char* pass)
        {
            cout<<uname<<" "<<pass<<endl;
            user ad;
            ifstream ifile;
            vector<user> login_det;
            ifile.open("user.bin",ios::in|ios::binary);
            while(ifile.read((char*)&ad,sizeof(ad)))
            {
                if((strcmp(ad.get_username(),uname)==0) && (strcmp(ad.get_password(),pass)==0))
                {
                    login_det.push_back(ad);
                    break;
                }
            }
            ifile.close();
            return login_det;
        }
        bool create_user(char *userid)
        {
            bool check=true;
            char path[]="userfolder/";
            strcat(userid,".bin");
            strcat(path,userid);
            ofstream ofile(path, ios::out|ios::app|ios::binary);
            if(!ofile){cout<<"error"<<endl; check=false;}
            ofile.close();
            return check;
        }
        bool user_delete(char *userid)
        {
            user b;
            int found=0;
            char choice;
            ofstream ofile("temp.bin",ios::out|ios::app|ios::binary);
            ifstream ifile("user.bin",ios::in|ios::binary);
            if(!ifile){cout<<"Error"<<endl; return false;}
            while(ifile.read((char*)&b,sizeof(b)))
            {
                if(strcmp(b.get_user_id(),userid)==0)
                {
                    b.display();
                    found=1;
                    cout<<"Do you want to delete ? (y/n) : ";
                    cin>>choice;
                    if(choice=='n'||choice=='N')
                    {
                        ofile.write((char*)&b,sizeof(b));
                    }
                }
                else
                {
                    ofile.write((char*)&b,sizeof(b));
                }
            }
            ifile.close();
            ofile.close();
            remove("user.bin");
            rename("temp.bin","user.bin"); 
            ifile.open("user.bin",ios::in|ios::binary);
            if(!ifile){cout<<"Database got Corrupted !!"; return false;}
            ifile.close();
            if(found==0)
            {
                cout<<"Record not Found !! ";
                return false;
            }
            if(choice=='y'||choice=='Y')
            {
                cout<<"Deleted succefully"<<endl;
            }
            else
            {
                cout<<"Delete Aborted!!!"<<endl;
            }
            char path[]="userfolder/"; 
            strcat(userid,".bin");
            strcat(path,userid);
            //cout<<path<<endl;
            remove(path);
            return true;
        }
};