#ifndef STORAGE_HPP
#define STORAGE_HPP

#include <iostream>
#include <vector>
#include <string>
#include "../../Sellable/Sellable.hpp"
#include "../../Utils/Utils.hpp"
using namespace std;

template <class T>
class Storage;

template <class T>
void display(const Storage<T> &storage);

template <>
void display<Sellable>(const Storage<Sellable> &storage);

template <class T>
class Storage
{
private:
    vector<vector<T *>> buffer;
    int neff;
    int row;
    int col;
    int capacity;

public:
    /**
     * @brief Construct a new Storage object
     *
     * @param N Num of Rows
     * @param M Num of Cols
     */
    Storage(int N, int M);
    /**
     * @brief Destroy the Storage object
     *
     */
    ~Storage();
    /**
     * @brief Insert object to first empty slot
     *
     * @param obj Object to be inserted
     */
    void insert(const T &obj);

    /**
     * @brief Insert a new object at a specific location
     *
     * @param row Row position of new object (starting from zero)
     * @param col Col position of new object (starting from zero)
     * @param obj Object to be inserted
     */
    void insert(int row, int col, const T &obj);
    /**
     * @brief Delete an object entry at a specific location without destroying the object then returns the object
     *
     * @param row Row position of deleted object (starting from zero)
     * @param col Col position of deleted object (starting from zero)
     * @return T& Reference to the deleted object entry
     */
    T &deleteAt(int row, int col);
    /**
     * @brief Check if the Storage is empty
     *
     * @return true if the Storage is empty
     * @return false otherwise
     */
    bool isEmpty();
    /**
     * @brief Check if the Storage is full
     *
     * @return true if the Storage is full
     * @return false otherwise
     */
    bool isFull();
    /**
     * @brief Get the object from buffer[row][col]
     *
     * @param row Row position of object (starting from zero)
     * @param col Col position of object (starting from zero)
     * @return T& Reference to object
     */
    T &getElement(int row, int col);
    /**
     * @brief Print storage with default inventory format
     *
     */
    friend void display<>(const Storage<T> &storage);
};

#endif