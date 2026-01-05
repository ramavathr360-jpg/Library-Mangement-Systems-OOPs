#include "Library.h"
#include "User.h"
#include "Book.h"
#include <iostream>
#include <limits>
using namespace std;

int main() {
    Library library;
    library.loadbooks("books.txt");
    library.loadusers("users.txt");
    library.displayBooks();
    library.displayUsers();
    while (true) {
        cout << endl << "----- Library Management System -----" << endl;
        cout << "1. Login" << endl;
        cout << "2. Exit" << endl;
        cout << "Enter your choice:(press only integers) : ";
        int choice;
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (choice == 1) {
            long long userid;
            string password;
            cout << "Enter User ID: ";
            cin >> userid;
            cout << "Enter Password: ";
            cin >> password;
            User *user = library.login(userid, password);
            if (user) {
                if (Student *student = dynamic_cast<Student *>(user)) {
                    studentInterface(library, student);
                }
                else if (Faculty *faculty = dynamic_cast<Faculty *>(user)) {
                    facultyInterface(library, faculty);
                }
                else if (Librarian *librarian = dynamic_cast<Librarian *>(user)) {
                    librarianInterface(library, librarian);
                }
            }
        }
        else if (choice == 2) {
            break;
        }
    }
    library.savebooks("books.txt");
    library.saveusers("users.txt");
    return 0;
}
