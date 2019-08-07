#include "../share/shareHead.h"

#pragma once
#ifndef _MyDSAVECTOR_H_
#define _MyDSAVECTOR_H_
namespace MyDSA
{
    #define DEFAULT_CAPACITY 3
    template <typename T>
    class vector
    {
    protected:
        T * _data;
        Rank _size;
        Rank _capacity;

        void copyFrom(T * addr, Rank lo, Rank hi);
        void expand();

    public:
        vector(T * first, T* last);
        vector(T * addr, int count);
        vector(int count, T const & e);
        vector(vector<T> & src);

        Rank const & size() const {return _size;}
        T& operator[] (Rank r) const {return _data[r];}
        T & front() const {return _data[0];}
        T & back() const {return _data[_size-1];}
        

        Rank insert(Rank r, T const & e);
        // Rank insert(Rank r, T * first, T * last);
        Rank push_back(T const & e) { return insert(_size,e);}
        Rank erase(Rank lo, Rank hi);
        void pop_back() {erase(_size-1,_size); }

        ~vector() { delete [] _data; };
    };    
}

#include "vector_implemention.h"

#endif