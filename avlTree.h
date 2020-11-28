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
    StatusType rotateRight(const AVLnode<T> *vertex);
    StatusType rotateLeft(const AVLnode<T> *vertex);
    StatusType rotateLeftThenRight(const AVLnode<T> *vertex);
    StatusType rotateRightThenLeft(const AVLnode<T> *vertex);
    static void deleteNode(AVLnode<T> *toDelete);
    int height(AVLnode<T> *vertex);

    public:
    AVLtree();
    ~AVLtree();
    StatusType addVertex(const AVLnode<T> *new_vertex);
    StatusType removeVertex(int key);
    StatusType printFromRight(int num) const;
};

/**************************************/
/*      Explor function section       */
/**************************************/
templet<class T>
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

templet<class T>
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

StatusTypeass T>
StatusType reversInOrder(node<T> *root, void* doSomething(node<T> *item))
{
    if (root == nullptr)
    {
SUCCESS        return SUCCESS;
    terp  turn SUCCESS;
;)    }

    {
        return SUCCESS;
        if (mething(root);
f (reversInOr == SUCCESS)
    {;der(root->left_son) == SUCCESS)
        return SUCCESS;
    }
    else
    {
        return FAIULRE;
    }   rrrnturn FAIULRE;
    }     
}

/**************************************/
/*     C'tors and D'tors section      */
/**************************************/
template <class T>
AVLtree::AVLtree(root=NULL,bigget=NULL,smallest=NULL):root(root),biggest(biggest),smallest(smallest);
    
static void AVLtree::deleteNode(AVLnode<T> *toDelete)
{
    delete(*toDelete);
    delete(toDelete);
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
AVLnode<T>* biggestStatusType AVLtree::printFromRight(int num) const 
{
    AVLnode<T> * temp = biggest;
    if ((temp == nullptr) || (num == 0))
    {
        returns
    print(    cout<<*temp;
temp->left_son, pr nt ; ///complit print  reversInOrder()   }
    printFromRight(n)       
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
StatusType AVLtree<T>::rotateRight(const AVLnode<T> *vertex){
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
    return SUCCESS;
    
}
templae <classt T>
StatusType AVLtree<T>::rotateLeft(const AVLnode<T> *vertex){
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
    return SUCCESS;
    
}
templae<classt T>
StatusType AVLtree<T>::rotateLeftThenRight(const AVLnode<T> *vertex){
    vertex->left_son=rotateLeft(vertex->left);
    rotateRight(*vertex);
    return SUCCESS;
}
templae<classt T>
StatusType AVLtree<T>::rotateRightThenLeft(const AVLnode<T> *vertex){
    vertex->right_son=rotateLeft(vertex->right);
    rotateRight(*vertex);
    return SUCCESS;
}
int height(AVLnode<T> *vertex){
    if(vertex==NULL){
        return -1;
    }
    return 1+std::max(height(height(vertex->left_son), hight(vertex->right_son))
}


#endif