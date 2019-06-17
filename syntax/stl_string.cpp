/*
* Description： A simple demonstration of c++11 STL string 
*
* 编译 : clang++ -std=c++11 stl_string.cpp
* 
*/

#include <iostream>
#include <string>

#include <iterator>

using namespace std;

int main()
{
    /*  --- 初始化 --- */    

    // 直接构造
    string s1 = "ab\0\0cd";
    string s2 = {"ab\0\0cd", 6};

    cout << s1 << endl;
    cout << s2 << endl;

    // 重复
    string s3 (4,'+');
    cout << s3 << endl;

    
    // 拷贝构造
    char c_str[] = "C-style string";
    string s4 (begin(c_str),end(c_str));
    cout << s4 << endl;

    /*  --- 访问 ---  */
    
    
    s4.pop_back();
    char tmp = s4.back();
    cout << tmp << endl;
    s4.pop_back();
    cout << s4 << endl;
    s4.push_back(tmp);    
    // s4.push_back('\0');
    s4.append(s3);
    cout << s4 << endl;

    return 0;
}