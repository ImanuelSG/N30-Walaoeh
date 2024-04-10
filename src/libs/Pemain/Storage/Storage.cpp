#include "Storage.hpp"

template <class T, int N, int M>
Storage<T, N, M>::Storage()
{
    neff = 0;
    capacity = N;
}