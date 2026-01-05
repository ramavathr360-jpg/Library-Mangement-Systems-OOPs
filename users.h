#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class Book;

class User {
protected:
    string Name;
    long long Userid;
    string Password;
public:
    User(const string &name = "", long long userid = 0, const string &password = "XYZ")
        : Name(name), Userid(userid), Password(password) {}
    string getname() const { return Name; }
    void setname(const string &newname) { Name = newname; }
    long long getuserid() const { return Userid; }
    void setuserid(long long userid) { Userid = userid; }
    string getPassword() const { return Password; }
    void setPassword(const string &newPassword) { Password = newPassword; }
    virtual bool borrowBook(Book &book) = 0;
    virtual void returnBook(Book &book) = 0;
    virtual void printuser() const {
        cout << "User ID: " << Userid << endl << "Name: " << Name << endl;
    }
    virtual ~User() {}
};

class Student : public User {
    int borrowed_books;
    int fine_amount;
public:
    Student(const string &name = "", long long userid = 0, const string &password = "")
        : User(name, userid, password), borrowed_books(0), fine_amount(0) {}
    int getborrowedbooks() const { return borrowed_books; }
    void setborrowedbooks(int newborrowedbooks) { borrowed_books = newborrowedbooks; }
    int getfineamount() const { return fine_amount; }
    void setfineamount(int newfineamount) { fine_amount = newfineamount; }
    void payfine() { fine_amount = 0; }
    bool borrowBook(Book &book) override;
    void returnBook(Book &book) override;
    void reserveBook(Book &book);
    void cancelReservation(Book &book);
    bool borrowReserved(Book &book);
};

class Faculty : public User {
    int borrowed_books;
public:
    Faculty(const string &name = "", long long userid = 0, const string &password = "")
        : User(name, userid, password), borrowed_books(0) {}
    int getborrowedbooks() const { return borrowed_books; }
    void setborrowedbooks(int newborrowedbooks) { borrowed_books = newborrowedbooks; }
    bool borrowBook(Book &book) override;
    void returnBook(Book &book) override;
    void reserveBook(Book &book);
    void cancelReservation(Book &book);
    bool borrowReserved(Book &book);
};

class Librarian : public User {
    vector<Book> books;
    vector<User *> users;
public:
    Librarian(const string &name = "", long long userid = 0, const string &password = "")
        : User(name, userid, password) {}
    void addBook(const Book &book);
    bool borrowBook(Book &book) override;
    void returnBook(Book &book) override;
    void removeBook(const string &bookid);
    void updateUser(long long userid);
    void addUser(User *user);
    void removeUser(int userid);
    void reserveBook(Book &book);
};

#endif
