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

//Generates max ID
int generateId(int& maxId)
{
    return maxId++;
}

//creates administrator 
void logInAsAdmin()
{
    cout << "Please, enter your username: ";
    cin >> adminUsername;
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
    if (username == adminUsername && password == adminPass)
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
void createParentProfile(PARENT user[], int& parentCounter, int& maxId)
{
    cout << "\n-----------------------------------------------------------" << endl;
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

    cout << "\n-----------------------------------------------------------" << endl;

    user[parentCounter].ID = generateId(maxId);

    parentCounter++;
}


void showParent(PARENT user)
{
    cout << "\n-----------------------------------------------------------" << endl;
    cout << "\nParent Id: " << user.ID << endl;
    cout << "Parent's username: " << user.parentUsername << endl;
    cout << "Parent's password: " << user.parentPass << endl;
    cout << "Parent's first name: " << user.firstName << endl;
    cout << "Parent's last name: " << user.lastName << endl;
    cout << "Parent's address: " << user.address << endl;
    cout << "Parent's child name: " << user.childData.name << endl;
    cout << "This parent's child is [" << user.childData.age << "] years old" << endl;
    cout << "\n-----------------------------------------------------------" << endl;
    cout << endl;
}


void showWholeParentsList(PARENT user[], int parentCounter)
{
    cout << "\nYou have entered the following employee:" << endl;
    for (int i = 0; i < parentCounter; i++)
    {
        showParent(user[i]);
    }
}


void showParentInfoById(PARENT* user, int& parentCounter)
{
    int id;
    cout << "\n-----------------------------------------------------------" << endl;
    cout << "\nPlease enter the id of the parent you want to be shown: "; cin >> id;
    for (int i = 0; i < parentCounter; i++)
    {
        if (id == user[i].ID)
        {
            showParent(user[i]);
        }
    }
}


int getParentById(PARENT* user, int& parentCounter, int id)
{

    for (int i = 0; i < parentCounter; i++)
    {
        if (user[i].ID == id)
        {
            return i;
        }
    }
    return -1;
}


void deleteParent(PARENT* user, int& parentCounter, int id)
{
    int index = getParentById(user, parentCounter, id);

    for (int i = index; i < parentCounter - 1; i++)
    {
        user[i] = user[i + 1];

    }
    parentCounter--;
}

//function for the menu of deleting one of the parents at the time
void deleteParentMenu(PARENT* user, int& parentCounter, int& maxId)
{
    int id;
    cout << "Enter employeeID(it's start from zero to one,two....):";
    cin >> id;
    deleteParent(user, parentCounter, id);
}


void findParentByLastName(PARENT* user, int& parentCounter)
{
    string parentLastName;
    int counter = 0;
    cout << "\nPlease write the last name of the parent who you want to be shown: "; cin >> parentLastName;
    for (int i = 0; i < parentCounter; i++)
    {
        if (parentLastName==user[i].lastName)
        {
            showParent(user[i]);
            counter++;
        }
    }
    if (counter == 0)
    {
        cout << "\n-----------------------------------------------------------" << endl;
        cout << "\nThere aren't any parents with that last name yet!" << endl;
        cout << "\n-----------------------------------------------------------" << endl;

    }
}

void findChildByName(PARENT* user, int& parentCounter)
{
    string childName;
    int counter = 0;
    cout << "\nPlease write the child's name of the parent who you want to be shown: "; cin >> childName;
    for (int i = 0; i < parentCounter; i++)
    {
        if (childName == user[i].childData.name)
        {
            showParent(user[i]);
            counter++;
        }
    }
    if (counter==0)
    {
        cout << "\n-----------------------------------------------------------" << endl;
        cout << "\nThere aren't any children with that name yet!" << endl;
        cout << "\n-----------------------------------------------------------" << endl;

    }
}

bool mainMenu(PARENT* user, int& parentCounter, int& maxId)
{
    int choice;
    if (adminCounter == 0 && parentCounter == 0)
    {
        cout << "There aren't any users currently logged!" << endl;
        cout << "Please log in as administrator first!" << endl;
        logInAsAdmin();
        accessLevel(adminUsername, adminPass);
        cout << endl;
    }
    else
    {
        cout << "\n1: Create parent profile." << endl;
        cout << "2: Show full parents list." << endl;
        cout << "3. Show parent by Id." << endl;
        cout << "4. Delete parent by Id." << endl;
        cout << "5. Find parent by last name." << endl;
        cout << "6. Find child's parent by child's name." << endl;
        cout << "0: Exit!" << endl << endl;
        cout << "Please enter your choice: "; cin >> choice;
        switch (choice)
        {
        case 1:
            createParentProfile(user, parentCounter, maxId);
            break;
        case 2:
            if (parentCounter == 0)
            {
                cout << "\n-----------------------------------------------------------" << endl;
                cout << "\nThere aren't any parent's profiles yet!" << endl;
                cout << "\n-----------------------------------------------------------" << endl;
            }
            else
            {
                showWholeParentsList(user, parentCounter);
            }
            break;
        case 3:
            showParentInfoById(user, parentCounter);
            break;
        case 4:
            if (parentCounter == 0)
            {
                cout << "Sorry there are not added parents! \nPlease choose option number 1 to add an employee!" << endl << endl;
            }
            else
            {
                deleteParentMenu(user, parentCounter, maxId);
            }
            break;
        case 5:
            findParentByLastName(user, parentCounter);
            break;
        case 6:
            findChildByName(user, parentCounter);
            break;
        case 0:
            return false;
            break;
        }
    }

    return true;
}

int main()
{
    PARENT user[100];
    int maxId = 0;
    int parentCounter = 0;
    bool doShowMenu = true;
    do {
        mainMenu(user, parentCounter, maxId);
        if (mainMenu(user, parentCounter, maxId) == false)
        {
            return 0;
        }
    } while (doShowMenu);
}




