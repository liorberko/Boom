#ifndef AVLTREE
#define AVLTREE
#include "AVLnode.h"
#include "library.h"
#include <iostream>
template <class T>
class AVLtree
{
    AVLnode<T> *root;
    AVLnode<T> *biggest;
    AVLnode<T> *smallest;
    AVLnode<T>* rotateLeftLeft(AVLnode<T> *vertex);
    AVLnode<T>* rotateRightRight(AVLnode<T> *vertex);
    AVLnode<T>* rotateLeftRight(AVLnode<T> *vertex);
    AVLnode<T>* rotateRightLeft(AVLnode<T> *vertex);
    int setHeight(AVLnode<T> *vertex);
    void rebalance(AVLnode<T> *vertex);
    void setBalance(AVLnode<T> *vertex);

    public:
    AVLtree();
    ~AVLtree();
    AVLnode<T>* getRoot();
    StatusType addVertex(AVLnode<T> *new_vertex);
    StatusType removeVertex(AVLnode<T> *new_vertex);
    StatusType applyFromRight(int &num, void (*doSomething)(AVLnode<T> *item, int &max_actions));
    static void deleteNode(AVLnode<T> *toDelete);
    void printBalance();
    void printTree();
    StatusType inOrder(AVLnode<T> *target, void (*doSomething)(AVLnode<T> *item));
    StatusType postOrder(AVLnode<T> *target, void (*doSomething)(AVLnode<T> *item));
};

/**************************************/
/*      Explore function section      */
/**************************************/
template <class T>
StatusType AVLtree<T>::inOrder(AVLnode<T> *target, void (*doSomething)(AVLnode<T> *item)){
    if (target == nullptr)
    {
        return SUCCESS;
    }
    if (inOrder(target->left_son,doSomething) == SUCCESS)
    {
        return SUCCESS;
    }
    doSomething(target);
    if (inOrder(target->right_son, doSomething) == SUCCESS)
    {
        return SUCCESS;
    }
    else
    {
        return FAILURE;
    }     
}

template <class T>
AVLnode<T>* AVLtree<T>::getRoot(){
    return root;
}

template <class T>
StatusType AVLtree<T>::postOrder(AVLnode<T> *target, void (*doSomething)(AVLnode<T> *item)){
    if (target == nullptr)
    {
        return SUCCESS;
    }
    if (postOrder(target->left_son, doSomething) == SUCCESS)
    {
        return SUCCESS;
    }
    if (postOrder(target->right_son ,doSomething) == SUCCESS)
    {
        return SUCCESS;
    }
    doSomething(target);
    return SUCCESS;

}

template <class T>
int reversInOrder(AVLnode<T> *target, void (*doSomething)(AVLnode<T> *item, int &max_actions),int &num){
    if ((target == nullptr) || (num <= 0))
    {
        return 0;
    }
    int temp = reversInOrder(target->right_son, doSomething ,num);
    if (num <= 0)
    {
        return temp;
    }
    doSomething(target,num);
    num--;
    temp++;
    temp += reversInOrder(target->left_son, doSomething, num);
    return temp; 
}

template <class T>
StatusType applyFromRightHelper(int &num, AVLnode<T>* target, void (*doSomething)(AVLnode<T> *item, int &max_actions))  
{
    if ((target == nullptr) || (num == 0))
    {
        return SUCCESS;
    }
    doSomething(target, num);
    num--;
    int temp = reversInOrder(target->left_son , doSomething, num );
    if (applyFromRightHelper(&num,target->parent,doSomething)!=SUCCESS)
    {
        return FAILURE;
    } 
    return SUCCESS;
}

template <class T>
StatusType AVLtree<T>::applyFromRight(int &num, void (*doSomething)(AVLnode<T> *item, int &max_actions))  
{
    return applyFromRightHelper(num, biggest, doSomething);
}

/**************************************/
/*     C'tors and D'tors section      */
/**************************************/
template <class T>
AVLtree<T>::AVLtree() : root(nullptr),biggest(nullptr),smallest(nullptr) {}

template <class T> 
void AVLtree<T>::deleteNode(AVLnode<T> *toDelete)
{
    delete(toDelete);
}

template <class T>
AVLtree<T>::~AVLtree()
{
    postOrder(root, AVLtree<T>::deleteNode);
}

/****************************************/
/*     Method implementation section    */
/****************************************/


template <class T>
StatusType AVLtree<T>::addVertex(AVLnode<T> *new_vertex)  {
    if(root==NULL){
        root= new_vertex;
    }
    if ((biggest == nullptr) || (biggest->info < new_vertex->info))
    {
        biggest = new_vertex;
    }
    if ((smallest == nullptr) || (smallest->info > new_vertex->info))
    {
        smallest = new_vertex;
    }
    AVLnode<T> *current_vertex = root;
    AVLnode<T> *parent; // so we have a grasp on parent vertex
    while(true)
    {
        if(current_vertex->info==new_vertex->info) return FAILURE; // this vertex already exists.
        parent=current_vertex;
        bool procede_left;
        if(current_vertex->info>new_vertex->info) procede_left = true;// if current node bigger then new node, we need to go left.
        else procede_left = false;// else we need to go right
        current_vertex = procede_left ? current_vertex->left_son : current_vertex->right_son;
        //when adding a new vertex it must become a leaf at first
        if(current_vertex==NULL)
        { // we made it all the way down to find new leaf spot
            if ((parent->left_son == nullptr ) && (parent->right_son == nullptr)) parent->height++;
            if(procede_left){
                parent->left_son = new_vertex;
            }
            else{
                parent->right_son = new_vertex;
            }
            new_vertex->parent=parent;
            setBalance(parent);
            new_vertex->height=0;
            //parent->height++;
            while(parent->parent != NULL && parent->height == parent->parent->height){
                //if the height of the parent of the vertex is bigger by 1 from the vertex's height then the
                //the tree above is already balanced.
                parent=parent->parent;
                rebalance(parent);
                parent->height=setHeight(parent);
            }
            while(parent != NULL)
            {
                setBalance(parent);
                parent=parent->parent;
            }
            break;
        }
    }
return SUCCESS;
}

template <class T>
AVLnode<T>* AVLtree<T>::rotateLeftLeft(AVLnode<T> *vertex){
    AVLnode<T> *p=vertex->parent;
    AVLnode<T> *b=vertex->left_son;
    if(b->right_son!=NULL) b->right_son->parent=vertex;
    vertex->left_son = b->right_son;
    b->right_son=vertex;
    vertex->parent=b;
    b->parent=p;
    if(p!=NULL){
        if(p->left_son==vertex){
            p->left_son=b;
        }
        else{
            p->right_son=b;
        }
    }
    else{
        root=b;
    }
    vertex->height = setHeight(vertex);
    b->height=setHeight(b);
    setBalance(vertex);
    setBalance(b);
    return b;
}

template <class T>
AVLnode<T>* AVLtree<T>::rotateRightRight(AVLnode<T> *vertex){
    AVLnode<T> *p=vertex->parent;
    AVLnode<T> *c=vertex->right_son;
    if(c->left_son!=NULL) c->left_son->parent=vertex;
    vertex->right_son = c->left_son;
    c->left_son=vertex;
    vertex->parent=c;
    c->parent=p;
    if(p!=NULL){
        if(p->right_son==vertex){
            p->right_son=c;
        }
        else{
            p->left_son=c;
        }
    }
    else
    {
        root = c;
    }
    vertex->height = setHeight(vertex);
    c->height=setHeight(c);
    setBalance(vertex);
    setBalance(c);
    return c;
    
}
template<class T>
AVLnode<T>* AVLtree<T>::rotateLeftRight(AVLnode<T> *vertex){
    vertex->left_son=rotateRightRight(vertex->left_son);
    rotateLeftLeft(vertex);
    return vertex;
}

template<class T>
AVLnode<T>* AVLtree<T>::rotateRightLeft(AVLnode<T> *vertex){
    vertex->right_son=rotateLeftLeft(vertex->right_son);
    rotateRightRight(vertex);
    return vertex;
}

template<class T>
int AVLtree<T>::setHeight(AVLnode<T> *vertex){
    if(vertex==NULL){
        return -1;
    }
    if ( vertex->left_son == nullptr && vertex->right_son == nullptr)
    {
        return 0;
    }
    else if(vertex->left_son == nullptr)
    {
        return (vertex->right_son->height +1);
    }
    else if (vertex->right_son == nullptr)
    {
        return (vertex->left_son->height +1);
    }
    return 1+std::max(vertex->left_son->height, vertex->right_son->height);
}

template <class T>
void AVLtree<T>::setBalance(AVLnode<T> *vertex) {
    if ( vertex->left_son == nullptr && vertex->right_son == nullptr)
    {
        vertex->balance=0;
        return;
    }
    else if(vertex->left_son == nullptr)
    {
        vertex->balance = -1 - vertex->right_son->height;
        return;
    }
    else if (vertex->right_son == nullptr)
    {
        vertex->balance = vertex->left_son->height + 1;
        return;
    }
    else vertex->balance = vertex->left_son->height - vertex->right_son->height;
}
template <class T>
void AVLtree<T>::rebalance(AVLnode<T> *vertex){
    int prev_balace= vertex->balance;
    setBalance(vertex);
    if(vertex->balance==-2){
        vertex->right_son->balance<=0 ? rotateRightRight(vertex) : rotateRightLeft(vertex);
    }
    if(vertex->balance==2){
        vertex->left_son->balance>=0 ? rotateLeftLeft(vertex) : rotateLeftRight(vertex);
    }
    
}
template <class T>
void printBalance(AVLnode<T> *vertex){
 if (vertex != NULL) {
        printBalance(vertex->left);
        std::cout << vertex->balance << " ";
        printBalance(vertex->right);
    }
}
template <class T>
void AVLtree<T>::printBalance() {
    printBalance(root);
    std::cout << std::endl;
}


template <class T>
StatusType AVLtree<T>::removeVertex(AVLnode<T> *ver_to_remove)
{
    AVLnode<T> *to_fix;
    if ((ver_to_remove->right_son == nullptr) &&(ver_to_remove->left_son == nullptr))
    {
        if (ver_to_remove->parent != nullptr)
        {
            if(ver_to_remove->parent->right_son == ver_to_remove)
            {
                ver_to_remove->parent->right_son = nullptr;
            }
            else 
            {
                ver_to_remove->parent->left_son = nullptr;
            }
        }
        to_fix = ver_to_remove->parent;
    }
    else if ((ver_to_remove->right_son == nullptr)  && !(ver_to_remove->left_son == nullptr))
    {
        if (ver_to_remove->parent != nullptr)
        {
            if(ver_to_remove->parent->right_son == ver_to_remove)
            {
                ver_to_remove->parent->right_son = ver_to_remove->left_son;
            }
            else 
            {
                ver_to_remove->parent->left_son = ver_to_remove->left_son;
            }
        }
        ver_to_remove->left_son->parent = ver_to_remove->parent;
        to_fix = ver_to_remove->left_son;
    }
    else if (!(ver_to_remove->right_son == nullptr)  && (ver_to_remove->left_son == nullptr))
    {
        if (ver_to_remove->parent != nullptr)
        {
            if(ver_to_remove->parent->right_son == ver_to_remove)
            {
                ver_to_remove->parent->right_son = ver_to_remove->right_son;
            }
            else 
            {
                ver_to_remove->parent->left_son = ver_to_remove->right_son;
            }
        }
        ver_to_remove->right_son->parent = ver_to_remove->parent;
        to_fix = ver_to_remove->right_son;
    }
    else
    {
        AVLnode<T> * temp1 = ver_to_remove->right_son;
        AVLnode<T> * temp2 = temp1->left_son;
        AVLnode<T> * temp3 = temp1->right_son;
        while (temp2 != nullptr)
        {
            temp3 = temp2->right_son;
            temp1 = temp2;
            temp2 = temp2->left_son;
        }
        if(temp1->parent->right_son == temp1)
        {
            temp1->parent->right_son = temp3;
            if (temp3 != nullptr)
            {
                temp3->parent = temp1->parent;
            }
        }
        else    
        {
            temp1->parent->left_son = temp3;
            if (temp3 != nullptr)
            {
                temp3->parent = temp1->parent;
            }
        }
        temp1->right_son = ver_to_remove->right_son;
        if (temp1->right_son != nullptr)
        {
            temp1->right_son->parent = temp1;
        }
        temp1->left_son = ver_to_remove->left_son;
        if (temp1->left_son != nullptr)
        {
            temp1->left_son->parent = temp1;
        }
        to_fix = temp1->parent;
        if (root == ver_to_remove)
        {
            root = temp1;
            temp1->parent = nullptr;
        }
        else
        {
            temp1->parent = ver_to_remove->parent;
            if(ver_to_remove->parent->right_son == ver_to_remove)
            {
                ver_to_remove->parent->right_son = temp1;
            }
            else 
            {
                ver_to_remove->parent->left_son = temp1;
            }
        }
    }
    AVLnode<T> *to_fix_balance = to_fix;
    while(to_fix_balance != NULL)
    {
        to_fix_balance->height = setHeight(to_fix_balance);
        setBalance(to_fix_balance);
        to_fix_balance=to_fix_balance->parent;
    }
    while (to_fix != nullptr)
    {
        rebalance(to_fix);
        to_fix = to_fix->parent;
    }
    ver_to_remove->parent = nullptr;
    ver_to_remove->right_son = nullptr;
    ver_to_remove->left_son = nullptr;
return SUCCESS;
}

template <class T>
void printVertex(AVLnode<T> *vertex) {
    std::cout <<"info:"<< std::endl;
    std::cout <<vertex->info<< std::endl;
    std::cout <<"balance:"<< std::endl;
    std::cout <<vertex->balance<< std::endl;
    std::cout <<"left son:"<< std::endl;
    std::cout <<vertex->left_son->info<< std::endl;
    std::cout <<"right son:"<< std::endl;
    std::cout <<vertex->right_son->info<< std::endl;
    std::cout <<"parent:"<< std::endl;
    std::cout <<vertex->parent->info<< std::endl;
    std::cout << std::endl;
}
template <class T>
void AVLtree<T>::printTree() {
    inOrder(root,printVertex);
    std::cout <<"the end"<< std::endl;
}
    

#endif  