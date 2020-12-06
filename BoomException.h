#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <iostream>

class BoomException : public std::exception 
{
public:
    BoomException() = default;
    virtual ~BoomException() = default;
};

class IllegalArgument : public BoomException
{ 
public:
    IllegalArgument() =default;
    ~IllegalArgument() = default;
};

#endif