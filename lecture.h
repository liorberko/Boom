#ifndef LECTURE_H
#define LECTURE_H
#include "AVLnode.h"
#include "library.h"
#include "array.h"

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
    int& getLectureID();
    int& getCourseID();
    int& getViewTime();
    lectureKey& getKey();
    bool operator<(const lecture target) const ;
    bool operator>(const lecture target) const ;
    bool operator==(const lecture target) const ;
    lecture& operator=(const lecture target) ;
    friend std::ostream& operator<<(std::ostream& out, const lecture target) ;
    lecture()  : key(0,0,0) {}
    lecture(int lectureID, int courseID, int viewTime = 0) : key(lectureID, courseID, viewTime){} 
    lecture(const lecture& target) : key(target.key.lectureID, target.key.courseID, target.key.viewTime){}
    ~lecture() = default;
};



#endif /* LECTURE_H */