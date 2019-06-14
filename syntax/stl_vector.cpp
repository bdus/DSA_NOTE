/*
* Description： A simple demonstration of c++11 STL vector 
*
* 编译 : clang++ -std=c++11 stl_vector.cpp
* 
*/

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
std::ostream& operator<<(std::ostream& s, const std::vector<T>& v) {
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
    /*  ---  构造函数 ----  */

    // 直接构造 
    vector<int> demo {1,2,3,4,5}; // vector<int> demo = {1,2,3,4,5};    
    cout << demo << endl; // [1, 2, 3, 4, 5]

    // 从地址构造 （数组）
    int buf[] = {1,2,3,4,5,6};
    vector<int> demo1 (buf,buf+sizeof(buf)/sizeof(int));
    cout << demo1 << endl; // [1, 2, 3, 4, 5, 6]

    // 从地址构造 (逆序拷贝)
    vector<int> demo2 (demo.rbegin(),demo.rend()); // vector<int> demo2 (demo.begin(),demo.end());
    cout << demo2 << endl; // [5, 4, 3, 2, 1]

    // 重复多次
    vector<char> demo3 (5,'a');
    cout << demo3 << endl; // [a, a, a, a, a]
    
    // 拷贝构造
    vector<char> demo4 (demo3);
    cout << demo4 << endl; // [a, a, a, a, a]

    vector<vector<int>> tmp = {{1,2,3},{4,5,6},{7,8,9}};
    cout << tmp[2] << endl; // [7, 8, 9]

    cout << "\n\n\n" << endl;

    /* ----  assign() ： 给容器（从新）赋值  --- */

    // 从数组
    demo.assign(buf,buf+sizeof(buf)/sizeof(int));
    cout << demo << endl; // [1, 2, 3, 4, 5, 6]

    demo.assign(5,buf[0]);
    cout << demo << endl; // [1, 1, 1, 1, 1]

    demo.assign({1,2,3});
    cout << demo << endl; // [1, 2, 3]

    cout << "\n\n\n" << endl;

    /* --- vector 实现栈 ---  */

    //访问第一个元素
    int num = demo.front();

    demo.push_back(num);
    cout << demo << endl; // [1, 2, 3, 1]

    demo.pop_back();
    cout << demo << endl; // [1, 2, 3]

    demo.insert(demo.end(),num);
    demo.insert(demo.begin()+demo.size(),num+1);
    cout << demo << endl; // [1, 2, 3, 1, 2] 

    demo.erase(demo.end()-1);
    cout << demo << endl; // [1, 2, 3, 1]

    demo.erase(demo.begin()+1,demo.end());
    cout << demo << endl; // [1]

    cout << "NY"[( demo.front() == demo.back() )] << endl; // Y

    return 0;
}