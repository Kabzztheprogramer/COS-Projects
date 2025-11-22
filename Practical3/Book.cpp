
#include "Book.h"
#include <iostream>
#include <string>
#include <sstream>

Book::Book(std::string title , std::string author , int numPages){
    this->title = title;
    this->author = author;
    this->numPages = numPages;
    numberOfTimesRead = 0 ;
};

Book::Book(const Book& other)
{
    this->title = other.title;
    this->author = other.author;
    this->numPages = other.numPages;
    this->numberOfTimesRead = 0 ;
};
 Book& Book::operator=(const Book& other)
{
    this->title = other.title;
    this->author = other.author;
    this->numPages = other.numPages;
    this->numberOfTimesRead = other.numberOfTimesRead ;
};
Book::~Book()
{ 
};
std:: string Book:: getBookInformation()
{
    std::string snumPages ;
    std::stringstream inttostr1;
    inttostr1<< numPages ;
    inttostr1 >>snumPages ;


    std::string  snumberOfTimesRead  ;
    std::stringstream inttostr2;
    inttostr2<< numberOfTimesRead  ;
    inttostr2 >>snumberOfTimesRead ; 

    return (title+":"+author+"("+snumPages+")"+snumberOfTimesRead);
    //Rise:SiyaKolisi(120)8
};
void Book:: readBook()
{
 ++numberOfTimesRead;
};