#include "../share/shareHead.h"

#ifndef _MyDSADELIST_H_
#define _MyDSADELIST_H_
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
        delist(delist<T> & src);
        ~delist();
        void assign(Rank count, T const & e);
        void assign(T * lo, T * hi);
        void assign(delist & src);

        T &  front() { return header->val; };
        T &  back() { return tail->val; };
        int const & size() const { return _size; } ;        
       
       void erase(DEListNode<T> * pos);
        void erase(DEListNode<T> * lo, DEListNode<T> * hi);
        void clear();
        void insert(DEListNode<T> * pos,T const & e);
        void push_front(T const & e) {insert(header,e); };
        void push_back(T const & e) {insert(tail->prev,e); };
        void pop_front() {erase(header->succ);};
        void pop_back() {erase(tail->prev);};

        DEListNode<T> * begin() {return header->succ;} ;
        DEListNode<T> *end() {return tail;};

        template <typename VST> //操作器
        void traverse ( VST& ); //遍历，依次实施visit操作（函数对象，可全局性修改）
    };
}

#include "delist_im.h"

#endif //_MyDSADELIST_H_