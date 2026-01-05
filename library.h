#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <string>
using namespace std;

class Book;
class User;
class Account;

class Library {
    vector<Book> books;
    vector<User *> users;
    vector<Account> accounts;
public:
    void addBook(const Book &book);
    void addUser(User *user);
    void displayBooks() const;
    void displayUsers() const;
    Book *findbook(const string &bookid);
    User *finduser(long long userid);
    void updateBookDetails(Book* book);
    void savebooks(const string &filename) const;
    void loadbooks(const string &filename);
    void saveusers(const string &filename) const;
    void loadusers(const string &filename);
    void borrowBook(long long userId, const string &bookId);
    vector<Book *> searchbooks(const string &searchitem) const;
    void removeBook(const string &bookId);
    void removeUser(long long userId);
    void payfine(long long userId);
    void updateUserDetails(User* user);
    int getbookscount() const;
    int getuserscount() const;
    User *login(long long userid, const string &password);
};

#endif
