#include <iostream>
#include "forward_list.h"
#include "../share/print.h"

using namespace std;

int main()
{
    int tmp[] = {1,2,3,4,5};
    MyDSA::forward_list<int> wtf(tmp,tmp+5);
    cout << "The size of forward list is : " << wtf.size() <<endl;
    wtf.push_front(1);   
    wtf.push_front(8);
    cout << "Adding 2 number in the front." <<endl;
    MyDSA::print(wtf);
    
    cout << wtf.front() <<endl;
    cout << wtf.size() <<endl;
    wtf.~forward_list();

    return 0;
}
