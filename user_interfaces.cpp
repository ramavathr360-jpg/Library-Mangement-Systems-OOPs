#include "Library.h"
#include "User.h"
#include "Book.h"
#include <iostream>
#include <limits>
using namespace std;

void studentInterface(Library &library, Student *student);
void facultyInterface(Library &library, Faculty *faculty);
void librarianInterface(Library &library, Librarian *librarian);

void studentInterface(Library &library, Student *student) {
    int choice;
    string bookId;
    do {
        cout << endl << "----- Student Menu -----" << endl;
        cout << "1. Search for a book" << endl;
        cout << "2. Borrow a book" << endl;
        cout << "3. Return a book" << endl;
        cout << "4. View account details" << endl;
        cout << "5. Pay fine" << endl;
        cout << "6. Reserve a book" << endl;
        cout << "7. Cancel Reservation" << endl;
        cout << "8. Logout" << endl;
        cout << "Enter your choice: " << endl;
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        switch (choice) {
        case 1: {
            string searchitem;
            cout << "Enter book title or author to search: ";
            cin.ignore();
            getline(cin, searchitem);
            vector<Book *> searchResults = library.searchbooks(searchitem);
            for (const auto &book : searchResults) book->displaydetails();
            break;
        }
        case 2:
            cout << "Enter Book ID to borrow: ";
            cin >> bookId;
            if (Book *book = library.findbook(bookId)) student->borrowBook(*book);
            break;
        case 3:
            cout << "Enter Book ID to return: ";
            cin >> bookId;
            if (Book *book = library.findbook(bookId)) student->returnBook(*book);
            break;
        case 4:
            cout << "Account Details for " << student->getname() << ":" << endl;
            cout << "User ID: " << student->getuserid() << endl;
            cout << "Books borrowed: " << student->getborrowedbooks() << endl;
            cout << "Fine amount: Rupees " << student->getfineamount() << endl;
            break;
        case 5:
            student->payfine();
            break;
        case 6:
            cout << "Enter Book ID to reserve: ";
            cin >> bookId;
            if (Book *book = library.findbook(bookId)) student->reserveBook(*book);
            break;
        case 7:
            cout << "Enter Book ID to cancel reservation: ";
            cin >> bookId;
            if (Book *book = library.findbook(bookId)) student->cancelReservation(*book);
            break;
        case 8:
            break;
        }
    } while (choice != 8);
}

void facultyInterface(Library &library, Faculty *faculty) {
    int choice;
    string bookId;
    do {
        cout << endl << "----- Faculty Menu -----" << endl;
        cout << "1. Search for a book" << endl;
        cout << "2. Borrow a book" << endl;
        cout << "3. Return a book" << endl;
        cout << "4. View account details" << endl;
        cout << "5. Reserve a book" << endl;
        cout << "6. Cancel Reservation" << endl;
        cout << "7. Logout" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        switch (choice) {
        case 1: {
            string searchitem;
            cout << "Enter book title or author to search: ";
            cin.ignore();
            getline(cin, searchitem);
            vector<Book *> searchResults = library.searchbooks(searchitem);
            for (const auto &book : searchResults) book->displaydetails();
            break;
        }
        case 2:
            cout << "Enter Book ID to borrow: ";
            cin >> bookId;
            if (Book *book = library.findbook(bookId)) faculty->borrowBook(*book);
            break;
        case 3:
            cout << "Enter Book ID to return: ";
            cin >> bookId;
            if (Book *book = library.findbook(bookId)) faculty->returnBook(*book);
            break;
        case 4:
            cout << "Account Details for " << faculty->getname() << ":" << endl;
            cout << "User ID: " << faculty->getuserid() << endl;
            cout << "Books borrowed: " << faculty->getborrowedbooks() << endl;
            break;
        case 5:
            cout << "Enter Book ID to reserve: ";
            cin >> bookId;
            if (Book *book = library.findbook(bookId)) faculty->reserveBook(*book);
            break;
        case 6:
            cout << "Enter Book ID to cancel reservation: ";
            cin >> bookId;
            if (Book *book = library.findbook(bookId)) faculty->cancelReservation(*book);
            break;
        case 7:
            break;
        }
    } while (choice != 7);
}

void librarianInterface(Library &library, Librarian *librarian) {
    int choice;
    do {
        cout << endl << "----- Librarian Menu -----" << endl;
        cout << "1. Add a book" << endl;
        cout << "2. Remove a book" << endl;
        cout << "3. Add a user" << endl;
        cout << "4. Remove a user" << endl;
        cout << "5. Display all books" << endl;
        cout << "6. Display all users" << endl;
        cout << "7. Update user details" << endl;
        cout << "8. Update book details" << endl;
        cout << "9. Logout" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        switch (choice) {
        case 1: {
            string isbn, title, author, publisher, bookid;
            int year;
            cout << "Enter ISBN: ";
            cin >> isbn;
            cin.ignore();
            cout << "Enter Title: ";
            getline(cin, title);
            cout << "Enter Author: ";
            getline(cin, author);
            cout << "Enter Publisher: ";
            getline(cin, publisher);
            cout << "Enter Year: ";
            cin >> year;
            cout << "Enter Book ID: ";
            cin >> bookid;
            Book newBook(isbn, title, author, publisher, year, bookid);
            library.addBook(newBook);
            break;
        }
        case 2: {
            string bookId;
            cout << "Enter Book ID to remove: ";
            cin >> bookId;
            library.removeBook(bookId);
            break;
        }
        case 3: {
            string name, type, password;
            long long userid;
            cout << "Enter user type (Student/Faculty): ";
            cin >> type;
            cout << "Enter name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter user ID: ";
            cin >> userid;
            cout << "Enter Password: ";
            cin >> password;
            if (type == "Student") library.addUser(new Student(name, userid, password));
            else if (type == "Faculty") library.addUser(new Faculty(name, userid, password));
            break;
        }
        case 4: {
            long long userId;
            cout << "Enter User ID to remove: ";
            cin >> userId;
            library.removeUser(userId);
            break;
        }
        case 5:
            library.displayBooks();
            break;
        case 6:
            library.displayUsers();
            break;
        case 7: {
            long long userId;
            cout << "Enter User ID to update: ";
            cin >> userId;
            User* targetUser = library.finduser(userId);
            if(targetUser) library.updateUserDetails(targetUser);
            break;
        }
        case 8: {
            string bookId;
            cout << "Enter Book ID to update: ";
            cin >> bookId;
            Book* targetBook = library.findbook(bookId);
            if(targetBook) library.updateBookDetails(targetBook);
            break;
        }
        case 9:
            break;
        }
    } while (choice != 9);
}
