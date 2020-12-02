#ifndef COURSE_H
#define COURSE_H
#include "AVLnode.h"

// struct courseInfo
// {
//     int courseID;
//     int numOfClasses;
    
// };

class course : public AVLnode<int>
{
    public:
    bool operator<(const course target) const ;
    bool operator>(const course target) const ;
    bool operator==(const course target) const ;
    friend std::ostream& operator<<(std::ostream& out, const course target) ;
    course(int info, course* left_son = nullptr, course* right_son = nullptr, course* parent = nullptr); 
    ~course();
};

course::~course() 
{
    delete(left_son);
    delete(right_son);
    delete(parent);
}

course::course(int info, course* left_son, course* right_son, course* parent) 
:AVLnode(info) {} 

bool course::operator<(const course target) const 
{
    if (info < target.info)
    {
        return true;
    }
    return false;
}

bool course::operator>(const course target) const {
    if(info>target.info) return true;
    return false;
}
bool course::operator==(const course target) const
{
    if (info == target.info)
    {
        return true;
    }
    return false;
}
std::ostream& operator<<(std::ostream& out, const course target) 
{
    out<< target.info;
    return out;
}
#endif /* COURSE_H */ 