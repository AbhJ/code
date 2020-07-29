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
const int N=1e5+10;
const int inf = /*0x3f3f3f3f*/ 1e18+12;
// const int M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
#define F first
#define S second
int d[N],n;
void solve(){
  cin>>n;
  int ans=0;
  while(n>0){
    auto x=lower_bound(d+1,d+N+1,n);
    while(*x>n)x--;
    if(x<=d)break;
    n-=*x;
    ans++;
  }
  cout<<ans;
}
int32_t main()
{
    ibs;cti;
    d[1]=2;
    for (int i = 2; i <N ; ++i)
    {
      d[i]=d[i-1]+i*3-1;
    }
    // cout<<d[N-1];
    int t;cin>>t;
    while(t--){
      solve();
      cout<<"\n";
    }
    return 0;
}