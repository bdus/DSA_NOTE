namespace MyDSA
{
    template<typename T>
    void init()
    {
        header =  new DEListNode<T>; 
        tail =  new DEListNode<T>;
        header->succ = tail;
        tail->prev = header;
    }

    template<typename T>
    delist<T>::delist() : _size(0),  header(NULL),  tail (NULL)
    {
        init();
    }
    template<typename T>
    delist<T>::delist(Rank count, T const & e) : _size(0),  header(NULL),  tail (NULL)
    {
        init();
        assign(count,e);
    }    

    template<typename T>
    void delist<T>::assign(Rank count, T const & e)
    {
        init();
        std::cout << "assign ok" << std::endl;
        while (count)
        {
            push_front(e);
            count--;
        }        
    }

    template<typename T>
    void delist<T>::push_front(T const & e)
    {
        std::cout << "push_front" << std::endl;
        DEListNode<T> * tmp =  new DEListNode<T>(e);        
        
        
        _size++;
        std::cout << "push_front ok" << std::endl;
    }

    template<typename T>
    void delist<T>::push_back(T const & e)
    {
        DEListNode<T> * tmp = tail;
        tail = new DEListNode<T>(e);
        tail->prev = tmp;
        tmp->succ = tail;

        _size++;
    }

    template<typename T>
    void delist<T>::pop_front()
    {
        if(_size > 0)
        {
            DEListNode<T> * tmp = header;
            header = header->succ;
            delete tmp;
            _size--;
        }
    }

    template<typename T>
    void delist<T>::pop_back()
    {
        if(_size > 0)
        {
            std::cout << "pop_back " << std::endl;
            DEListNode<T> * tmp = tail;
            tail = tail->prev;  
            delete tmp;
            _size--;
            std::cout << "pop_back ok" << std::endl;
        }
    }

    template<typename T>
    void delist<T>::erase(DEListNode<T> * pos)
    {
        pos->prev->succ = pos->succ;
        pos->succ->prev = pos->prev;
        delete pos;
        _size--;
    }

    template<typename T>
    void delist<T>::erase(DEListNode<T> * lo, DEListNode<T> * hi)
    {
        DEListNode<T> * tmp = tail;
        while (lo < hi)
        {
            erase(lo++); 
        }        
    }

    template<typename T>
    delist<T>::~delist()
    {
        while (_size)
        {
            pop_back();
        }        
    }

    template<typename T> template<typename VST>
    void delist<T>::traverse(VST & visit)
    {
        for ( DEListNode<T> * p = header; p != tail; p = p->succ ) visit ( p->val); 
    }

}