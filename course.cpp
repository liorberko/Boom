#include "course.h"


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
course& course::operator=(const course target) 
{
    if (this == &target)
    {
        return *this;
    }
    courseID = target.courseID;
    lectures = target.lectures;
    return *this;
}
std::ostream& operator<<(std::ostream& out, const course target) 
{
    out<< target.courseID;
    return out;
}

int course::getCourseID()
{
    return courseID;
}

int course::getNumOfClasses()
{
    return num_of_classes;
}

array<lecture>& course::getLectures()
{
    return lectures;
}