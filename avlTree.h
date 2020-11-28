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
    node<t> *toRemove = root;
    while (toRemove->left_son != nullptr)
    {
        toRemove = toRemove->left_son;
    }
    if (toRemove->right_sun != nullptr)
    {
        node<T>* temp = toRemove;
        toRemove = toRemove->parent;
        delete (*temp);
        delete (temp);
    }
}

templet<class T>
StatusType inOrder(node<T> *root, void* doSomething(node<T> *item))
{
    if (root == nullptr)
    {
        return SUCCESS;
    }
    if (inOrdet(root->left_son) == SUCCESS)
    {
        return SUCCESS;
    }
    doSomething(root);
    if (inOrdet(root->right_son) == SUCCESS)
    {
        return SUCCESS;
    }
    else
    {
        return FAIULRE;
    }     
}

templet<class T>
StatusType reversInOrder(node<T> *root, void* doSomething(node<T> *item))
{
    if (root == nullptr)
    {
        return SUCCESS;
    }
    if (reversInOrder(root->right_son) == SUCCESS)
    {
        return SUCCESS;
    }
    doSomething(root);
    if (reversInOrder(root->left_son) == SUCCESS)
    {
        return SUCCESS;
    }
    else
    {
        return FAIULRE;
    }     
}
template <class T>
StatusType addVertex(const node<T> *new_vertex)  {
    node<T> *current_vertex
    while(true){
        if(current_vertex->right_son!=NULL && new_vertex->key>current_vertex->key){
           *current_vertex=current_vertex->right_son;
        }
        else if(new_vertex->key>current_vertex->key){
            break; // we need to put the new vertex as right son to the current vretex.
        }
        else if(current_vertex->left_son!=NULL && new_vertex->key<current_vertex->key){
            *current_vertex=current_vertex->left_son;
        }
        else if(new_vertex->key<current_vertex->key){
            break; // we need to put the new vertex as left son to the current vertex
        }
        else if (current_vertex->key==new_vertex->key){
            return FAILURE;
        }
        else if(current_vertex->left_son==NULL && current_vertex->right_son==NULL){
            //then we need to put the new vertex between the current vertex and its parent.
        }
    }
}
StatusType rotateRight(const node<T> *vertex){
    
}



#endif