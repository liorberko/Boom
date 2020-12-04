#include "lecture.h"

bool lecture::operator<(const lecture target) const 
{
    if(viewTime < target.viewTime){
        return true;
    }
    if (viewTime == target.viewTime && lectureID > target.lectureID)
    {
        return true;
    }
    else if (viewTime == target.viewTime && lectureID==target.lectureID && courseID > target.courseID){
        return true;
    }
    return false;
}
bool lecture::operator>(const lecture target) const 
{
    if(viewTime > target.viewTime){
        return true;
    }
    if (viewTime == target.viewTime && lectureID < target.lectureID)
    {
        return true;
    }
    else if (viewTime == target.viewTime && lectureID==target.lectureID && courseID < target.courseID){
        return true;
    }
    return false;
}

bool lecture::operator==(const lecture target) const 
{
    if ((lectureID == target.lectureID) && (courseID == target.courseID) && (viewTime == target.viewTime))
    {
        return true;
    }
    return false;
}

lecture& lecture::operator=(const lecture target) {
    if (this == &target)
    {
        return *this;
    }
    this->lectureID=target.courseID;
    this->courseID=target.courseID;
    this->viewTime=target.viewTime;
    return *this;
}

std::ostream& operator<<(std::ostream& out, const lecture target) 
{
    out << "lecture id: " << target.lectureID << std::endl;
    out << "course id: " << target.courseID << std::endl;
    out << "lecture view time: " << target.viewTime << std::endl;
}
int lecture::getLectureID()
{
    return lectureID;
}

int lecture::getCourseID()
{
    return courseID;
}

int lecture::getViewTime()
{
    return viewTime;
}