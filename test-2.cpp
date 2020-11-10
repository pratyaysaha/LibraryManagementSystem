#include<iostream>
#include<vector>

#include"adminMenu.h"
using namespace std;

int main()
{
    issue_database idb;
    issue i;
    if(i.new_issue())idb.upload(i);
    vector<issue> info=idb.download();
    idb.extract(info);
   // idb.return_a_book();

}