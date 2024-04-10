#include "Storage.hpp"

template <class T>
Storage<T>::Storage(int N, int M)
{
    buffer.resize(N, vector<T *>(M, nullptr)); // Initialize buffer with nullptrs

    neff = 0;
    row = N;
    col = M;
    capacity = N * M;
}

template <class T>
Storage<T>::~Storage()
{
    for (auto &row : buffer)
    {
        for (auto ptr : row)
        {
            delete ptr; // Delete objects pointed by pointers
        }
    }
}
template <class T>
void Storage<T>::insert(const T &obj)
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
}

template <class T>
void Storage<T>::insert(int row, int col, const T &obj)
{
    buffer[row][col] = &obj;
    neff++;
}

template <class T>
T &Storage<T>::deleteAt(int row, int col)
{
    if (buffer[row][col] != nullptr)
    {
        T &ref = buffer[row][col];
        buffer[row][col] = nullptr; // Set the pointer to nullptr
        neff--;
        return ref;
    }
}

template <class T>
bool Storage<T>::isEmpty()
{
    return neff == 0;
}

template <class T>
bool Storage<T>::isFull()
{
    return neff == capacity;
}

template <class T>
T &Storage<T>::getElement(int row, int col)
{
    return buffer[row][col];
}

template <class T>
void display(const Storage<T> &storage)
{
    // ================[ Penyimpanan ]==================
    cout << "     ";
    int numOfEq = (1 + 6 * storage.col - 15) / 2; // 15 is len([ Penyimpanan ])
    for (int i = 0; i < numOfEq; i++)
    {
        cout << "=";
    }
    cout << "[ Penyimpanan ]";
    for (int i = 0; i < numOfEq; i++)
    {
        cout << "=";
    }
    cout << endl;

    // Print the letters for each column
    cout << "     ";
    for (char c = 'A'; c < 'A' + storage.col; ++c)
    {
        cout << "   " << c << "  ";
    }
    cout << " " << endl;

    for (int i = 0; i < storage.col; ++i)
    {
        if (i == 0)
        {
            cout << "     +";
        }
        cout << "-----+";
    }
    cout << endl;
    for (int i = 0; i < storage.row; ++i)
    {
        cout << "  " << intToStringWithLeadingZero(i + 1) << " |";
        for (int j = 0; j < storage.col; ++j)
        {
            string keluaran = "";
            if (storage.buffer[i][j] != nullptr)
            {
                keluaran = (*storage.buffer[i][j]).getKodeHuruf();
            }
            if (keluaran == "")
            {
                keluaran = "   ";
            }
            cout << " " << keluaran << " |";
        }
        cout << endl;
        cout << "     +";
        for (int j = 0; j < storage.col; ++j)
        {
            cout << "-----+";
        }
        cout << endl;
    }
}