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
            cout<<"Quantity : ";
            cin>>quantity;
            cin.ignore();
        }
        void display()
        {
            cout<<"-----------------------------------"<<endl;
            cout<<"BookID : "<<bookId<<endl
                <<"Name: "<<name<<endl
                <<"Author: "<<author<<endl
                <<"Genre : "<<genre <<endl
                <<"Publisher : "<<pub<<endl
                <<"Quantity : "<<quantity<<endl;
            cout<<"-----------------------------------"<<endl;
        }
        int get_bookID(){return bookId;}
        int get_quantity(){return quantity;}
        char* get_name(){return name;}
        char* get_publisher(){return pub;}
        char* get_genre(){return genre;}
        char* get_author(){return author;}

        int set_quantity(int quan){quantity=quan;}
        char* set_name(char *nam){strcpy(name,nam);}
        char* set_publisher(char* publisher){strcpy(pub,publisher);}
        char* set_genre(char* gen){strcpy(gen, genre);}
        char* set_author(char *auth){strcpy(auth,author);}

    
};