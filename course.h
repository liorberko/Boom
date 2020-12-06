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
    AVLnode<lecture, lectureKey>** lectures;
    public:
    bool operator<(const course target) const ;
    bool operator>(const course target) const ;
    bool operator==(const course target) const ;
    course& operator=(const course target) ;
    int getCourseID();
    int getNumOfClasses();
    AVLnode<lecture, lectureKey>** getLectures();
    friend std::ostream& operator<<(std::ostream& out, const course target) ;
    course(int courseID, int num_of_classes) : courseID(courseID), num_of_classes(num_of_classes)
    {
        lectures = new AVLnode<lecture, lectureKey>*[num_of_classes];
        for (int i=0 ; i<num_of_classes; i++)
        {
            lecture new_lec(i,courseID,0);
            AVLnode<lecture, lectureKey>* temp = new AVLnode<lecture, lectureKey>(new_lec, new_lec.getKey()); 
            lectures[i] = temp;
        }
    }; 
    // course(const course& target) : courseID(target.courseID), num_of_classes(target.num_of_classes), lectures(num_of_classes) 
    // {
    //     // for (int i=0 ; i<num_of_classes; i++)
    //     // {
    //     //     lecture* new_lec = new lecture(i,courseID,0);
    //     //     AVLnode<lecture, lectureKey>* temp = new AVLnode<lecture, lectureKey>(*new_lec, new_lec->getKey()); 
    //     //     lectures[i] = temp;
    //     // }
    // }; 
    ~course() 
    {
        for(int i=0; i<num_of_classes;i++)
        {
            if (lectures[i] != NULL)
            {
                delete (lectures[i]);
            }
        }
        delete[] lectures;
    }
};


#endif /* COURSE_H */ 