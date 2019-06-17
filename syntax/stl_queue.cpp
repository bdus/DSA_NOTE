/*
* Description： A simple demonstration of c++11 STL queue 
*
* 编译 : clang++ -std=c++11 stl_queue.cpp
* 
* deque 是一个双向队列 
*   其内部单元地址不是连续的
*
*   常用访问函数
*       at
*       size
*       front
*       back
*       push_back
*       pop_back
*       push_front
*       pop_front
*
*
* queue 是标准的FIFO的队列
*   内部实现可能是deque或者list
* 
*   常用访问函数
*       front
*       back
*       push_back
*       pop_front
*/

#include <iostream>
#include <queue>
#include <deque>

using namespace std;

template<typename T>
std::ostream& operator<<(std::ostream& s, const std::deque<T>& v) {
    s.put('[');
    char comma[3] = {'\0', ' ', '\0'};    
    for (const auto& e : v) {
        s << comma << e;
        comma[0] = ',';
    }
    return s << ']';
}
template<typename T>
std::ostream& operator<<(std::ostream& s, const std::queue<T>& v) {
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

    // 直接构造
    deque<int> demo {1,2,3};
    cout << demo << endl; // [1, 2, 3]

    deque<int> demo1 (demo.rbegin() ,demo.rend());
    // 迭代器构造
    cout << demo1 << endl; // [1, 2, 3]

    // 重复
    deque<int> demo2 (2,0);
    cout << demo2 << endl; // [0, 0]

    // 拷贝构造
    deque<int> demo3 (demo2);
    cout << demo3 << endl; // [0, 0]

    /*  --- 访问 ---  */

    demo.push_front(0);
    demo.push_back(4);
    cout << demo << endl; // [0, 1, 2, 3, 4]
    demo.pop_back();
    demo.pop_front();

    // 删除从位置1到队尾的部分
    std::deque<int>::iterator range_begin = demo.begin();
    std::deque<int>::iterator range_end = demo.begin();
    std::advance(range_begin,1);
    std::advance(range_end,demo.size());
    demo.erase(range_begin, range_end);

    cout << "NY"[demo.front() == demo.back()] << endl; // Y
    cout << demo << endl; // [1]

    cout << "\n\n\n\n\n" << endl;

    /*  --- 初始化 --- */    

    // 直接构造
    deque<int> qdemo {1,2,3};
    cout << qdemo << endl; // [1, 2, 3]

    qdemo.push_back(0);
    qdemo.pop_front();
    cout << qdemo << endl; // [2, 3, 0]

    deque<int> pdemo (qdemo.rbegin(),qdemo.rend());
    cout << "NY"[qdemo.front() == pdemo.back()] << endl; // Y

    return 0;
}