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

int adminCounter = 0;

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

void logInAsAdmin()
{
    cout << "Please, enter your username: "; 
    cin>>adminUsername;
    cout << "Please, enter your password: ";
    cin >> adminPass;
    adminCounter++;
}
void logInAsAdminSecondTime()
{
    string adminUsernameCheck;
    string adminPassCheck;
    
    do
    {
        cout << "Please, enter your username: "; cin >> adminUsernameCheck;
        cout << "Please, enter your password: "; cin >> adminPassCheck;
        if (adminUsernameCheck != adminUsername || adminPassCheck != adminPass)
        {
            cout << "\nWrong input!" << endl;
        }

    } while (adminUsernameCheck != adminUsername || adminPassCheck != adminPass);
    
}


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

void createParentAcc(PARENT user[], int& parentCount)
{
    cout << "\nEnter parent's Id: " << endl;
    cin >> user[parentCount].ID;



    cout << "\nEnter parent's username: " << endl;
    cin >> user[parentCount].parentUsername;



    cout << "\nEnter parent's password: " << endl;
    cin >> user[parentCount].parentPass;



    cout << "\nEnter parent's first name: " << endl;
    cin >> user[parentCount].firstName;



    cout << "\nEnter parent's last name: " << endl;
    cin >> user[parentCount].lastName;



    cout << "\nEnter parent's address: " << endl;
    cin >> user[parentCount].address;



    parentCount++;



}

bool mainMenu(PARENT* user)
{
    int choice;
    cout << endl;
    cout << "1: Log in" << endl;
    cout << "2: Insert user." << endl;
    cout << "0: Exit!" << endl << endl;
    cout << "Please enter your choice: "; cin >> choice;
    switch (choice) 
    {
    case 1:
        int caseOneChoice;
        if (adminCounter == 0)
        {
            cout << "\nThere isnt administrator loged in yet. Please, log in as administrator!" << endl;
            logInAsAdmin();

        }
        else
        {
            cout<<"There is an admin you may choose between : \n1 : Log in as admin.\n2 : Log in as parent." << endl;
            cout << "Your choice: "; cin >> caseOneChoice;

            if (caseOneChoice==1)
            {
                logInAsAdminSecondTime();
                accessLevel(adminUsername, adminPass);
            }
        }
        
        
        
        
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
    PARENT user[100];
    int parentCount = 0;
    bool doShowMenu = true;
    do {
        mainMenu(user);
        if (mainMenu(user) == false)
        {
            return 0;
        }
    } while (doShowMenu);
}