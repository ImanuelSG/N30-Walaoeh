#ifndef STORAGE_HPP
#define STORAGE_HPP

#include <iostream>


template<class T>
class Storage{
    private:
        T& array[][];
        int neff;
        int capacity;
    public:
        Storage(int N, int M);
        ~Storage();
        void insert(const T& obj);
        void insert(int row, int col, const T& obj);
        void deleteAt(int row, int col);
        bool isEmpty();
        bool isFull();
        void display();
};

#endif

