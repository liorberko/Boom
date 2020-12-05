#include "boom.h"

bool boom::AddCourse (int courseID, int numOfClasses)
{
    AVLnode<T,M>*check= courses.find(courseID);
    if(check != nullptr) return FAILURE;
    course* new_course = new course(courseID,numOfClasses);
    AVLnode<course, int>* new_ver = new AVLnode<course, int>(*new_course, courseID);
    courses.addVertex(new_ver);
    class_counter+=numOfClasses;
    return true;
}

bool boom::RemoveCourse(int courseID)
{
    AVLnode<T,M>*check= courses.find(courseID);
    if(check == nullptr) return FAILURE;
    AVLnode<course,int>* course_to_delete = courses.find(courseID);
    class_counter-=course_to_delete->info.getNumOfClasses();
    array<AVLnode<lecture, lectureKey>*> lectures_to_delete = course_to_delete->info.getLectures();
    int num_of_classes = course_to_delete->info.getNumOfClasses();
    for(int i=0; i<num_of_classes;i++){
        StatusType control=lectures.removeVertex(lectures_to_delete[i]);
        if(control!=SUCCESS) return false;
    }
    StatusType control=courses.removeVertex(course_to_delete);
    if(control==SUCCESS) return true;
    return false;
}

bool boom::WatchClass(int courseID, int classID, int time)
{   
    AVLnode<T,M>*check= courses.find(courseID);
    if(check == nullptr) return FAILURE;
    AVLnode<course,int>* temp = courses.find(courseID);
    AVLnode<lecture, lectureKey>* lec = (temp->info.getLectures())[classID];
    if (lectures.removeVertex(lec) != SUCCESS) return false;
    lec->info.getViewTime() += time;
    if (lectures.addVertex(lec) != SUCCESS) return false;
    return true;
}

int boom::TimeViewed(int courseID, int classID){
    AVLnode<course,int>* wanted_course = courses.find(courseID);
    if ((wanted_course == NULL)|| (wanted_course->info.getNumOfClasses() <classID) return -1;
    array<AVLnode<lecture, lectureKey>*> wanted_course_lectures = wanted_course->info.getLectures();
    int TimeViewed = wanted_course_lectures[classID]->info.getViewTime();
    return TimeViewed;
}

void recieveFromLecturesTree(AVLnode<lecture,lectureKey> *item,int* &courses,int* &classes,int &max_actions){
    *classes=item->info.getLectureID();
    classes++;
    *courses=item->info.getCourseID();
    courses++;   
}

void recieveFromCoursesTree(AVLnode<course,int> *item,int* &courses,int* &classes, int &max_actions)
{
    for (int i = 0; ((i < item->info.getNumOfClasses()) && (max_actions > 0)) ; i++ )
    {
        if ((item->info.getLectures()[i])->info.getViewTime() == 0)
        {
            *courses = item->info.getCourseID();
            courses++;
            *classes = i;
            classes++;
            max_actions--;
        }
    }
}

bool boom::GetMostViewedClasses(int numOfClasses, int *courses, int *classes)
{
    if (class_counter < numOfClasses)
    {
        return false;
    }
    int numOfActions = lectures.applyFromRight(numOfClasses,recieveFromLecturesTree, courses,classes);
    //starting with lectures that known to be watched.
    int res = numOfClasses-numOfActions;
    if (res > 0){
        //if wished to more lectures then watched, we are reaching for the courses tree.
       lectures.applyFromLeft(res, recieveFromLecturesTree, courses + res,classes +res);
    }
    return true;
}

