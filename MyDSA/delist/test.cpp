#include <iostream>
#include "delist.h"
#include "../share/print.h"

using namespace std;

int main()
{
    int tmp[] = {1,2,3,4,5,6};
    MyDSA::delist<int> src(3,6);
    MyDSA::delist<int> wtf(tmp,tmp+6);
    MyDSA::print(wtf);
    wtf.clear();    
    //wtf.assign(3,6);
    wtf.assign(src);
    cout << "The size of delist is : " << wtf.size() <<endl;    
    wtf.push_back(7);
    wtf.push_front(5);
    cout << "The size of delist is : " << wtf.size() <<endl;
    
    MyDSA::print(wtf);
    wtf.assign(tmp,tmp+6);
    MyDSA::print(wtf);

    //TODO1: 几种类型的assign可以重载一个连续插入的insert  重新写
    //TODO2: 隐隐约约觉得代码哪里好像有内存泄漏 什么方法可以检查一下呢
    
    return 0;
}