#include <iostream>
#include <cstdio>
#include <string>


using namespace std;

string adminUsername = "admin";
string adminPass = "adminpass";

struct PARENT
{
    int ID;
    string parentUsername;
    string parentPassword;
    string firstName;
    string lastName;
    string address;
    CHILD childData;
};

struct CHILD
{
    string name;
    int address;
};



int main()
{

}