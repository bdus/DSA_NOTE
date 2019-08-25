
namespace MyDSA
{
    // template<typename T>
    // void print(delist<T> const & src )
    // {
    //     ;
    // }
    #ifdef _MyDSAFORWARDLIST_H_
    template<typename T>
    void print(forward_list<T>  & src )//void print(forward_list<T>  const & src )
    {
        std::cout << "print forward_list (size : " << src.size() << "):" << std::endl;
        ForwardListNode<T> * itor = NULL;
        itor = src.begin();
        while (itor != src.end() )
        {
            std::cout <<  itor->val << ' ';
            itor = itor->next;
        }
        std::cout << std::endl;
    }
    #endif //_MyDSAFORWARDLIST_H_

    #ifdef _MyDSADELIST_H_
    template<typename T>
    void print(delist<T>  & src )
    {
        std::cout << "print delist (size : " << src.size() << "):" << std::endl;
        DEListNode<T> * itor = NULL;
        itor = src.begin();
        while (itor != src.end() )
        {
            std::cout <<  itor->val << ' ';
            itor = itor->succ;
        }
        std::cout << std::endl;
    }
    #endif //_MyDSADELIST_H_
}
