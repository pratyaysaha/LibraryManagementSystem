#include<iostream>
#include<fstream>
#include<vector>
#include"book.h"
using namespace std;

class book_database
{
    public:
        bool upload(book &b)    
        {
            ofstream ofile("book",ios::out|ios::app);
            if(!ofile){cout<<"Error"<<endl; return false;}
            ofile.write((char*)&b, sizeof(b));
            ofile.close();
            return true;
        }
        vector<book> download()
        {
            vector<book> all_data;
            book b;
            ifstream ifile("book",ios::in);
            if(!ifile){cout<<"Error"<<endl; return all_data;}
            while(ifile.read((char*)&b,sizeof(b)))
            {
                all_data.push_back(b);
            }
            ifile.close();
            return all_data;
        }
};