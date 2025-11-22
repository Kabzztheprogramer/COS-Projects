#ifndef LIBRARY_H
#define LIBRARY_H

#include <sstream>

#include "Book.h"

class Library {
    
    private:

    int numBooks;
    Book **books ;

    public:
    
    Library();
    Library(const Library& other);
    Library& operator=(const Library& other);
    ~Library();
    std::string  booksSummary();
    void addBook(std::string title , std::string author , int numPages);
    int readBook(std::string title , std::string author );
    int totalNumberOfTimesRead();
    std::string uniqueAuthors();
    std::string uniqueTitles();
};

#endif