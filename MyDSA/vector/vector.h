#pragma once
#ifndef _MyDSAVECTOR_H_
#define _MyDSAVECTOR_H_
namespace MyDSA
{
    #define DEFAULT_CAPACITY 3
    typedef int Rank;
    template <typename T>
    class vector
    {
    protected:
        T * data;
    public:
        vector(T * first, T* last);
        vector(T * addr, int count);
        vector(int count, T const & e);
        vector(vector<T> & src);
        T& operator[] (Rank r) const;
        ~vector() { delete [] data; };
    };
    
    template <typename T>
    vector<T>::vector(T * first, T* last)
    {
        data = new T[DEFAULT_CAPACITY];
        unsigned int cnt = 0;
        while((first + cnt) < last){
            data[cnt] = *(first+cnt);
            cnt++;
        }        
    }
    template <typename T>
    T & vector<T>::operator[](Rank r) const
    {
        return data[r];
    }

}

#endif