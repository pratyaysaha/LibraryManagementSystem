#include<iostream>
using namespace std;

class book
{
    private:
        int bookId, quantity;
        char name[100], author[100], genre[100],pub[100];
    public:
        book():bookId(-1),quantity(-1){}
        void new_book()
        {
            cout<<"BookID : ";
            cin>>bookId;
            cin.ignore();
            cout<<"Name : ";
            cin.getline(name,100);
            cout<<"Author : ";
            cin.getline(author,100);
            cout<<"Genre : ";
            cin.getline(genre,100);
            cout<<"Pub : ";
            cin.getline(pub,100);
        }
        void display()
        {
            cout<<"-----------------------------------"<<endl;
            cout<<"BookID : "<<bookId<<endl
                <<"Name: "<<name<<endl
                <<"Author: "<<author<<endl
                <<"Genre : "<<genre <<endl
                <<"Publisher : "<<pub<<endl;
            cout<<"-----------------------------------"<<endl;
        }
};