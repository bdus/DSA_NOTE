#include <iostream>
#include "stack.h"
#include "../share/print.h"

using namespace std;

int main()
{    
    MyDSA::stack<int> wtf1(3,6);
    wtf1.push(1);
    print(wtf1);

    return 0;
}
