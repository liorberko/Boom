#include "AVLnode.h"
#include "AVLtree.h"
#include <iostream>

main(){
    AVLtree<int> t;
 
    std::cout << "Inserting integer values 1 to 10" << std::endl;
    for (int i = 1; i <= 10; ++i)
        t.addVertex(i);
 
    std::cout << "Printing balance: ";
    t.printBalance();
}