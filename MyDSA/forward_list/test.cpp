#include <iostream>
#include "forward_list.h"

using namespace std;

int main()
{
    int tmp[] = {1,2,3,4,5};
    MyDSA::forward_list<int> wtf(tmp,tmp+5);
    cout << wtf.size() <<endl;
    wtf.push_front(1);   
    wtf.push_front(1);
    cout << wtf.front() <<endl;
    cout << wtf.size() <<endl;
    wtf.~forward_list();

    return 0;
}
