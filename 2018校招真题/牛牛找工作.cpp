/*#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N = 0, M = 0;
    
    cin >> N >> M;

    vector<int> b(M); //小伙伴的数量M
    vector<pair<int,int>> table(N);    //工作的数量N

    for(auto & i : table)  cin >> i.first >> i.second;    
    sort(table.begin(), table.end());

    //auto fun = [](pair<int,int> & i) {cout << i.first << ' ' << i.second << endl;};
    //for_each(table.begin(),table.end(), fun);
    //for_each(Able.begin(),Able.end(), [](int & i){cout << i << ' ';});
    b[0] = table[0].second;
    for(int i = 1; i < N; i++)
    {
        b[i] = max(table[i].second, b[i-1]);
    }
    for_each(b.begin(),b.end(), [](int & i){cout << i << ' ';});

    for(int i = 0; i < M; i++)
    {
        int tmp = 0;
        cin >> tmp;
        int shift = upper_bound(table.begin(), table.end(), pair<int,int> (tmp,1000000005)) - table.begin();
        //cout << shift <<endl;
        cout << b[shift-1] << endl;
    }
    
    return 0;
}