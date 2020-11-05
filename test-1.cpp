#include<iostream>
#include<vector>
#include"admin_database.h"
#include"book_database.h"


using namespace std;

int main()
{
    book b;
    book_database db;
   // b.new_book();
    //db.upload(b);

    vector<book> info=db.download();
    for(int i=0;i<info.size();i++)
    {
        info[i].display();
    }

    

}