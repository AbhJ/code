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
// #include <bits/stdc++.h>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
// const ll M = 998244353 ; // Mulo
const ll M = 1e9+7 ; // Mulo
#define F first
#define S second
void solve(){
    int x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6;
    cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4>>x5>>y5>>x6>>y6;
    if(x3<=x1 and y3<=y1 and x4>=x2 and y4>=y2){cout<<"NO\n";return;}
    if(x5<=x1 and y5<=y1 and x6>=x2 and y6>=y2){cout<<"NO\n";return;}
    if(x4>=x2 and y4>=y2 and x3<=x1 and x5<=x1 and y5<=y1 and x6>=x2 and y6>=y3){cout<<"NO\n";return;}
    if(x6>=x2 and y6>=y2 and x5<=x1 and x3<=x1 and y3<=y1 and x4>=x2 and y4>=y5){cout<<"NO\n";return;}
    if(x3<=x1 and y3<=y1 and y4>=y2 and x6>=x2 and y5<=y1 and y6>=y2 and x5<=x4){cout<<"NO\n";return;}
    if(x5<=x1 and y5<=y1 and y6>=y2 and x4>=x2 and y4>=y2 and y3<=y1 and x6>=x3){cout<<"NO\n";return;}
    cout<<"YES\n";
}
int main()
{
  ibs;cti;
  solve()/*,cout<<"\n"*/;
  // int t;cin>>t;
  // while(t--){solve();cout<<"\n";}
  return 0;
}