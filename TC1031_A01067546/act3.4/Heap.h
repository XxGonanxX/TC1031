
#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <climits>
#include <sstream>
#include <cmath>

bool isPowerOfTwo(int n)
{
    return (std::ceil(std::log2(n)) == std::floor(std::log2(n)));
}

typedef unsigned int uint;

template <class T>
class Heap
{
private:
    std::vector<T> hvec;

    uint parent(uint child) const { return (child - 1) / 2; }
    uint left(uint parent) const { return (parent * 2) + 1; }
    uint right(uint parent) const { return (parent * 2) + 2; }

    void swap(uint, uint);

public:
    Heap() {}

    uint size() const;
    bool empty() const;

    void heapify(uint);

    T top() const;
    void push(T);
    int pop();


};

template <class T>
/**
 * @brief 
 * @param i
 * @param j
 */
void Heap<T>::swap(uint i, uint j)
{
    T temp = hvec[i];
    hvec[i] = hvec[j];
    hvec[j] = temp;
}

template <class T>
/**
 * @brief 
 * @return uint
 */
uint Heap<T>::size() const
{
    return hvec.size();
}

template <class T>
/**
 * @brief 
 * @return true
 * @return false
 */
bool Heap<T>::empty() const
{
    return hvec.empty();
}

template <class T>
/**
 * @brief 
 * @param i
 */
void Heap<T>::heapify(uint i)
{
    uint le = left(i);
    uint ri = right(i);
    uint min = i;

    if (le < hvec.size() && hvec[le] < hvec[min])
        min = le;

    if (ri < hvec.size() && hvec[ri] < hvec[min])
        min = ri;

    if (i != min)
    {
        swap(i, min);
        heapify(min);
    }
}



template <class T>
/**
 * @brief 
 * @param val
 */
void Heap<T>::push(T val)
{
    hvec.push_back(val);
    uint pos = hvec.size() - 1;
    while (pos > 0 && val < hvec[parent(pos)])
    {
        swap(pos, parent(pos));
        pos = parent(pos);
    }
}

template <class T>
/**
 * @brief 
 */
int Heap<T>::pop()
{
    if (empty())
        return INT_MAX;

    int aux = hvec[0];
    hvec[0] = hvec[hvec.size() - 1];
    hvec.pop_back();
    heapify(0);
    return aux;
}



#endif