#ifndef COURSE_H
#define COURSE_H
#include "AVLnode.h"
#include "library.h"
#include "array.h"
#include "lecture.h"

class course 
{
    int courseID;
    int num_of_classes;
    array<lecture> lectures;
    public:
    bool operator<(const course target) const ;
    bool operator>(const course target) const ;
    bool operator==(const course target) const ;
    course& operator=(const course target) ;
    int getCourseID();
    int getNumOfClasses();
    array<lecture>& getLectures();
    friend std::ostream& operator<<(std::ostream& out, const course target) ;
    course(int courseID, int num_of_classes) : courseID(courseID), num_of_classes(num_of_classes), lecture(num_of_classes) {}; 
    ~course() = default;
};

#endif /* COURSE_H */ 