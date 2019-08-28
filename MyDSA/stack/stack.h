//#include "../share/shareHead.h"
#include "../vector/vector.h"

#ifndef _MyDSASTACK_H_
#define _MyDSASTACK_H_

namespace MyDSA
{
template <typename T>
class stack:public vector<T>
{
public:        

//stack(int count, T const & e):vector<T>(count,e) {}
using vector<T>::vector;      //参考注释1

void push( T const & e) { this->push_back(e); }
T top() {return this->back(); }
void pop() { this->pop_back(); }
};
}

#endif //_MyDSASTACK_H_

/*  注释1
    vector中未定义默认的无参构造函数 因此子类需要显示调用：
    “
            1. 如果子类没有定义构造方法，则调用父类的无参数的构造方法。
            2. 如果子类定义了构造方法，不论是无参数还是带参数，在创建子类的对象的时候,首先执行父类无参数的构造方法，然后执行自己的构造方法。
            3. 在创建子类对象时候，如果子类的构造函数没有显示调用父类的构造函数，则会调用父类的默认无参构造函数。
            4. 在创建子类对象时候，如果子类的构造函数没有显示调用父类的构造函数且父类自己提供了无参构造函数，则会调用父类自己的无参构造函数。
            5. 在创建子类对象时候，如果子类的构造函数没有显示调用父类的构造函数且父类只定义了自己的有参构造函数，则会出错（如果父类只有有参数的构造方法，则子类必须显示调用此带参构造方法）。
            6. 如果子类调用父类带参数的构造方法，需要用初始化父类成员对象的方式
        ”
    针对5 ： 
    
    https://www.cnblogs.com/yangykaifa/p/6737354.html
    派生写法：
    struct A
    {
       A(int i){}
    }；

    struct B:A
    {
      B(int i)：A(i),d(i){}
      int d;
    };
    
    构造函数比较多的时候
    struct A
    {
        A(int i) {}
        A(double d,int i){}
        A(float f,int i,const char* c){}
        //...等等系列的构造函数版本号
    }；
    struct B:A
    {
        B(int i):A(i){}
        B(double d,int i):A(d,i){}
        B(folat f,int i,const char* c):A(f,i,e){}
        //......等等好多个和基类构造函数相应的构造函数
    }；
    非常明显当基类构造函数一多，派生类构造函数的写法就显得非常累赘，相当不方便。           


    struct A
    {
      A(int i) {}
      A(double d,int i){}
      A(float f,int i,const char* c){}
      //...等等系列的构造函数版本号
    }；
    struct B:A
    {
      using A::A;
      //关于基类各构造函数的继承一句话搞定
      //......
    }；
*/