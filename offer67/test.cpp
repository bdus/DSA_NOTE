#include <iostream>
#include <map>
#include <iterator>
#include <algorithm>
#include <vector>

using namespace std;

// int FindGreatestSumOfSubArray(vector<int> array)
// {
//     if(array.size() < 1)
//         return 0; 
//     else
//     {
//         return max(array.front(), 
//             array.front() + FindGreatestSumOfSubArray(vector<int> (array.begin()+1,array.end()) )  );
//     }
        
// }

// int FindGreatestSumOfSubArray(vector<int> array)
// {   
//     int sum = array.back();
//     int ans = sum;
//     for(int i = array.size()-1; i >=0; i--)
//     {
//         sum = max( array[i], array[i] + sum );
//         ans = max(sum,ans);
//     }
//     return ans;
// }

int FindGreatestSumOfSubArray(vector<int> array)
{   
    int sum = array.front();
    int ans = sum;
    for(int i = 1; i < array.size(); i++)
    {
        sum = max( array[i], array[i] + sum );
        ans = max(sum,ans);
    }
    return ans;
}
int main()
{
    //map<int, int> dict;
    int arr[] = {6,-3,-2,7,-15,1,2,2};    
    unsigned int len = sizeof(arr)/sizeof(int);
    vector<int> buf(arr,arr+len);   
   
    cout << FindGreatestSumOfSubArray(buf) << endl;
    

    return 0;
}