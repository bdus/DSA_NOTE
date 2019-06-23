#include <iostream>
#include "vector.h"

using namespace std;

int main()
{
    int buf[2] = {1,2};
    cout << buf[0]  << endl;

    MyDSA::vector<int> v (buf,buf+2);
    // MyDSA::vector<int> v (buf,sizeof(buf)/sizeof(int));
    // MyDSA::vector<int> v (3,6);
    // MyDSA::vector<int> src (buf,buf+2);
    // MyDSA::vector<int> v (src);    
    v.push_back(3);    
    v.insert(0,0);
    for(int i  =0; i < v.size(); i++)
        cout << v[i] << ' ';
    cout << endl;    
    v.erase(0,1);
    v.pop_back();
    for(int i  =0; i < v.size(); i++)
        cout << v[i] << '-';
    cout << endl;

    cout << v.front() << endl;
    cout << v.back() << endl;

    return 0;
}