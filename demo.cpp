#include<iostream>
#include<fstream>
#include"book_database.h"

int main()
{
    ifstream ifile("book",ios::in);
    book b;
    while(ifile.read((char*)&b,sizeof(b)))
    {
        b.display();
    }
    ifile.close();
}