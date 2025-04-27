/* 
=============================================
|                Author:Ali Raza            |
=============================================
 */

#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

struct Entry {
    string date;
    string text;
};

string loggedInUser;

void registerUser();
bool login();
void addEntry();
void deleteEntry();
void viewEntries();
void clearInputBuffer();

void mainMenu();      
void userMenu();      

void clearScreen(){
   system("cls"); }

int main() {
    mainMenu();
    return 0;
}

void mainMenu() {
    int choice;

    do {
        cout << "\n==================================" << endl;
        cout << "|      Personal Diary System     |" << endl;
        cout << "==================================" << endl;
        cout << "| 1. Register                    |" << endl;
        cout << "| 2. Login                       |" << endl;
        cout << "| 3. Exit                        |" << endl;
        cout << "==================================" << endl;

        cout << "Enter your choice (1-3): ";
        while (!(cin >> choice) || choice < 1 || choice > 3) {
            cout << "Invalid input! Please enter a valid option (1-3): ";
            cin.clear();
            clearInputBuffer();
        }

        cin.ignore(); 
        switch (choice) {
            case 1:
                registerUser();
 
                break;
            case 2:
                if (login()) {
                    userMenu();
                }
                break;
            case 3:
            clearScreen();
                cout << "Goodbye!\n";
                cout << "\nThanks for using Personal Dairy Management..\n\n";
                return;
        }
    } while (true);
}

void userMenu() {
    int choice;

    do {
        cout << "\n==================================" << endl;
        cout << "|      Personal Diary System     |" << endl;
        cout << "==================================" << endl;
        cout << "| 1. Add Entry                   |" << endl;
        cout << "| 2. Delete Entry                |" << endl;
        cout << "| 3. View Entries                |" << endl;
        cout << "| 4. Logout                      |" << endl;
        cout << "==================================" << endl;

        cout << "Enter your choice (1-4): ";
        while (!(cin >> choice) || choice < 1 || choice > 4) {
            cout << "Invalid input! Please enter a valid option (1-4): ";
            cin.clear();
            clearInputBuffer();
        }

        cin.ignore(); 
        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                deleteEntry();
                break;
            case 3:
                viewEntries();
                break;
            case 4:
            clearScreen();
                cout << "Logging out...\n\n";

                loggedInUser.clear();
                cout<<"Logout Successfull!\n";
                return;
        }
    } while (true);
}

void registerUser() {
    string username, password;
    ofstream userFile("D:\\PF LAb project Practices\\Group_no_2\\user.txt", ios::app);

    cout << "\nEnter username: ";
    getline(cin, username);
    cout << "Enter password: ";
    getline(cin, password);

    ifstream checkFile("D:\\PF LAb project Practices\\Group_no_2\\user.txt");
    string existingUser, existingPass;
    while (checkFile >> existingUser >> existingPass) {
        if (existingUser == username) {
            clearScreen();
            cout << "Username already exists. Please try another.\n";
            return;
        }
    }
    checkFile.close();

    userFile << username << " " << password << "\n";
    userFile.close();
    cout << "Registration successful!\n";
}

bool login() {
    string username, password;
    ifstream userFile("D:\\PF LAb project Practices\\Group_no_2\\user.txt");
    clearScreen();
cout<<"Login Now..\n";
    if (!userFile) {
        cout << "No users found. Please register first.\n";
        return false;
    }

    cout << "\nEnter username: ";
    getline(cin, username);
    cout << "Enter password: ";
    getline(cin, password);

    string storedUser, storedPass;
    while (userFile >> storedUser >> storedPass) {
        if (storedUser == username && storedPass == password) {
            loggedInUser = username;
            clearScreen();
            cout << "Login successful! Welcome, " << loggedInUser << "!\n";
            userFile.close();
            return true;
        }
    }
    userFile.close();
    cout << "Invalid username or password.\n";
    return false;
}

void addEntry() {
    Entry entry;
    ofstream diaryFile("D:\\PF LAb project Practices\\Group_no_2\\diary.txt", ios::app);
clearScreen();
cout<<"Entering the Diary..\n\n";
    cout << "\nEnter date (YYYY-MM-DD): ";
    getline(cin, entry.date);

    cout << "Enter text: ";
    getline(cin, entry.text);

    diaryFile << loggedInUser << " " << entry.date << " " << entry.text << "\n";
    diaryFile.close();
    cout << "Entry added successfully.\n";
}
void deleteEntry() {
    ifstream diaryFile("D:\\PF LAb project Practices\\Group_no_2\\diary.txt");
    ofstream tempFile("D:\\PF LAb project Practices\\Group_no_2\\temp.txt");

    if (!diaryFile) {
        cout << "No diary entries found.\n";
        return;
    }



    string dateToDelete, user, date, text;
    bool found = false;

    cout << "\nEnter the date of the entry to delete (YYYY-MM-DD): ";
    getline(cin, dateToDelete);

    while (diaryFile >> user >> date) {
        diaryFile.ignore(); 
        getline(diaryFile, text);

        if (user == loggedInUser && date == dateToDelete) {
            found = true; 
        } else {
            tempFile << user << " " << date << " " << text << "\n"; 
        }
    }

    diaryFile.close();
    tempFile.close();

    remove("D:\\PF LAb project Practices\\Group_no_2\\diary.txt");
    rename("D:\\PF LAb project Practices\\Group_no_2\\temp.txt", "D:\\PF LAb project Practices\\Group_no_2\\diary.txt");

    if (found) {
        cout << "Entry deleted successfully.\n";
    } else {
        cout << "No entry found for the specified date.\n";
    }
}

void viewEntries() {
    ifstream diaryFile("D:\\PF LAb project Practices\\Group_no_2\\diary.txt");
    clearScreen();
    if (!diaryFile) {
        cout << "No diary entries found.\n";
        return;
    }

    string user, date, text;
    bool found = false;

    cout << "\nDIARY Entries for " << loggedInUser << ":\n\n";
    while (diaryFile >> user) {
        diaryFile >> date;
        diaryFile.ignore();
        getline(diaryFile, text);

        if (user == loggedInUser) {
            cout << date << ": " << text << "\n";
            found = true;
        }
    }

    if (!found) {
        cout << "No entries found.\n";
    }

    diaryFile.close();
}

void clearInputBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
