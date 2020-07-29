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
const int N=2e5+10;
const int inf = /*0x3f3f3f3f*/ 1e18+12;
// const int M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
#define F first
#define S second
multiset<int>s[4];int n,a[N][4];
void solve(){
  cin>>n;
  for (int i = 0; i < n; ++i)
  {
    for(int j=0;j<4;j++)
      cin>>a[i][j],s[j].insert(a[i][j]);
  }
  for (int i = 0; i < n; ++i)
  {
    for(int j=0;j<4;j++)
      s[j].erase(a[i][j]);
    if(*s[0].rbegin()<=*s[2].begin() and *s[1].rbegin()<=*s[3].begin()){
      cout<<*s[0].rbegin()<<" "<<*s[1].rbegin();return;
    }
    for(int j=0;j<4;j++)
      s[j].insert(a[i][j]);
  }
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