#ifndef AVLNODE
#define AVLNODE
template <class T>
class AVLnode
{
    public:
    int key;
    T info;  
    int balance;
    AVLnode* left_son;
    AVLnode* right_son;
    AVLnode* parent; 
    AVLnode(T info, AVLnode* left_son = nullptr, AVLnode* right_son = nullptr, AVLnode* prev = nullptr) : info(info), left_son(left_son),right_son(right_son),parent(parent);
    ~AVLnode() = default;
};

#endif /* AVLNODE */