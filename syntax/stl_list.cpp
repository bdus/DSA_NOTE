/*
* Description： A simple demonstration of c++11 STL list 
*
* 编译 : clang++ -std=c++11 stl_vector.cpp
* 
* list 是一个双向链表
*/
#include <iostream>
#include <list>

#include <iterator>

using namespace std;

template<typename T>
std::ostream& operator<<(std::ostream& s, const std::list<T>& v) {
    s.put('[');
    char comma[3] = {'\0', ' ', '\0'};    
    for (const auto& e : v) {
        s << comma << e;
        comma[0] = ',';
    }
    return s << ']';
}

int main()
{
    /*  --- 初始化 --- */

    //直接构造
    list<int> demo {1,2,3};
    cout << demo << endl; // [1, 2, 3]

    //迭代器构造
    list<int> demo1 (demo.rbegin() ,demo.rend());
    cout << demo1 << endl; // [1, 2, 3]

    //重复
    list<int> demo2 (2,0);
    cout << demo2 << endl; // [0, 0]

    //拷贝构造
    list<int> demo3 (demo2);
    cout << demo3 << endl; // [0, 0]

    /*  --- 访问 ---  */

    demo.push_front(0);
    demo.push_back(4);
    cout << demo << endl; // [0, 1, 2, 3, 4]
    demo.pop_back();
    demo.pop_front();

    std::list<int>::iterator range_begin = demo.begin();
    std::list<int>::iterator range_end = demo.begin();
    std::advance(range_begin,1);
    std::advance(range_end,demo.size());
    demo.erase(range_begin, range_end);

    cout << "NY"[demo.front() == demo.back()] << endl; // Y
    cout << demo << endl; // [1]

    return 0;
}