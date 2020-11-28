#ifndef AVLTREE
#define AVLTREE
#include "AVLnode.h"
#include "library.h"

template <class T>
class AVLtree
{
    node<T> *root;
    node<T> *bigest;
    node<T> *smallest;
    StatusType rotateRight(const node<T> *vertex);
    StatusType rotateLeft(const node<T> *vertex);
    StatusType rotateLeftToRight(const node<T> *vertex);
    StatusType rotateRightThenLeft(const node<T> *vertex);

    public:
    AVLtree();
    ~AVLtree();
    StatusType addVertex(const node<T> *new_vertex);
    StatusType removeVertex(int key);
};
/**************************************/
/*     C'tors and D'tors section      */
/**************************************/
template <class T>
AVLtree(root=NULL,bigget=NULL,smallest=NULL):root(root),biggest(biggest),smallest(smallest);

template <class T>
~AVLtree()
{
    node<t> *current;
    while (current.rightSun 
    {
        /* code */
    }
}
template <class T>
StatusType addVertex(const node<T> *new_vertex)  



#endif