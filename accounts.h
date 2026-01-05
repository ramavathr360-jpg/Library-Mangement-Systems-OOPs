#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <vector>
using namespace std;

class User;
class Book;

class Account {
    User *user;
    vector<Book> borrowedbooks;
    vector<Book> borrowingHistory;
    int fineamount;
public:
    Account(User *user);
    bool borrowBook(Book &book);
    void returnBook(Book &book);
    void payfine();
    void displaydetails() const;
};

#endif
