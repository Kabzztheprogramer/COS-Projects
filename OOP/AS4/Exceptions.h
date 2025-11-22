#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <string>
#include <sstream>

class Exception{
    private:
        std::string message;

    protected:
        void setMessage(std::string message);

    public:
        Exception(std::string message = "Exception occurred");
        virtual ~Exception();
        std::string getMessage() const;
};

class IndexOutOfBoundsException: public Exception{
    public:
        IndexOutOfBoundsException(int position, int maxPosition);
};

#endif //EXCEPTIONS_H