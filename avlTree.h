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
    StatusType rotateLeftLeft(const AVLnode<T> *vertex);
    StatusType rotateRightRight(const AVLnode<T> *vertex);
    StatusType rotateLeftRight(const AVLnode<T> *vertex);
    StatusType rotateRightLeft(const AVLnode<T> *vertex);
    int setHeight(AVLnode<T> *vertex);
    void rebalance(AVLnode<T> *vertex);
    void setBalance(AVLnode<T> *vertex);

    public:
    AVLtree();
    ~AVLtree();
    StatusType addVertex(AVLnode<T> *new_vertex);
    StatusType removeVertex(AVLnode<T> *new_vertex);
    StatusType receiveFromRight(int num, AVLnode<T>* biggest, AVLnode<T> ** node_array) const ;
    static void deleteNode(AVLnode<T> *toDelete);
    void printBalance();
    void printTree();
};

/**************************************/
/*      Explore function section      */
/**************************************/
template <class T>
StatusType inOrder(AVLnode<T> *root, void (*doSomething)(AVLnode<T> *item)){
    if (root == nullptr)
    {
        return SUCCESS;
    }
    if (inOrder(root->left_son,doSomething) == SUCCESS)
    {
        return SUCCESS;
    }
    doSomething(root);
    if (inOrder(root->right_son, doSomething) == SUCCESS)
    {
        return SUCCESS;
    }
    else
    {
        return FAILURE;
    }     
}

template <class T>
StatusType postOrder(AVLnode<T> *root, void (*doSomething)(AVLnode<T> *item)){
    if (root == nullptr)
    {
        return SUCCESS;
    }
    if (inOrder(root->left_son, doSomething) == SUCCESS)
    {
        return SUCCESS;
    }
    if (inOrder(root->right_son ,doSomething) == SUCCESS)
    {
        return SUCCESS;
    }
    doSomething(root);
    return SUCCESS;

}

template <class T>
int reversInOrder(AVLnode<T> *root, AVLnode<T> **node_array ,int &num){
    if ((root == nullptr) || (num <= 0))
    {
        return 0;
    }
    int temp = reversInOrder(root->right_son, node_array ,num);
    if (num <= 0)
    {
        return temp;
    }
    num--;
    *node_array = root;
    node_array++;
    temp++;
    temp += reversInOrder(root->left_son, node_array, num);
    return temp; 
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
StatusType AVLtree<T>::receiveFromRight(int num, AVLnode<T>* biggest, AVLnode<T> ** node_array) const 
{
    if ((biggest == nullptr) || (num == 0))
    {
        return SUCCESS;
    }
    *node_array = biggest;
    num--;
    int temp = reversInOrder(biggest->left_son , (node_array+1), &num );
    if (receiveFromRight(&num,biggest->parent,(node_array+temp+1))!=SUCCESS)
    {
        return FAILURE;
    } 
    return SUCCESS;
}

template <class T>
StatusType AVLtree<T>::addVertex(AVLnode<T> *new_vertex)  {
    if(root==NULL){
        root= new_vertex;
    }
    else{
        AVLnode<T> *current_vertex = root;
        AVLnode<T> *parent; // so we have a grasp on parent vertex
        while(true){
            if(current_vertex->info==new_vertex->info) return FAILURE; // this vertex already exists.
            parent=current_vertex;
            bool procede_left;
            if(current_vertex->info>new_vertex->info) procede_left = true;// if current node bigger then new node, we need to go left.
            else procede_left = false;// else we need to go right
            current_vertex = procede_left ? current_vertex->left_son : current_vertex->right_son;
            //when adding a new vertex it must become a leaf at first
            if(current_vertex==NULL){ // we made it all the way down to find new leaf spot
                if(procede_left){
                    parent->left_son = new_vertex;
                }
                else{
                    parent->right_son = new_vertex;
                }
                new_vertex->parent=parent;
                new_vertex->height=0;
                parent->height++;
                while(parent->parent != NULL && parent->height == parent->parent->height){
                    //if the height of the parent of the vertex is bigger by 1 from the vertex's height then the
                    //the tree above is already balanced.
                    parent=parent->parent;
                    setBalance(parent);
                    parent->height=setHeight(parent);
                }
                break;
            }
        
        }
    }
    return SUCCESS;
}
template <class T>
StatusType AVLtree<T>::rotateLeftLeft(const AVLnode<T> *vertex){
    AVLnode<T> *p=vertex->parent;
    AVLnode<T> *b=vertex.left_son;
    if(b->right_son->parent!=NULL) b->right_son->parent=vertex;
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
    setBalance(vertex);
    setBalance(b);
    return SUCCESS;
}
template <class T>
StatusType AVLtree<T>::rotateRightRight(const AVLnode<T> *vertex){
    AVLnode<T> *p=vertex->parent;
    AVLnode<T> *c=vertex.right_son;
    if(c->left_son->parent!=NULL) c->left_son->parent=vertex;
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
    setBalance(vertex);
    setBalance(c);
    return SUCCESS;
    
}
template<class T>
StatusType AVLtree<T>::rotateLeftRight(const AVLnode<T> *vertex){
    vertex->left_son=rotateRightRight(vertex->left_son);
    rotateLeftLeft(*vertex);
    return SUCCESS;
}
template<class T>
StatusType AVLtree<T>::rotateRightLeft(const AVLnode<T> *vertex){
    vertex->right_son=rotateRightRight(vertex->right_son);
    rotateLeftLeft(*vertex);
    return SUCCESS;
}
template<class T>
int AVLtree<T>::setHeight(AVLnode<T> *vertex){
    if(vertex==NULL){
        return -1;
    }
    return 1+std::max(vertex->left_son->height, vertex->right_son->height);
}
template <class T>
void AVLtree<T>::setBalance(AVLnode<T> *vertex) {
    vertex->balance = vertex->left_son->height - vertex->right_son->height;
}
template <class T>
void rebalance(AVLnode<T> *vertex){
    int prev_balace= vertex->balance;
    setBalance(vertex);
    if(vertex->balance==-2){
        vertex->right_son->balance<=0 ? roataeRightRight(*vertex) : rotateRightLeft(*vertex);
    }
    if(vertex->balance==2){
        vertex->left_son->balance>=0 ? roataeLeftLeft(*vertex) : rotateLeftRight(*vertex);
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
    }
    else if ((ver_to_remove->right_son == nullptr)  && !(ver_to_remove->left_son == nullptr))
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
    else if (!(ver_to_remove->right_son == nullptr)  && (ver_to_remove->left_son == nullptr))
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
        }
        else    
        {
            temp1->parent->left_son = temp3;
        }
        temp1->right_son = ver_to_remove->right_son;
        temp1->right_son->parent = temp1;
        temp1->left_son = ver_to_remove->left_son;
        temp1->left_son->parent = temp1;
        if (root == ver_to_remove)
        {
            root = temp1;
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
    AVLnode<T> *to_fix = ver_to_remove->parent;
    while (to_fix->parent != nullptr)
    {
        rebalance(to_fix->parent);
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