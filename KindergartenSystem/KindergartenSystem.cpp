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

//It counts the administrators
int adminCounter = 0;

//Parent's child data
struct CHILD
{
    string name;
    int age;
};

//Parent's data
struct PARENT
{
    int ID;
    string parentUsername;
    string parentPass;
    string firstName;
    string lastName;
    string address;
    CHILD childData;
};

//creates administrator 
void logInAsAdmin()
{
    cout << "Please, enter your username: "; 
    cin>>adminUsername;
    cout << "Please, enter your password: ";
    cin >> adminPass;
    adminCounter++;
}

//It must do something....
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

//Creates parent's profile
void createParentProfile(PARENT user[], int& parentCounter)
{
    cout << "\nEnter parent's Id: " << endl;
    cin >> user[parentCounter].ID;

    cout << "\nEnter parent's username: " << endl;
    cin >> user[parentCounter].parentUsername;

    cout << "\nEnter parent's password: " << endl;
    cin >> user[parentCounter].parentPass;

    cout << "\nEnter parent's first name: " << endl;
    cin >> user[parentCounter].firstName;

    cout << "\nEnter parent's last name: " << endl;
    cin >> user[parentCounter].lastName;

    cout << "\nEnter parent's address: " << endl;
    cin >> user[parentCounter].address;

    cout << "\nEnter parent's child name: " << endl;
    cin >> user[parentCounter].childData.name;

    cout << "\nEnter parent's child age: " << endl;
    cin >> user[parentCounter].childData.age;

    parentCounter++;
}

bool mainMenu(PARENT* user, int& parentCounter)
{
    int choice;
    if (adminCounter == 0 && parentCounter == 0)
    {
        cout << "There aren't any users currently logged!" << endl;
        cout << "Please log in as administrator first!" << endl;
        logInAsAdmin();
        accessLevel(adminUsername, adminPass);
    }
    else
    {
        cout << "\n1: Create parent profile." << endl;
        cout << "2: Show full parents list." << endl;
        cout << "3. Show parent by Id." << endl;
        cout << "4. Show parent by Id." << endl;
        //cout << "3: Switch profile." << endl;
        cout << "0: Exit!" << endl << endl;
        cout << "Please enter your choice: "; cin >> choice;
        switch (choice)
        {
        case 1:
            createParentProfile(user, parentCounter);
            break;
        /*case 3:
            int caseOneChoice;
            
            cout << "\n1 : Log in as admin.\n2 : Log in as parent." << endl;
            cout << "Your choice: "; cin >> caseOneChoice;
            if (caseOneChoice == 1)
            {
               logInAsAdminSecondTime();
               accessLevel(adminUsername, adminPass);
            }
            if (caseOneChoice == 2)
            {

            }
            break;*/
        case 0:
            return false;
            break;
            
            return true;
        }
    }
}

int main()
{
    PARENT user[100];
    int parentCounter = 0;
    bool doShowMenu = true;
    do {
        mainMenu(user, parentCounter);
        if (mainMenu(user,parentCounter) == false)
        {
            return 0;
        }
    } while (doShowMenu);
}