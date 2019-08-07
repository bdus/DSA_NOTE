/*

 */
//#include<iostream>
#include<string>
#include<map>
#include<stdio.h>

using namespace std;

int main()
{
    map<char,int> table;

    char C = 0;
    int N = 0;
    bool flag = false;
    bool flag_o = false; 
    while (2 == scanf("%c:%d",&C,&N))
    {
        if (flag == false)
            table[C] = N;
        else
        {
            table[C] -= N;
            if(N != 0)
                flag_o = true;
        }
            
        //printf("GET %c:%d\n",C,N);
        char cmd = getchar();
        if(cmd == ',')
        continue;
        else if(cmd == '@')
        {
            flag = true; 
        }        
        else if(cmd == '\0' || cmd == '\n')
        {
            //printf("BREAK GET %c\n",cmd);
            break;
        }
        else
        {
            ;
        }        
    }
    
    int idx = 0;
    for(auto i = table.begin(); i != table.end(); i++)
    {                
        idx++;
        if(idx != table.size()  )
        {
            printf("%c:%d,-",i->first,i->second);
        }
        else
        {
            if(flag_o == true)
                printf("%c:%d\n",i->first, i->second);
            else
                printf("%c:%d@\n",i->first, i->second);    
        }       
    }

    return 0;
}