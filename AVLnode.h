#ifndef AVLNODE
#define AVLNODE
#include <iostream>
#include "library.h"


template <class T, class M>
class AVLnode
{
    public:
    T info; 
    M key;
    int balance;
    int height;
    AVLnode* left_son;
    AVLnode* right_son;
    AVLnode* parent;
    AVLnode(T info, M key);
    ~AVLnode() = default;
    AVLnode<T,M>& operator=(const AVLnode<T,M> target);
};

template <class T, class M>
AVLnode<T,M>::AVLnode(T info, M key): info(info), key(key), balance(0), height(0), left_son(nullptr), right_son(nullptr), parent(nullptr) {}

template <class T, class M>
AVLnode<T,M>& AVLnode<T,M>::operator=(const AVLnode<T,M> target)
{
    if (this == &target)
    {
        return *this;
    }
    info = target.info;
    key = target.key;
    balance = target.balance;
    height = target.height;
    left_son = target.left_son;
    right_son = target.right_son;
    parent = target.parent;
    return *this;
}

#endif /* AVLNODE */