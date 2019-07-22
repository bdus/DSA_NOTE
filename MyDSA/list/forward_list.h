#pragma once
/*
    https://zh.cppreference.com/w/cpp/container/forward_list 
*/
#ifndef _MyDSAFORWARDLIST_H_
#define _MyDSAFORWARDLIST_H_
namespace MyDSA
{
    #ifndef _Rank
    #define _Rank
    typedef int Rank;
    #endif
    template <typename T>
    struct ForwardListNode {
          T val;
          struct ForwardListNode *next;
          ForwardListNode(T x) :
                val(x), next(NULL) {
          }
    };

    template <typename T>
    class forward_list
    {
        protected:
            ForwardListNode<T> * head;
            int _size;
            void init() {   head = NULL;    _size = 0; };

        public:
            forward_list();
            forward_list(Rank count, const T & value );
            forward_list(const T * lo, const T *hi);
            forward_list(forward_list<T> & src);

            void assign(Rank count, const T & value );
            void assign(const T * lo, const T *hi);
            void assign(forward_list<T> & src);

            int const & size() const {return _size;};            

            void push_front(T e);
            T  & front() const; 
            void pop_front();
            void clear();
            ~forward_list();
    };
}
#include "forward_list_im.h"

#endif //#ifndef _MyDSAFORWARDLIST_H_