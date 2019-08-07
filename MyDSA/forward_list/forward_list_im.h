namespace MyDSA
{
    template<typename T>
    forward_list<T>::forward_list()
    {
        init();
    }

    template<typename T>
    forward_list<T>::forward_list(Rank count, const T & value )
    {
        init();
        assign(count,value);
    }
    template<typename T>
    forward_list<T>::forward_list(const T * lo, const T *hi)
    {
        init();
        assign(lo,hi);
    }
    template<typename T>
    forward_list<T>::forward_list(forward_list<T> & src)
    {
        init();
        assign(src);
    }
    template<typename T>
    void forward_list<T>::assign(Rank count, const T & value )
    {
        while (count)
        {
            count--;
            push_front(value);
        }        
    }
    template<typename T>
    void forward_list<T>::assign(const T * lo, const T *hi)
    {
        while (lo < hi)
        {
            push_front(*lo);
            lo++;
        }        
    }
    template<typename T>
    void forward_list<T>::assign(forward_list<T> & src)
    {
        while (src.size() > 0)
        {
            push_front(src.front());
            src.pop_front();
        }        
    }
    template<typename T>
    void forward_list<T>::push_front(T e)
    {
        ForwardListNode<T> * backup  = head;
        head = new ForwardListNode<T> (e);
        head->next = backup; 
        _size++;
    }

    template<typename T>
    T  & forward_list<T>::front() const
    {
        return head->val;
    }

    template<typename T>
    void forward_list<T>::pop_front()
    {
        if(_size > 0)
        {
            ForwardListNode<T> * tmp = head;
            head = head->next;            
            delete tmp;
            _size--;
        }        
    }
    template<typename T>
    void forward_list<T>::clear()
    {
        while (_size > 0)
        {            
            pop_front();
        }        
    }
    template<typename T>
    forward_list<T>::~forward_list()    
    {
        clear();
        init();     
    }
} 
    