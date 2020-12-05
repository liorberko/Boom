#include "library.h"
#include "boom.h"

void *Init()
{
    boom *DS=new boom();
    return (void*)DS;
}

StatusType AddCourse (void *DS, int courseID, int numOfClasses)
{
    if(courseID <=0 || numOfClasses <=0 || DS==nullptr) return INVALID_INPUT;
    try{
        if(!((boom*)DS)->AddCourse(courseID, numOfClasses))
        {
            return FAILURE;
        }
    }
    catch(...){
        return ALLOCATION_ERROR;
    }
    return SUCCESS;
}

StatusType RemoveCourse(void *DS, int courseID)
{
    if((courseID <=0)|| (DS == NULL)) return INVALID_INPUT;
    try{
        if(!((boom*)DS)->RemoveCourse(courseID))
        {
            return FAILURE;
        }
    }
    catch(...){
        return ALLOCATION_ERROR;
    }
    return SUCCESS;
}

StatusType WatchClass(void *DS, int courseID, int classID, int time)
{
    if(courseID <=0 || classID <0 || DS==nullptr) return INVALID_INPUT;
    try{
        if(!((boom*)DS)->WatchClass(courseID,classID,time))
        {
            return FAILURE;
        }
        return SUCCESS;
    }
    catch(...){
        return ALLOCATION_ERROR;
    }
}

StatusType TimeViewed(void *DS, int courseID, int classID, int *timeViewed)
{
    if (DS==NULL, courseID<=0, classID<0 )
    {
        return INVALID_INPUT;
    }
    *timeViewed= ((boom*)DS)->TimeViewed(courseID , classID);
    if (*timeViewed == FAILURE) return FAILURE ; 
    else return SUCCESS;
}

StatusType GetMostViewedClasses(void *DS, int numOfClasses, int *courses, int *classes){
    if(numOfClasses <=0 || DS==nullptr) return INVALID_INPUT;
    try{
       if(!((boom*)DS)->GetMostViewedClasses(numOfClasses, courses, classes))
        {
            return FAILURE;
        }
    }
    catch (...)
    {
        return ALLOCATION_ERROR;
    }
    return SUCCESS;
}

void Quit(void** DS){
    delete(boom*)(DS);
}