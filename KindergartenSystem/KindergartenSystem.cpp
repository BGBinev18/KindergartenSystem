#include <iostream>
#include <cstdio>
#include <string>


using namespace std;


//The only admin's username
string adminUsername = "empty";

//The only admin's password
string adminPass = "empty";

//It's value is true if the current user is admin and false if the user is parent 
bool isAdmin;


//Parent's data
struct PARENT
{
    int ID;
    string parentUsername;
    string parentPass;
    string firstName;
    string lastName;
    string address;
    //CHILD childData;
};

//Parent's child data
struct CHILD
{
    string name;
    int age;
};

////////////////////////////////////////void insertUserName()

//Checks if the current user is admin or not
bool accessLevel(string username, string password)
{
    if (username == adminUsername && password==adminPass)
    {
        isAdmin = true;
    }
    else
    {
        isAdmin = false;
    }

    return isAdmin;
}

bool mainMenu(PARENT* user)
{
    int choice;
    cout << endl;
    cout << "1: Insert user." << endl;
    cout << "0: Exit!" << endl << endl;
    cout << "Please enter your choice: ";
    switch (choice) 
    {
    case 1:

        break;
    case 2:
        
        break;
    case 0:
        return false;
        break;
    }
    return true;
}

int main()
{

}