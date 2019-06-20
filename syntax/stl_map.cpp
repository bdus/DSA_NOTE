/*
* Description： A simple demonstration of c++11 STL map 
*
* 编译 : clang++ -std=c++11 stl_map.cpp
* 
* map 是一个字典
*/
#include <iostream>
#include <map>
#include <string>

using namespace std;

template<typename Map>
void print_map(Map& m)
{
   std::cout << '{';
   for(auto& p: m)
        std::cout << p.first << ':' << p.second << ' ';
   std::cout << "}\n";
}

int main()
{
    /*  --- 初始化 --- */
    
    map<std::string,int> dict = { {"haha",233},{"aa",11}};
    
    dict.insert(std::pair<std::string, int>("abandon", 1) );
    dict["something"] = 69;
    dict["anything"] = 199;
    dict["that thing"] = 50;

    cout << "dict = "; print_map(dict);


    /*  --- 访问 ---  */
    
    map<std::string,int>::iterator iter;
    iter = dict.find("haha");
    if(iter != dict.end())
        cout << "find [" << iter->first << "] : " << iter->second << endl;
    
    cout << "test [aa] : " << dict["aa"] << endl;
    return 0;
}