#ifndef LECTURE_H
#define LECTURE_H
#include "AVLnode.h"
#include "library.h"
#include "array.h"
#include "course.h"

class lecture 
{
    int lectureID;
    int courseID;
    int viewTime;
    public:
    int getLectureID();
    int getCourseID();
    int getViewTime();
    bool operator<(const lecture target) const ;
    bool operator>(const lecture target) const ;
    bool operator==(const lecture target) const ;
    lecture& operator=(const lecture target) ;
    friend std::ostream& operator<<(std::ostream& out, const lecture target) ;
    lecture(int lectureID, int courseID, int viewTime = 0) : lectureID(lectureID), courseID(courseID) , viewTime(viewTime){} 
    ~lecture() = default;
};



#endif /* LECTURE_H */