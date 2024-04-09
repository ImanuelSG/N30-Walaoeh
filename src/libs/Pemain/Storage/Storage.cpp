#include "Storage.hpp"

template<class T>
Storage<T>::Storage(int N, int M) {
    array = new T**[N];
    for (int i = 0; i < N; i++) {
        array[i] = new T*[M];
        for (int j = 0; j < M; j++) {
            array[i][j] = nullptr;
        }
    }
    neff = 0;
    capacity = N * M;
}

template<class T>
Storage<T>::~Storage() {
    for (int i = 0; i < N; i++) {
        delete[] array[i];
    }
    delete[] array;
}

template<class T>
void Storage<T>::insert(const T& obj) {
    bool found = false;
    int i = 0;
    while (i < N && !found) {
        int j = 0;
        while (j < M && !found) {
            if (array[i][j] == nullptr) {
                array[i][j] = &obj;
                found = true;
            }
            j++;
        }
        i++;
    }
}

template<class T>
void Storage<T>::insert(int row, int col, const T& obj) {
    array[row][col] = &obj;
    neff++;
}

template<class T>
void Storage<T>::deleteAt(int row, int col) {
    array[row][col] = nullptr;
    neff--;
}

template<class T>
bool Storage<T>::isEmpty() {
    return neff == 0;
}

template<class T>
bool Storage<T>::isFull() {
    return neff == capacity;
}

// template<class T>
// void Storage<T>::display() {

// }