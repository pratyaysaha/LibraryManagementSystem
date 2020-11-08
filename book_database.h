#include<iostream>
#include<fstream>
#include<vector>
#include<string.h>
#include<string>
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
            log("upload 1 book");
            return true;
        }
        void upload(int k)
        {
            bool check;
            for(int i=0;i<k;i++)
            {
                book b;
                b.new_book();
                check=upload(b);
                if(check){cout<<"Data "<<i+1<<" is/are uploaded!!"<<endl;}
                else {cout<<"Not Uploaded !!"<<endl;return;}
            }
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
            log("downloaded all books");
            return all_data;
        }

        bool extract(vector<book> &info)
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
            log("serarch by book id");
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
            log("serarch by book name");
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
            log("serarch by book author");
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
            log("serarch by book publisher");
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
            log("serarch by book genre");
            return all_data;
        }

        bool deleteRecord(int bookid)
        {
            book b;
            int found=0;
            char choice;
            ofstream ofile("temp",ios::out|ios::app);
            ifstream ifile("book",ios::in);
            if(!ifile){cout<<"Error"<<endl; return false;}
            while(ifile.read((char*)&b,sizeof(b)))
            {
                if(b.get_bookID()==bookid)
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

            remove("book");
            rename("temp","book");
            ifile.open("book",ios::in);
            if(!ifile){cout<<"Database got Corrupted !!"; return false;}
            ifile.close();
            if(found==0)
            {
                cout<<"Record not Found !! ";
                log("record book id : "+to_string(bookid)+" not found");
                return false;
            }
            if(choice=='y'||choice=='Y')
            {
                cout<<"Deleted succefully"<<endl;
                log("record book id : "+to_string(bookid)+" deleted successfull");
            }
            else
            {
                cout<<"Delete Aborted!!!"<<endl;
                log("record book id : "+to_string(bookid)+" deleted aborted");
            }
            
            return true;
        }
        bool try_again()
        {
            cout<<"Do you want to modify more? (y/n) :";
            char ch;
            cin>>ch;
            if(ch=='y'||ch=='Y')
                return true;
            return false;
        }
        void modify_menu(book &b)
        {
            cout<<"Modify : "<<endl
                <<"1. Name "<<endl
                <<"2. Author"<<endl
                <<"3. Genre"<<endl
                <<"4. Publisher"<<endl
                <<"5. Quantity to be added"<<endl;
            cout<<"Choice: ";
            int choice;
            cin>>choice;
            char mod[100];
            int q;
            char ch;
            switch(choice)
            {
                case 1 : 
                    cout<<"Name : ";
                    cin.ignore();
                    cin.getline(mod,100);
                    b.set_name(mod);
                   
                    break;
                case 2:
                    cout<<"Author : ";
                    cin.ignore();
                    cin.getline(mod,100);
                    b.set_author(mod);
                   
                    break;
                case 3: 
                    cout<<"Genre : ";
                    cin.ignore();
                    cin.getline(mod,10);
                    b.set_genre(mod);
                    
                    break;
                case 4:
                    cout<<"Publisher : ";
                    cin.ignore();
                    cin.getline(mod,100);
                    b.set_publisher(mod);
                    
                    break;
                case 5:
                    cout<<"Quantity to be added : ";
                    cin>>q;
                    b.set_quantity(q);
                    
                    break;
                default:
                    cout<<"Wrong choice!!";
                   
            }
            if(try_again()){modify_menu(b);}
        }
        bool modify(int bookid)
        {
            book b;
            fstream ifile;
            bool res= true;
            int pos;
            int found=0;
            ifile.open("book",ios::in|ios::out);
            if(!ifile){cout<<"Error"<<endl;log("modify error");return false;}
            while(!ifile.eof())
            {
                pos=ifile.tellg();
                ifile.read((char*)&b, sizeof(b));
                if(b.get_bookID()==bookid)
                {
                    b.display();
                    modify_menu(b);
                    found=1;
                    ifile.seekg(pos);
                    ifile.write((char*)&b,sizeof(b));
                    break;
                }
            }
            if (found==0) 
            { 
                cout<<"Record not found "<<endl; 
                log("record book id : "+to_string(bookid)+" not found to be modified");
                res=false;
            }
            else{ 
                cout<<"Modified Succesfully !!"<<endl; 
                log("record book id : "+to_string(bookid)+" modified successfull");            
            }
            ifile.close();
            return res;
        }
        bool searchMenu()
        {
            cout<<"Search : "<<endl
                <<"1. BookID "<<endl
                <<"2. Name"<<endl
                <<"3. Author"<<endl
                <<"4. Publisher"<<endl
                <<"5. Genre"<<endl
                <<"0. Get back to Main Menu"<<endl;
            cout<<"Choice: ";
            int choice;
            cin>>choice;
            char mod[100];
            int q;
            char ch;
            bool res=false;
            switch(choice)
            {
                case 1 : 
                {
                    cout<<"Id : ";
                    cin.ignore();
                    cin>>q;
                    vector<book> info= searchByBookID(q);
                    if(extract(info)){system("cls"); res=searchMenu();}
                    else{exit(1);}
                    break;
                }
                case 2:
                {
                    cout<<"Name : ";
                    cin.ignore();
                    cin.getline(mod,100);
                    vector<book> info= searchByName(mod);
                    if(extract(info)){system("cls");res= searchMenu();}
                    else{exit(1);}
                    break;
                }
                case 3: 
                {
                    cout<<"Author : ";
                    cin.ignore();
                    cin.getline(mod,10);
                    vector<book> info= searchByAuthor(mod);
                    if(extract(info)){system("cls"); res=searchMenu();}
                    else{exit(1);}
                    
                    break;
                }
                case 4:
                {
                    cout<<"Publisher : ";
                    cin.ignore();
                    cin.getline(mod,100);
                    vector<book> info= searchByPublisher(mod);
                    if(extract(info)){system("cls"); res=searchMenu();}
                    else{exit(1);}
                    break;
                }
                case 5:
                {
                    cout<<"Genre : ";
                    cin.ignore();
                    cin.getline(mod,100);
                    vector<book> info= searchByGenre(mod);
                    if(extract(info)){system("cls"); res=searchMenu();}
                    else{exit(1);}
                    break;
                }
                case 0:
                {
                    res=true;
                    break;
                }
                default:
                {
                    system("cls");
                    cout<<"Wrong choice!!"<<endl;
                    res= searchMenu();
                }
            }
            return res;
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
