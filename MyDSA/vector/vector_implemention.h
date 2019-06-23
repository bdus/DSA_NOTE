namespace MyDSA
{
    template <typename T>
    void vector<T>::expand()
    {
        if(_size < _capacity) return;
        if(_capacity < DEFAULT_CAPACITY) _capacity = DEFAULT_CAPACITY;
        T * _oldElem = _data;
        _data = new T[_capacity <<= 1];
        for(int i = 0; i < _size; i++)
            _data[i] = _oldElem[i];
        delete [] _oldElem;
    }

    //   **** 构造函数 *****
    template <typename T>    
    void vector<T>::copyFrom(T * addr, Rank lo, Rank hi)
    {        
        _capacity = hi - lo + DEFAULT_CAPACITY;
        _data = new T[_capacity];
        _size = 0;
        while(lo < hi)
            _data[_size++] = addr[lo++];
    }    
    template <typename T>
    vector<T>::vector(T * first, T* last)
    {
        Rank cnt = last - first;
        copyFrom(first,0,cnt);
    }
    template <typename T>
    vector<T>::vector(T * addr, Rank count)
    {
        copyFrom(addr,0,count);
    }
    template <typename T>
    vector<T>::vector(Rank count, T const & e)
    {
        _size = count;
        _data = new T[_size];
        for(unsigned int i = 0; i < _size; i++)
        {
            _data[i] = e;
        }
    }
    template <typename T>
    vector<T>::vector(vector<T> & src)
    {
        copyFrom(&src[0],0,src.size());
    }
    //   **** 构造函数 end *****

    //   **** 动态操作 ****
    template <typename T>
    Rank vector<T>::insert(Rank r, T const & e)
    {
        expand();
        for(Rank i = _size; i > r; i--)
            _data[i] = _data[i-1];
        _data[r] = e; _size++;
        return r;
    }
    // template <typename T>
    // Rank vector<T>::insert(Rank r, T * first, T * last)
    // {
    //     expand();
    //     Rank cnt = last - first;
    //     for(Rank i )

    // }

    template <typename T>
    Rank vector<T>::erase(Rank lo, Rank hi)
    {
        //assert(0 < lo < hi && hi -lo < _size && hi < _size)
        // 0 lo hi _size
        // **xxx***
        while(hi < _size){
            _data[lo++] = _data[hi++];
        }
        _size = lo;
        return hi - lo;
    }   
}