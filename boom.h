#ifndef BOOM_H
#define BOOM_H
#include "library.h"
#include "lecture.h"
#include "AVLnode.h"
#include "AVLtree.h"
#include "course.h"

class boom
{
private:
    AVLtree<course> courses;
    AVLtree<lecture> lectures;
    int class_counter;
public:
    boom()=default;
    ~boom();

    bool AddCourse (int courseID, int numOfClasses);

    bool RemoveCourse(int courseID);

    bool WatchClass(int courseID, int classID, int time);

    int TimeViewed(int courseID, int classID);

    bool GetMostViewedClasses(int numOfClasses, int *courses, int *classes);

};


#endif /* BOOM_H */