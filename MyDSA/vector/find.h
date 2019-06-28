#pragma once

namespace MyDSA
{
    int * binFind(int * first, int * last,int key)
    {
        int ans = -1;
        int * lo = first;
        int * hi = last;
        while (lo < hi)
        {
            int * mid = lo + ((hi-lo)>>1);            
            if( *mid > key )
                hi = mid;            
            else
                lo = mid+1;            
        }
        return --lo;
    }
}