#include<iostream>
#include<vector>
#include"admin_database.h"
#include"book_database.h"


using namespace std;

int main()
{
    book b;
    book_database db;
    /* for(int i=0;i<5;i++)
    {
        b.new_book();
        db.upload(b); 
    } */
    char a[100];
    strcpy(a,"penguin");

    vector<book> info=db.searchByPublisher(a);
    for(int i=0;i<info.size();i++)
    {
        info[i].display();
    } 
    
    

}