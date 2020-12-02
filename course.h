#ifndef COURSE_H
#define COURSE_H
#include "AVLnode.h"
#include "library.h"


class course 
{
    int courseID;
    public:
    bool operator<(const course target) const ;
    bool operator>(const course target) const ;
    bool operator==(const course target) const ;
    course& operator=(const course target) ;
    friend std::ostream& operator<<(std::ostream& out, const course target) ;
    course(int info) : courseID(info) {}; 
    ~course() = default;
};



bool course::operator<(const course target) const 
{
    if (courseID < target.courseID)
    {
        return true;
    }
    return false;
}

bool course::operator>(const course target) const {
    if(courseID>target.courseID) return true;
    return false;
}
bool course::operator==(const course target) const
{
    if (courseID == target.courseID)
    {
        return true;
    }
    return false;
}
course& course::operator=(const course target) {
    this->courseID=target.courseID;
    return *this;
}
std::ostream& operator<<(std::ostream& out, const course target) 
{
    out<< target.courseID;
    return out;
}
#endif /* COURSE_H */ 