#pragma once

namespace MyDSA
{
    template <typename T>
    inline void swap(T & a, T & b)
    {
        T tmp = a;
        a = b;
        b = tmp;
    }

    //template < class RandomIt > stl中用Iterator隔断算法和容器    
    void bubbleSort(int * first, int * last)
    {        
        for(int * i = first; i < last-1; i++)
        {
            for(int * j = first + 1; j < last; j++)
            {
                if(*j < *(j-1))
                {                    
                    swap(*j,*(j-1));
                }                
            }
        }
    }

    void selectSort(int * first, int * last)
    {
        for(int * i = first; i < last; i++)
        {
            int *min = i;            
            for(int * j = i+1; j < last; j++)
            {
                if(*j < *min)
                    min = j;                                        
            }
            swap(*i,*min);
        }
    }
    void merge(int * first, int * mid, int * last)
    {
        if(first == NULL || mid == NULL || last == NULL)
            return;
        unsigned int len = last - first;
        int * buf = new int[len];
        unsigned int cnt = 0;
        int * l = first;
        int * r = mid;
        while(l < mid && r < last){            
            if(*l < *r) {
                buf[cnt++] = *l;
                l++;
            }
            else {
                buf[cnt++] = *r;
                r++;
            }            
        }
        while(l < mid){
            buf[cnt++] = *l;
            l++;
        }
        while(r < last){
            buf[cnt++] = *r;
            r++;
        }        
        for(unsigned int i = 0; i < cnt; i++)
        {
            first[i] = buf[i];
        }        
        delete [] buf;
    }
    void mergeSort(int * first, int * last)
    {
        unsigned int len = last - first;
        if(len < 2) return;
        int * mid = first + (len >> 1 );
        mergeSort(first,mid);   mergeSort(mid,last);
        merge(first,mid,last);
    }
}