# lower_bound & upper_bound

```cpp
//下列两个函数适用于 cpp 11 以上的标准库

#include < algorithm>

//返回指向范围 [first, last) 中首个不小于（即大于或等于） value 的元素的迭代器，或若找不到这种元素则返回 last 。
template< class ForwardIt, class T >
ForwardIt lower_bound( ForwardIt first, ForwardIt last, const T& value );


//返回指向范围 [first, last) 中首个大于 value 的元素的迭代器，或若找不到这种元素则返回 last 。
template< class ForwardIt, class T >
ForwardIt upper_bound( ForwardIt first, ForwardIt last, const T& value );
```

```cpp

#include<iostream>
#include <algorithm>

using namespace std;

int * my_lower_bound(int * first, int * last, const int & val)
{    
    while (first < last)
    {
        int * mid = first + ((last - first)>>1);
        if( (*mid) >= val )
        {
            last = mid;
        }
        else
        {
            first = mid+1;
        }       
    }
     return first;
}
int * my_upper_bound(int * first, int * last, const int & val)
{    
    while (first < last)
    {
        int * mid = first + ((last - first)>>1);
        if( (*mid) > val )
        {
            last = mid;
        }
        else
        {
            first = mid+1;
        }       
    }
     return first;
}
int main()
{
    int num[] = {1,2,4,66,55,76,8,79,9,5,7,7,7,6,6,6};
    int shift = sizeof(num)/sizeof(int);
    auto print = [](const int & n) {cout << ' ' << n;};
    
    cout << "search in list : " << endl;
    sort(num,num+shift);
    for_each(num,num+ shift,print);
    cout << endl;
    
    auto loca = lower_bound(num,num+shift,6);
    cout << "#num @" << loca - num << " == " <<
    *loca << endl;

    loca = upper_bound(num,num+shift,6);
    cout << "#num @" << loca - num << " == " << 
    *loca << endl; 
   
    int * loca1 = my_lower_bound(num,num+shift,6);
    cout << "#num @" << loca1 - num << " == " << 
    *loca1 << endl; 
    loca1 = my_upper_bound(num,num+shift,6);
    cout << "#num @" << loca1 - num << " == " << 
    *loca1 << endl; 
    /*
     1 2 4 5 6 6 6 7 7 7 8 9 55 66 76 79
    #num @4 == 6
    #num @7 == 7
    #num @4 == 6
    #num @7 == 7
    */

    return 0;
}

```