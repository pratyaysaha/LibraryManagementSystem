#include<iostream>
#include<fstream>
#include<vector>
#include<string.h>
#include<string>

#include"issue.h"

using namespace std;

class issue_database
{
    public:
        bool upload(issue &b)    
        {
            ofstream ofile("issue",ios::out|ios::app);
            if(!ofile){cout<<"Error"<<endl; return false;}
            ofile.write((char*)&b, sizeof(b));
            ofile.close();
            log("upload 1 issue");
            return true;
        }
        void upload(int k)
        {
            bool check;
            for(int i=0;i<k;i++)
            {
                issue b;
                b.new_issue();
                check=upload(b);
                if(check){cout<<"Data "<<i+1<<" is/are uploaded!!"<<endl;}
                else {cout<<"Not Uploaded !!"<<endl;return;}
            }
        }
        vector<issue> download()
        {
            vector<issue> all_data;
            issue b;
            ifstream ifile("issue",ios::in);
            if(!ifile){cout<<"Error"<<endl; return all_data;}
            while(ifile.read((char*)&b,sizeof(b)))
            {
                all_data.push_back(b);
            }
            ifile.close();
            log("downloaded all books");
            return all_data;
        }

        bool extract(vector<issue> &info)
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

        vector<issue> all_unreturn_book()
        {
            vector<issue> all_data;
            issue b;
            ifstream ifile("issue",ios::in);
            if(!ifile){cout<<"Error"<<endl; return all_data;}
            while(ifile.read((char*)&b,sizeof(b)))
            {
                if(b.get_isReturn()==false)
                {
                    all_data.push_back(b);
                }
            }
            ifile.close();
            log("downloaded all ureturned issues");
            return all_data;
        }
        bool return_a_book(int issueid)
        {
            issue b;
            fstream ifile;
            bool res= true, check;
            int bookid;
            int pos;
            int found=0;
            ifile.open("issue",ios::in|ios::out);
            if(!ifile){cout<<"Error"<<endl;return false;}
            while(!ifile.eof())
            {
                pos=ifile.tellg();
                ifile.read((char*)&b, sizeof(b));
                if(b.get_issueid()==issueid)
                {
                    if(b.get_isReturn()){cout<<"Already updated!!"<<endl; return false;}
                    b.set_isReturn();
                    bookid=b.get_bookid();
                    found=1;
                    ifile.seekg(pos);
                    ifile.write((char*)&b,sizeof(b));
                    break;
                }
            }
            ifile.close();
            if (found == 1)
            {
                book b;
                fstream ifile;
                bool res = true;
                int pos;
                int found = 0;
                ifile.open("book", ios::in | ios::out);
                if (!ifile)
                {
                    cout << "Error" << endl;
                    return false;
                }
                while (!ifile.eof())
                {
                    pos = ifile.tellg();
                    ifile.read((char *)&b, sizeof(b));
                    if (b.get_bookID() == bookid)
                    {
                        b.set_presenQuanincement();
                        ifile.seekg(pos);
                        ifile.write((char *)&b, sizeof(b));
                        break;
                    }
                }
            }
            else
            {
                cout<<"Record not found"<<endl;
                return false;
            }
            return true;
        }

        void log(string work)
        {
            ofstream ofile;
            ofile.open("log.txt",ios::out|ios::app);
            time_t now = time(0);
            string dt = ctime(&now);
            dt= dt+ " ::::::: "+ work;
            ofile<<dt<<endl;
            ofile.close();
        }
};

