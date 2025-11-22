#include "Exceptions.h"

void Exception::setMessage(std::string message)
{
    //TODO: Implement function
    this->message = message;
}

Exception::Exception(std::string message): message(message) 
{
    //TODO: Implement function
}

Exception::~Exception()
{
}

std::string Exception::getMessage() const
{
    //TODO: Implement function
    return message;
}

IndexOutOfBoundsException::IndexOutOfBoundsException(int position, int maxPosition)
{
    //TODO: Implement function
    std::ostringstream os;
    os << "Tried to access " << position << " in bound " << maxPosition;
    setMessage(os.str());
}
