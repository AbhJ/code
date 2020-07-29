#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <numeric>
#include <vector>
#include <iterator> 
#include <map>
#include <set>
#include <climits>
#include <queue>
#include <iomanip>
#include <cmath>
#include <stack>
#include <cctype>
#include <bitset>
// #include <bits/stdc++.h>
#define int long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=3e5+10;
const int inf = /*0x3f3f3f3f*/ 1e18+12;
// const int M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
#define F first
#define S second
int n;string s[N];int ans,worst[N],total[N];
set<int>ok;
void solve(){
    cin>>n;
    for (int i = 1;i<=n; ++i)
    {
        cin>>s[i];
    }
    memset(worst,inf,sizeof(worst));
    map<int,int>m;
    //stores all total values
    for (int i = 1;i<=n; ++i)
    {
        int o=0;
        for(auto j:s[i]){
            if(j=='(')o++;else o--;
            worst[i]=min(worst[i],o);
        }
        total[i]=o;
        if(worst[i]>=0)m[total[i]]++;
        //if worst i is negative it would lead to ())))) or ()))((
    }
    //if worst is total it can be used as second element like ()))))
    for (int i = 1;i<=n; ++i)if(worst[i]==total[i])ans+=m[-total[i]];
    cout<<ans;
}
int32_t main()
{
    ibs;cti;
    // int t;cin>>t;
    // while(t--){
      solve();
      cout<<"\n";
    // }
    return 0;
}