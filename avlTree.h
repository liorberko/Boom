#ifndef AVLTREE
#define AVLTREE
#include "AVLnode.h"
#include "library.h"
#include <stdlib>
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
    static void deleteNode(AVLnode<T> *toDelete);
    int height(AVLnode<T> *vertex);
    void rebalance(AVLnode<T> *vertex);
    void setBalance(AVLnode<T> *vertex);
    void printBalance(AVLnode *vertex);

    public:
    AVLtree();
    ~AVLtree();
    StatusType addVertex(const AVLnode<T> *new_vertex);
    StatusType removeVertex(AVLnode<T> *new_vertex);
    StatusType printFromRight(int num, AVLnode<T> biggest) const ;
};

/**************************************/
/*      Explore function section       */
/**************************************/
template <class T>
StatusType inOrder(AVLnode<T> *root, void* doSomething(AVLnode<T> *item))
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

template <class T>
StatusType postOrder(AVLnode<T> *root, void* doSomething(AVLnode<T> *item))
{
    if (root == nullptr)
    {
        return SUCCESS;
    }
    if (inOrdet(root->left_son) == SUCCESS)
    {
        return SUCCESS;
    }
    if (inOrdet(root->right_son) == SUCCESS)
    {
        return SUCCESS;
    }
    doSomething(root);
    else
    {
        return FAIULRE;
    }     
}

template <class T>
int reversInOrder(AVLnode<T> *root, AVLnode<T> **node_array ,int& num)
{
    if ((root == nullptr) || (num <= 0))
    {
        return 0;
    }
    int temp = reversInOrder(root->right_son, node_array&, num&);
    if (num <= 0)
    {
        return temp;
    }
    num--;
    *node_array = root;
    node_array++;
    temp++;
    temp += reversInOrder(root->left_son, node_array&, num&);
    return temp; 
}

/**************************************/
/*     C'tors and D'tors section      */
/**************************************/
template <class T>
AVLtree::AVLtree() : root(nullptr),biggest(nullptr),smallest(nullptr);

template <class T> 
static void AVLtree::deleteNode(AVLnode<T> *toDelete)
{
    delete(*toDelete);
    delete(toDelete);
}

static void AVLtree::printNode(AVLnode<T>*  to_print)
{
    
}

template <class T>
AVLtree::~AVLtree()
{
    postOrder(root, AVLtree::deleteNode);
}

/****************************************/
/*     Method implementation section    */
/****************************************/
template <class T>
StatusType AVLtree::printFromRight(int num, AVLnode<T>* biggest, AVLnode<T> ** node_array) const 
{
    if ((biggest == nullptr) || (num == 0))
    {
        return SUCCESS;
    }
    *node_array = biggest;
    num--;
    temp = reversInOrder(biggest->left_son , (node_array+1), num& )
    if (printFromRight(num& , biggest->parent, (node_array+temp+1)) != SUCCESS)
    {
        return FAIULRE;
    } 
    return SUCCESS;
}

template <class T>
StatusType AVLtree::addVertex(const AVLnode<T> *new_vertex)  {
    if(*this->root==nullptr){
        root=new AVLnode<T> (new_vertex->info,new_vertex->key);
    }
    else{
        AVLnode<T> *current_vertex = root;
        AVLnode<T> *parent; // so we have a grasp on parent vertex
        while(true){
            if(current_vertex->key==new_vertex->key) return FAIULRE; // this vertex already exists.
            parent=current;
            bool procede_left;
            if(current_vertex->key>new_vertex->key) procede_left = true;// if current key bigger then new vertex key, we need to go left.
            else procede_left = false;// else we need to go right
            current_vertex = procede_left ? current->left_son : current->right_son;
            //when adding a new vertex it must become a leaf at first
            if(current==nullptr){ // we made it all the way down to find new leaf spot
                if(procede_left){
                    parent->left_son = new AVLnode<T>(new_vertex->info,new_vertex->key);
                }
                else{
                    parent->right_son = new AVLnode<T>(new_vertex->info,new_vertex->key);
                }
                rebalance(parent);// when adding a new vertex theres a need for only one roatation.
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
            p->left_son=b);
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
            p->right_son=c);
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
    vertex->left_son=rotateRightRight(vertex->left);
    rotateLeftLeft(*vertex);
    return SUCCESS;
}
template<class T>
StatusType AVLtree<T>::rotateRightLeft(const AVLnode<T> *vertex){
    vertex->right_son=rotateRightRight(vertex->right);
    rotateLeftLeft(*vertex);
    return SUCCESS;
}
template<class T>
int height(AVLnode<T> *vertex){
    if(vertex==NULL){
        return -1;
    }
    return 1+std::max(height(height(vertex->left_son), height(vertex->right_son))
}
template <class T>
void AVLtree<T>::setBalance(AVLnode<T> *vertex) {
    vertex->balance = height(n->right) - height(n->left);
}
template <class T>
void rebalance(AVLnode<T> *vertex){
    setBalance(vertex);
    if(vertex->balance==-2){
        if(vertex->right_son->balance<=0){
            roataeRightRight(*vertex);
        }
        else if(vertex->right_son->balance==1){
            rotateRightLeft(*vertex);
        }
    }
    if(vertex->balance==2){
        if(vertex->left_son->balance>=0){
            roataeLeftLeft(*vertex);
        }
        else if(vertex->right_son->balance==-1){
            rotateLeftRight(*vertex);
        }
    }
template <class T>
void printBalance(AVLnode *vertex){
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

StatusType AVLtree::removeVertex(AVLnode<T> *ver_to_remove)
{
    if ((ver_to_remove->right_sun == nullptr) &&(ver_to_remove->left_son == nullptr))
    {
        if (ver_to_remove->parent =! nullptr)
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
    else if ((ver_to_remove->right_sun == nullptr)  && !(ver_to_remove->left_son == nullptr))
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
    else if (!(ver_to_remove->right_sun == nullptr)  && (ver_to_remove->left_son == nullptr))
    {
        if(ver_to_remove->parent->right_son == ver_to_remove)
        {
            ver_to_remove->parent->right_son = ver_to_remove->right_sun;
        }
        else 
        {
            ver_to_remove->parent->left_son = ver_to_remove->right_sun;
        }
    }
    else
    {
        AVLnode<T> * temp1 = ver_to_remove->right_sun;
        AVLnode<T> * temp2 = temp1->left_son;
        AVLnode<T> * temp3 = temp1->right_sun;
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
        temp1->right_sun = ver_to_remove->right_sun;
        temp1->right_sun->perenr = temp1;
        temp1->left_son = ver_to_remove->left_son;
        temp1->left_son->perenr = temp1;
        if (root == ver_to_remove)
        {
            room = temp1;
        }
        else
        {
            temp1->perent = ver_to_remove->parent;
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

}

    

#endif