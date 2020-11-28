#ifndef NODE
#define NODE
template <class T>
class node
{
    public:
    int key;
    T info;  
    int balance;
    node* left_son;
    node* right_son;
    node* parent; 
    AVLnode(T info, node* left_son = nullptr, node* right_son = nullptr, node* prev = nullptr) : info(info), left_son(left_son),right_son(right_son),parent(parent);
    ~AVLnode() = default;
};

#endif /* NODE */