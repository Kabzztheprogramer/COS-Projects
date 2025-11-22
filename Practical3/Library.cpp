#include "Book.h"
#include "Library.h"
#include <iostream>
#include <string>
#include <sstream>

Library:: Library(){
    numBooks = 0 ;
};

Library::Library(const Library& other){

    for (int i  = 0 ; i < other.numBooks; i++){
        this->books[i] = new Book("","",0);
        this->books[i] = other.books[i];
    }
    this->numBooks = other.numBooks;
};
Library& Library:: operator=(const Library& other){
    //clearing the current library
    if (this == &other){
        return *this;
    } 
    for (int i  = 0 ; i < this->numBooks ;i++){
        
        delete this->books[i];
    }
    delete [] this->books;

    if(other.numBooks > 0)
    {
        books = new Book * [other.numBooks];
        //Adding books from the other Library to the  current Library
        for (int i  = 0 ; i < other.numBooks ;i++){

            this-> books[i] = new Book("","",0);
            *books[i] = *other.books[i];

        }

        return *this ;
    }
    };

Library::~Library() {
    if (books) {
        for (int i = 0; i < numBooks; ++i) {
            delete books[i];
        }
        delete[] books;
    }
};
std::string  Library:: booksSummary(){

    std:: string allSummary;
    for (int i  = 0 ; i < numBooks ;i++){

        allSummary += books[i]->getBookInformation();
        if(i == numBooks-1){

            allSummary += "\n" ;

        }

    }

    return allSummary;
    
};
void Library::addBook(std::string title , std::string author , int numPages){
   Book **NewBooksarr = new Book *[numBooks+1];
    //clearing the current library
    for (int i  = 0 ; i < numBooks ;i++){
        NewBooksarr[i] = books[i];
        delete this->books[i];
    }
    delete [] this->books;

     //Adding books to the resized array
     books = new Book *[numBooks+1];
    for (int i  = 0 ; i < numBooks ;i++){

        this->books[i] = NewBooksarr[i];

    }
    
    books[numBooks] = new Book(title,author , numPages);
    ++numBooks;

   
};
int Library:: readBook(std::string title , std::string author ){

    bool bfound = false;
    int arrsize = 0;
    while (arrsize < numBooks){
        //getting the title
        std::string info = books[arrsize]->getBookInformation();
        int Pcol= info.find(":");
        std::string Ctitle = info.substr(0,Pcol);
        info.erase(0,Pcol+1);   

        //getting the name of the Author 
        int Ppar = info.find("(");
        std::string Cauthor = info.substr(0,Ppar);
        info.erase(0,Ppar+1);

        //get the number of pages
        int Ppar2 = info.find(")");
        std::stringstream strtoint;
        std::string spages = info.substr(0,Ppar);
        int Cpages ;
        strtoint << spages ;
        strtoint>> Cpages ;
        info.erase(0,Ppar2+1);

        //checking if the books are the same 
        if ( Cauthor == author && Ctitle == title){
            this->books[arrsize]->readBook();
            return Cpages;
        }
        ++arrsize;

    }
 return -1;

};
int Library:: totalNumberOfTimesRead(){
    int sum = 0;
    for (int i  = 0 ; i < numBooks ;i++){
        //getting the title
        std::string info = books[i]->getBookInformation();
        int Pcol= info.find(":");
        std::string Ctitle = info.substr(0,Pcol);
        info.erase(0,Pcol+1);   

        //getting the name of the Author 
        int Ppar = info.find("(");
        std::string Cauthor = info.substr(0,Ppar);
        info.erase(0,Ppar+1);

        //get the number of pages
        int Ppar2 = info.find(")");
        std::stringstream strtoint;
        std::string spages = info.substr(0,Ppar);
        int Cpages ;
        strtoint << spages ;
        strtoint>> Cpages ;
        info.erase(0,Ppar2+1);

        int CnumberoftimesRead ;
        strtoint << info ;
        strtoint>> CnumberoftimesRead ;

        sum +=CnumberoftimesRead;

    }
    return sum;
};

std::string Library:: uniqueAuthors(){

    std::string strAuthor = "";
     for (int i  = 0 ; i < numBooks ;i++){
        //getting the title
        std::string info = books[i]->getBookInformation();
        int Pcol= info.find(":");
        std::string Ctitle = info.substr(0,Pcol);
        info.erase(0,Pcol+1);   

        //getting the name of the Author 
        int Ppar = info.find("(");
        std::string Cauthor = info.substr(0,Ppar);
        info.erase(0,Ppar+1);
        
        if (info.find(Cauthor) > info.length() || info.find(Ppar) < 0 ){
            strAuthor+="[" + Cauthor + "]";
        }


    }
    return strAuthor;
};
std::string Library:: uniqueTitles(){
    
    std::string strAuthor = "";
     for (int i  = 0 ; i < numBooks ;i++){
        //getting the title
        std::string info = books[i]->getBookInformation();
        int Pcol= info.find(":");
        std::string Ctitle = info.substr(0,Pcol);
        info.erase(0,Pcol+1);   

        std::stringstream strtoint;
        std::string si;
        strtoint << i ;
        strtoint >> si ;  
        if (info.find(Ctitle) > info.length() || info.find(Ctitle) < 0 ){
            strAuthor+="[" + Ctitle + " " + si  +"]";
        }


    }
    return strAuthor;
};