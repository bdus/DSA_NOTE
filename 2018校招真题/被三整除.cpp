#include<stdlib.h>
#include<string>
#include<vector>

using namespace std;

unsigned int base10bits(unsigned int n)
{
//    if(n == 0) return 1;
    int ans = 0;
    while(n > 0)
    {
        n /= 10;        
        ans++;
    }
    return ans;
}

unsigned int times10(unsigned int  n, int r)
{
    while(r--)
    {
        n = (n << 3) + (n << 1);
    }
    return n;
}

int main()
{
    int l = 0, r = 0;
    //printf("%u \n",times10(5,5) );
    //printf("%u \n",base10bits(12) );
    
    if(2 != scanf("%d %d",&l,&r) ) return -1; 
    if( !(l > 0 && r > l) )
        return -1;

    vector<unsigned int> Ts(r+1,0);
    
    unsigned int S = 0;

    for(int i = 1; i <= r; i++)
    {
        S = times10(S,base10bits(i)) + i;
        Ts[i] = Ts[i-1] + (S % 3 == 0); 
        //printf("S = %u , %u \n",S,Ts[i]);
    }
    printf("%u \n",Ts[r] -  Ts[l-1]);
    
    return 0;
}
