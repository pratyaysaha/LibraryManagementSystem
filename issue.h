#include<iostream>
#include<fstream>
#include <ctime>
#include<string>
#include"book_database.h"
using namespace std;


class issue
{
    private: 
        int issueid;
        int bookid;
        char userid[100], adminid[100];
        char issue_date[100], return_date[100];
        bool isreturn;
    public:
        issue():bookid(0),isreturn(false){};
        bool new_issue()
        {
            time_t now = time(0);
            tm *ltm = localtime(&now);
            cout<<"BookID : ";
            cin>>bookid;
            cout<<endl<<"Is this the book ? "<<endl;
            if(!book_check(bookid)){cout<<"No Book"<<endl; return false;}
            cout<<"Issue ID : ";
            cin>>issueid;
            cout<<"UserID : ";
            cin.ignore();
            cin.getline(userid,100);
            cout<<"AdminID : ";
            cin.getline(adminid,100);
            string idate= to_string(ltm->tm_mday)+"."+to_string(1+ltm->tm_mon)+"."+to_string(1900 + ltm->tm_year);
            strcpy(issue_date,idate.c_str());
            isreturn=false;
            strcpy(return_date,return_date_calc().c_str());
            reduce_presentQuntity(bookid);
            return true;
        }
        void display()
        {
            cout<<"--------------------------------------"<<endl;
            cout<<"IssueID : "<<issueid<<endl
                <<"UserID : "<<userid<<endl
                <<"AdminID : "<<adminid<<endl
                <<"BookID : "<<bookid<<endl
                <<"Issue date : "<<issue_date<<endl
                <<"Return date : "<<return_date<<endl
                <<"Returned : "<<(isreturn?"RETURNED":"NO")<<endl;
            cout<<"--------------------------------------"<<endl;
        }
        string return_date_calc()
        {
            int month[12] = {31, 28, 31, 30, 31, 30, 
                      31, 31, 30, 31, 30, 31 }; 
            time_t now = time(0);
            tm *ltm = localtime(&now);

            ltm->tm_mday+=10;
            if(ltm->tm_mday> month[ltm->tm_mon])
            {
                ltm->tm_mday-=month[ltm->tm_mon];
                if(ltm->tm_mon==11)
                {
                    ltm->tm_mon=0;
                    ltm->tm_year+=1;
                }
                else
                    ltm->tm_mon+=1;
            }
            string rdate= to_string(ltm->tm_mday)+"."+to_string(1+ltm->tm_mon)+"."+to_string(1900 + ltm->tm_year);
            return rdate;
        }
        bool book_check(int bookid)
        {
            bool check=false,check2=false;
            book b;
            ifstream ifile("book",ios::in);
            if(!ifile){cout<<"Error"<<endl; return false;}
            while(ifile.read((char*)&b,sizeof(b)))
            {
                if(b.get_bookID()==bookid)
                {
                    b.display();
                    check=true;
                    break;
                }
            }
            ifile.close();
            if(b.get_presentQuan()>0) check2=true;
            return check&&check2;
        }
        bool reduce_presentQuntity(int bookid)
        {
            book b;
            fstream ifile;
            bool res= true;
            int pos;
            int found=0;
            ifile.open("book",ios::in|ios::out);
            if(!ifile){cout<<"Error"<<endl;return false;}
            while(!ifile.eof())
            {
                pos=ifile.tellg();
                ifile.read((char*)&b, sizeof(b));
                if(b.get_bookID()==bookid)
                {
                    b.set_presentQuan();
                    ifile.seekg(pos);
                    ifile.write((char*)&b,sizeof(b));
                    break;
                }
            }
            ifile.close();
            return true;
        }
        bool get_isReturn(){return isreturn;}
        char* get_returndate(){return return_date;}
        char* get_issuedate(){return issue_date;}
        char* get_userid(){return userid;}
        char* get_adminid(){return adminid;}
        int get_bookid(){return bookid;}
        int get_issueid(){return issueid;}

        void set_isReturn(){isreturn=true;}
};
