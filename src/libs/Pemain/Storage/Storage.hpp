#ifndef STORAGE_HPP
#define STORAGE_HPP

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <tuple>
#include <set>

#include "../../Sellable/Sellable.hpp"
#include "../../Hewan/Hewan.hpp"
#include "../../Tanaman/Tanaman.hpp"
#include "../../Exception/Exception.hpp"
using namespace std;

template <class T>
class Storage;

template <class T>
void display(const Storage<T> &storage);

template <class T>
map<string, tuple<vector<string>,int>> readyPanen(const Storage<T> &storage);

template <class T>
void displayItems(const Storage<T> &storage);

template <>
void display<Sellable>(const Storage<Sellable> &storage);

template <>
void display<Hewan>(const Storage<Hewan> &storage);

template <>
void display<Tanaman>(const Storage<Tanaman> &storage);

template <>
map<string, tuple<vector<string>,int>> readyPanen<Hewan>(const Storage<Hewan> &storage);

template <>
map<string, tuple<vector<string>,int>> readyPanen<Tanaman>(const Storage<Tanaman> &storage);

template <>
void displayItems<Hewan>(const Storage<Hewan> &storage);

template <>
void displayItems<Tanaman>(const Storage<Tanaman> &storage);

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
    Storage(int N, int M)
    {
        buffer.resize(N, vector<T *>(M, nullptr)); // Initialize buffer with nullptrs
        neff = 0;
        row = N;
        col = M;
        capacity = N * M;
    }

    /**
     * @brief Destroy the Storage object
     *
     */
    ~Storage() {}

    /**
     * @brief Get the Row attribute
     *
     * @return int
     */
    int getRow() const
    {
        return row;
    }

    /**
     * @brief Get the Col attribute
     *
     * @return int
     */
    int getCol() const
    {
        return col;
    }

    /**
     * @brief Get the Neff attribute
     *
     * @return int
     */
    int getNeff() const
    {
        return neff;
    }

    /**
     * @brief Get the Capacity attribute
     *
     * @return int
     */
    int getCapacity() const
    {
        return capacity;
    }

    /**
     * @brief Insert object to first empty slot
     *
     * @param obj Object to be inserted
     */
    void insert(T &obj)
    {
        bool found = false;
        int i = 0;
        while (i < row && !found)
        {
            int j = 0;
            while (j < col && !found)
            {
                if (buffer[i][j] == nullptr)
                {
                    buffer[i][j] = &obj;
                    found = true;
                }
                j++;
            }
            i++;
        }
        neff++;
    }

    /**
     * @brief Insert a new object at a specific location
     *
     * @param row Row position of new object (starting from zero)
     * @param col Col position of new object (starting from zero)
     * @param obj Object to be inserted
     */
    void insert(int row, int col, T &obj)
    {
        buffer[row][col] = &obj;
        neff++;
    }

    /**
     * @brief Delete an object entry at a specific location without destroying the object then returns the object
     *
     * @param row Row position of deleted object (starting from zero)
     * @param col Col position of deleted object (starting from zero)
     * @return T& Reference to the deleted object entry
     */
    T &deleteAt(int row, int col)
    {
        if (buffer[row][col] != nullptr)
        {
            T &ref = *(buffer[row][col]);

            buffer[row][col] = nullptr; // Set the pointer to nullptr
            neff--;
            return ref;
        }
        else
        {

            throw InvalidStorageIndexException();
        }
    }

    /**
     * @brief Check if the Storage is empty
     *
     * @return true if the Storage is empty
     * @return false otherwise
     */
    bool isEmpty()
    {
        return neff == 0;
    }

    /**
     * @brief Check if the Storage is full
     *
     * @return true if the Storage is full
     * @return false otherwise
     */
    bool isFull()
    {
        return neff == capacity;
    }

    /**
     * @brief Get the object from buffer[row][col]
     *
     * @param row Row position of object (starting from zero)
     * @param col Col position of object (starting from zero)
     * @return T* Pointer to object
     */
    T *getElementAddress(int row, int col)
    {
        return buffer[row][col];
    }

    /**
     * @brief Get number of empty slots
     *
     * @return number of empty slots
     */
    int countEmptySlot()
    {
        return capacity - neff;
    }

    /**
     * @brief Print storage with default inventory format
     *
     */
    friend void display<>(const Storage<T> &storage);
    /**
     * @brief Print daftar barang yang siap panen
     *
     */
    friend map<string, tuple<vector<string>,int>> readyPanen<>(const Storage<T> &storage);

    /**
     * @brief Print barang-barang yang ada di storage
     *
     */
    friend void displayItems<>(const Storage<T> &storage);
};

#endif