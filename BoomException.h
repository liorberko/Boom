#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <iostream>

class BoomException : public std::exception 
{
public:
    BoomException();
    virtual ~BoomException() = default;
};

class IllegalArgument : public BoomException
{ 
public:
    IllegalArgument();
    ~IllegalArgument() = default;
};

#endif