#ifndef LECTURE_H
#define LECTURE_H
#include "AVLnode.h"
#include "library.h"
#include "array.h"
#include "course.h"

struct lectureKey{
        int lectureID;
        int courseID;
        int viewTime;
        lectureKey(int lectureID, int courseID, int viewTime) : lectureID(lectureID), courseID(courseID), viewTime(viewTime){}
        ~lectureKey() = default;
    };
class lecture 
{
    lectureKey key;
    public:
    int getLectureID();
    int getCourseID();
    int getViewTime();
    bool operator<(const lecture target) const ;
    bool operator>(const lecture target) const ;
    bool operator==(const lecture target) const ;
    lecture& operator=(const lecture target) ;
    friend std::ostream& operator<<(std::ostream& out, const lecture target) ;
    lecture()  : key(0,0,0) {}
    lecture(int lectureID, int courseID, int viewTime = 0) : key(lectureID, courseID, viewTime){} 
    ~lecture() = default;
};



#endif /* LECTURE_H */