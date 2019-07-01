#include <iostream>
#include "vector.h"
#include "sort.h"
#include <algorithm>    // std::find
#include "find.h"

using namespace std;

int main()
{
    int buf[] = {1,2,5,8,7,1,3,0,9,5};
    cout << buf[0]  << endl;

    // MyDSA::vector<int> v (buf,buf+2);
    MyDSA::vector<int> v (buf,sizeof(buf)/sizeof(int));
    // MyDSA::vector<int> v (3,6);
    // MyDSA::vector<int> src (buf,buf+2);
    // MyDSA::vector<int> v (src);    
    for(int i  =0; i < v.size(); i++)
        cout << v[i] << ' ';
    cout << endl;    
    // MyDSA::bubbleSort(&v[0],&v[0]+v.size());
    // MyDSA::selectSort(&v[0],&v[0]+v.size());
    MyDSA::mergeSort(&v[0],&v[0]+v.size());
    
    for(int i  =0; i < v.size(); i++)
        cout << v[i] << ' ';
    cout << endl;    

    //auto p = std::find (&v[0],&v[0]+v.size(), 3);
    auto p = MyDSA::binFind(&v[0],&v[0]+v.size(), 10);
    
    if(p != &v[0]+v.size())
        cout << *p << endl;

    // v.push_back(3);    
    // v.insert(0,0);    
    // for(int i  =0; i < v.size(); i++)
    //     cout << v[i] << ' ';
    // cout << endl;    
    // v.erase(0,1);
    // v.pop_back();

    // for(int i  =0; i < v.size(); i++)
    //     cout << v[i] << '-';
    // cout << endl;

    // cout << v.front() << endl;
    // cout << v.back() << endl;

    return 0;
}