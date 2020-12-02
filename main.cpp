#include <iostream>
#include "AVLnode.h"
#include "AVLtree.h"
#include "course.h"

int main()
{
     AVLtree<int> newAVL;
 
    std::cout << "Inserting integer values 1 to 10" << std::endl;
    for (int i = 1; i <= 10; ++i)
    {
        course temp(i);
        newAVL.addVertex(&temp);
    }
    std::cout << "Printing balance: " << std::endl;
    newAVL.printTree();
}
