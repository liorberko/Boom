// #include <iostream>
// #include "AVLnode.h"
// #include "AVLtree.h"
// #include "course.h"


// int main()
// {
//      AVLtree<course, int> newAVL;
 
//     std::cout << "Inserting integer values 1 to 10" << std::endl;
//     for (int i = 10; i > 0; i-=2)
//     {
//         std::cout<<"im adding new course"<<std::endl;
//         course* temp = new course(i,i);
//         AVLnode<course,int>* newNode = new AVLnode<course,int> (*temp,i);
//         newAVL.addVertex(newNode);
//     }
//     for (int i = 1; i < 10; i+=2)
//     {
//         std::cout<<"im inside the loop"<<std::endl;
//         course* temp = new course(i,i);
//         AVLnode<course,int>* newNode = new AVLnode<course,int> (*temp,i);
//         newAVL.addVertex(newNode);
//     }
//     // for (int i = 1; i < 10; i+=2)
//     // {
//     //     std::cout<<"remove"<<std::endl;
//     //     newAVL.removeVertex(newAVL.getRoot());
//     // }
//     newAVL.printTree();
// }
