#ifndef AVLTREE
#define AVLTREE
#include "AVLnode.h"
#include "library.h"

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
    void printBalance();

    public:
    AVLtree();
    ~AVLtree();
    StatusType addVertex(const AVLnode<T> *new_vertex);
    StatusType removeVertex(int key);
    StatusType printFromRight(int num, AVLnode<T> biggest) const ;
};

/**************************************/
/*      Explor function section       */
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
        returns return SUCCESS;
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
    AVLnode<T> *current_vertex
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
    vertex->right_son=rotaterightright(vertex->left);
    rotateleftLeft(*vertex);
    return SUCCESS;
}
template<class T>
StatusType AVLtree<T>::rotateRightLeft(const AVLnode<T> *vertex){
    vertex->left_son=rotateRightRight(vertex->right);
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
if(vertex->balance==2){
if(vertex->left_son->balance>=0){
    roataeLeftLeft(*vertex);
}
else if(vertex->right_son->balance==-1){
    rotateLeftRight(*vertex);
}
}
#endif