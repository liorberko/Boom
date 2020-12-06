#include "course.h"


bool course::operator<(const course target) const {
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

array<AVLnode<lecture, lectureKey>*>& course::getLectures()
{
    return lectures;
}

course::~course()
{
    for(int i=0; i<num_of_classes ; i++)
    {
        delete (lectures[i]);
    }
}