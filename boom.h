#ifndef BOOM_H
#define BOOM_H
#include "library.h"
#include "lecture.h"
#include "AVLnode.h"
#include "AVLtree.h"
#include "course.h"
#include "BoomException.h"

class boom
{
private:
    AVLtree<course,int> courses;
    AVLtree<lecture, lectureKey> lectures;
    int class_counter;
public:
    boom()=default;

    ~boom() = default;
    // {
    //     delete(&lectures);
    //     delete(&courses);
    // }

    bool AddCourse(int courseID, int numOfClasses);

    bool RemoveCourse(int courseID);

    StatusType WatchClass(int courseID, int classID, int time);

    int TimeViewed(int courseID, int classID);

    bool GetMostViewedClasses(int numOfClasses, int *courses_array, int *classes_array);

};

#endif /* BOOM_H */