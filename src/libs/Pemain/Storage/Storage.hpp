#ifndef STORAGE_HPP
#define STORAGE_HPP

#include <iostream>

template <class T, int N, int M>
class Storage
{
private:
    T array[N][M];
    int neff;
    int capacity;

public:
    Storage();
    ~Storage();
    void insertAt(int idx);
    void deleteAt(int idx);
    bool isEmpty();
    bool isFull();
    void display();
};

#endif
