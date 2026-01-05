#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <ctime>
using namespace std;

class User;

class Book {
    string ISBN;
    string Title;
    string Author;
    string Publisher;
    string Bookid;
    int Year;
    bool Available;
    string BorrowedBy;
    bool Reserved;
    string ReservedBy;
    time_t borrowTime;
public:
    Book(const string isbn = "", const string &title = "", const string &author = "",
         const string &publisher = "", const int year = 0, const string bookid = "")
        : ISBN(isbn), Title(title), Author(author), Publisher(publisher),
          Year(year), Bookid(bookid), Available(true), Reserved(false), ReservedBy("") {}
    bool borrow(User *user);
    void returnBook(User *user);
    void reserve(User *user);
    void cancelReservation();
    void displaydetails() const;
    bool borrowReserved(User *user);
    void setBorrowedBy(const string &name);
    string getBorrowedBy() const;
    void setReservedBy(const string &name);
    string getReservedBy() const;
    bool getreserved() const;
    void setreserved(bool reserved);
    void setBorrowTime(time_t t = time(0));
    time_t getBorrowTime() const;
    string getISBN() const;
    string gettitle() const;
    string getauthor() const;
    string getpublisher() const;
    string getbookid() const;
    int getyear() const;
    bool getstatus() const;
    void setISBN(const string &isbn);
    void settitle(const string &title);
    void setauthor(const string &author);
    void setpublisher(const string &publisher);
    void setbookid(const string &bookid);
    void setYear(int year);
    void setstatus(bool available);
};

#endif
