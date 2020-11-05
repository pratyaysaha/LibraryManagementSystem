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

        vector<book> searchByBookID(int id)
        {
            vector<book> all_data;
            book b;
            ifstream ifile("book",ios::in);
            if(!ifile){cout<<"Error"<<endl; return all_data;}
            while(ifile.read((char*)&b,sizeof(b)))
            {
                if(b.get_bookID()==id)
                {
                    all_data.push_back(b);
                    break;
                }
            }
            ifile.close();
            return all_data;
        }
        vector<book> searchByName(char *name)
        {
            vector<book> all_data;
            book b;
            ifstream ifile("book",ios::in);
            if(!ifile){cout<<"Error"<<endl; return all_data;}
            while(ifile.read((char*)&b,sizeof(b)))
            {
                if(strcmp(b.get_name(),name)==0)
                {
                    all_data.push_back(b);
                }
            }
            ifile.close();
            return all_data;
        }

        vector<book> searchByAuthor(char *auth)
        {
            vector<book> all_data;
            book b;
            ifstream ifile("book",ios::in);
            if(!ifile){cout<<"Error"<<endl; return all_data;}
            while(ifile.read((char*)&b,sizeof(b)))
            {
                if(strcmp(b.get_author(),auth)==0)
                {
                    all_data.push_back(b);
                }
            }
            ifile.close();
            return all_data;
        }

        vector<book> searchByPublisher(char *pub)
        {
            vector<book> all_data;
            book b;
            ifstream ifile("book",ios::in);
            if(!ifile){cout<<"Error"<<endl; return all_data;}
            while(ifile.read((char*)&b,sizeof(b)))
            {
                if(strcmp(b.get_publisher(),pub)==0)
                {
                    all_data.push_back(b);
                }
            }
            ifile.close();
            return all_data;
        }

        vector<book> searchByGenre(char *gen)
        {
            vector<book> all_data;
            book b;
            ifstream ifile("book",ios::in);
            if(!ifile){cout<<"Error"<<endl; return all_data;}
            while(ifile.read((char*)&b,sizeof(b)))
            {
                if(strcmp(b.get_genre(),gen)==0)
                {
                    all_data.push_back(b);
                }
            }
            ifile.close();
            return all_data;
        }



        
};