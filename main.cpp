#include <iostream>
#include "AVLnode.h"
#include "AVLtree.h"
#include "course.h"

int main()
{
     AVLtree<course> newAVL;
 
    std::cout << "Inserting integer values 1 to 10" << std::endl;
    for (int i = 10; i > 0; i-=2)
    {
        std::cout<<"im inside the loop"<<std::endl;
        course* temp = new course(i);
        AVLnode<course>* newNode = new AVLnode<course> (*temp);
        newAVL.addVertex(newNode);
    }
    for (int i = 1; i < 10; i+=2)
    {
        std::cout<<"im inside the loop"<<std::endl;
        course* temp = new course(i);
        AVLnode<course>* newNode = new AVLnode<course> (*temp);
        newAVL.addVertex(newNode);
    }
    std::cout << "Printing tree: " << std::endl;
    newAVL.printTree();
}