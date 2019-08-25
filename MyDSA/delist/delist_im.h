namespace MyDSA
{
    template<typename T>
    void delist<T>::init()
    {
        header =  new DEListNode<T>(0); //加入头哨兵和尾哨兵
        tail =  new DEListNode<T>(0);
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
        clear();
        while (count)
        {
            //push_front(e);
            //push_back(e);
            insert(header,e);
            count--;
        }        
    }
     template<typename T>
     void delist<T>::insert(DEListNode<T> * pos, T const & e)
     {
         //insert e After pos

        assert(pos != NULL);
        DEListNode<T> * x  = new DEListNode<T>(e);
        x->prev = pos;
        x->succ = pos->succ;
        
        assert(pos->succ != NULL);
        pos->succ->prev = x;
        pos->succ = x;
        _size++;
     }

    // template<typename T>
    // void delist<T>::push_front(T const & e)
    // {        
    //     DEListNode<T> * tmp =  header->succ;
    //     header->succ = new DEListNode<T>(e);
    //     header->succ->succ = tmp;
    //     header->succ->prev = header;

    //     tmp->prev = header->succ;        

    //     _size++;
    //     std::cout << "push_front ok" << std::endl;
    // }

    // template<typename T>
    // void delist<T>::push_back(T const & e)
    // {
    //     DEListNode<T> * tmp = tail->prev;
    //     tail->prev = new DEListNode<T>(e);
    //     tail->prev->succ = tail;
    //     tail->prev->prev = tmp;

    //     tmp->succ = tail->prev;

    //     _size++;
    // }

    // template<typename T>
    // void delist<T>::pop_front()
    // {
    //     if(_size > 0)
    //     {
    //         DEListNode<T> * tmp = header->succ;
    //         tmp->succ->prev = header;
    //         header->succ = tmp->succ;           
            
    //         delete tmp;
    //         _size--;
    //     }        
    // }
    // template<typename T>
    // void delist<T>::pop_back()
    // {
    //     if(_size > 0)
    //     {            
    //         DEListNode<T> * tmp = tail->prev;            
    //         tmp->prev->succ = tail;
    //         tail->prev = tmp->prev;
    //         delete tmp;
    //         _size--;                        
    //     }        
    // }

    template<typename T>
    void delist<T>::erase(DEListNode<T> * pos)
    {
        if(_size > 0)
        {
            assert(pos!=header && pos!=tail);
            assert(pos->prev != NULL);            
            pos->prev->succ = pos->succ;
            assert(pos->succ != NULL);
            pos->succ->prev = pos->prev;
            delete pos;
            _size--;
        } 
    }

    template<typename T>
    void delist<T>::erase(DEListNode<T> * lo, DEListNode<T> * hi)
    {        
        while (lo != hi)
        {
            lo = lo->succ;
            erase(lo->prev);
        }        
    }

    template<typename T>
    void delist<T>::clear()
    {
        erase(begin(),end());
        // while (_size)
        // {
        //     //pop_back();
        //     //pop_front();
        //     //erase(header->succ);
        //     //erase(tail->prev);            
        // } 
    }

    template<typename T>
    delist<T>::~delist()
    {
        clear();
        delete header;
        delete tail;
    }

    template<typename T>
    void delist<T>::assign(T * lo, T * hi)
    {
        clear();
        while (lo < hi)
        {
            push_back(*lo);
            lo++;
        }
    }
    template<typename T> 
    delist<T>::delist(T * lo, T * hi)  : _size(0),  header(NULL),  tail (NULL)
    {
        init();
        assign(lo,hi);
    }
    template<typename T>
    void delist<T>::assign(delist<T> & src)
    {
        clear();
        DEListNode<T> * itor = src.begin();
        while (itor != src.end())
        {
            push_back(itor->val);
            itor = itor->succ;            
        }       
    }
    template<typename T> 
    delist<T>::delist(delist<T> & src)  : _size(0),  header(NULL),  tail (NULL)
    {
        init();
        assign(src);
    }

    template<typename T> template<typename VST>
    void delist<T>::traverse(VST & visit)
    {
        for ( DEListNode<T> * p = header; p != tail; p = p->succ ) visit ( p->val); 
    }

}