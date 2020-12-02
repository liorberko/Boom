#ifndef AVLNODE
#define AVLNODE
#include <iostream>
#include "library.h"

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
    AVLnode(T info);
    ~AVLnode() = default;
    AVLnode<T>& operator=(const AVLnode<T> target);
};

template <class T>
AVLnode<T>::AVLnode(T info): info(info), balance(0), height(0), left_son(nullptr), right_son(nullptr), parent(nullptr) {}

template <class T>
AVLnode<T>& AVLnode<T>::operator=(const AVLnode<T> target)
{
    info = target.info;
    balance = target.balance;
    height = target.height;
    left_son = target.left_son;
    right_son = target.right_son;
    parent = target.parent;
    return *this;
}

#endif /* AVLNODE */