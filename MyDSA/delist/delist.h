#include "../share/shareHead.h"
#pragma once
namespace MyDSA
{
    template<typename T>
    struct DEListNode {
        T val;
        struct DEListNode * prev; 
        struct DEListNode * succ;
        DEListNode(T e) : val(e), prev(NULL), succ(NULL) {}        
    };

    template<typename T>
    class delist
    {
    protected:
        Rank _size;
        DEListNode<T> * header;
        DEListNode<T> * tail;        
        void init();

    public:
        delist();
        delist(Rank count, T const & e);
        delist(T * lo, T * hi);
        delist(delist & src);
        ~delist();
        void assign(Rank count, T const & e);
        void assign(T * lo, T * hi);
        void assign(delist & src);

        T &  front() { return header->val; };
        T &  back() { return tail->val; };
        int const & size() const { return _size; } ;
        void push_front(T const & e);
        void push_back(T const & e);
        void pop_front();
        void pop_back();
       
       void erase(DEListNode<T> * pos);
        void erase(DEListNode<T> * lo, DEListNode<T> * hi);
        void clear();

        template <typename VST> //操作器
        void traverse ( VST& ); //遍历，依次实施visit操作（函数对象，可全局性修改）
    };
}

#include "delist_im.h"
