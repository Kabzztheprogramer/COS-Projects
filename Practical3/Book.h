#ifndef BOOK_H
#define BOOK_H

#include <sstream>
#include <string>

class Book {
    private :
    
    std::string title;
    std::string author;
    int numPages ;
    int numberOfTimesRead ;

    public :

    Book(std::string title , std::string author , int numPages);
    Book(const Book& other);
    Book& operator=(const Book& other);
    ~Book();
    std:: string getBookInformation();
    void readBook();
};

#endif