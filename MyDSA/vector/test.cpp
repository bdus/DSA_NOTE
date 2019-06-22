#include <iostream>
#include "vector.h"

using namespace std;

int main()
{
    int buf[2] = {1,2};
    cout << buf[0]  << endl;

    MyDSA::vector<int> v (buf,buf+2);
    cout << v[0]  << endl;

    return 0;
}