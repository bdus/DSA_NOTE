/*
* Description： A simple demonstration of c++11 STL list 
*
* 编译 : clang++ -std=c++11 stl_vector.cpp
* 
* list 是一个双向链表
*/
#include <iostream>
#include <set>

using namespace std;

int main()
{
    /*  --- 初始化 --- */
    
    set<int> seen;
    
    seen.insert({1,2,2,3,3,3,4,4,4,4});
    seen.insert(1);


    /*  --- 访问 ---  */

    cout << seen.size() << endl;
    cout << seen.count(4) << endl;    // set 的 count值 {0,1}    
    seen.erase(4);
    cout << seen.count(4) << endl;

    //find 
    //https://zh.cppreference.com/w/cpp/container/set/find
    
    return 0;
}