#ifndef AVLNODE
#define AVLNODE
#include <iostream>

template <class T>
class AVLnode
{
    public:
    T info;  
    int balance;
    int height;
    AVLnode* left_son;
    AVLnode* right_son;
    AVLnode* parent;
    virtual bool operator<(const AVLnode<T> target) const;
    virtual bool operator>(const AVLnode<T> target) const ;
    virtual bool operator==(const AVLnode<T> target) const; 
    virtual bool operator<<(const AVLnode<T> target) const ;
    AVLnode(T info, int balance = 0, int height = 0, AVLnode* left_son = nullptr, AVLnode* right_son = nullptr, AVLnode* parent = nullptr)
    : info(info), balance(balance), height(height), left_son(left_son), right_son(right_son), parent(parent) {} 
};

#endif /* AVLNODE */