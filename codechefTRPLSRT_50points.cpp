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
set<int>s;int n,m,a[N],x[N],y[N],z[N],c;
void work(int A,int B,int C){
  x[c]=A,y[c]=B,z[c]=C;c++;
  int temp=a[A];
  a[A]=a[C];a[C]=a[B];a[B]=temp;
}
void solve(){
  cin>>n>>m;
  c=0;
  s.clear();
  memset(x,0,sizeof(x)),memset(a,0,sizeof(a)),memset(y,0,sizeof(y)),
  memset(z,0,sizeof(z));
  for (int i = 1; i <= n; ++i){cin>>a[i];if(a[i]!=i)s.insert(i);}
  while(s.size()!=2 and s.size()!=0){
    int X=*s.begin();
    int Y=a[X];
    s.erase(Y);
    int Z=a[Y];
    if(Z==X){
      bool gadha=0;
      for(auto q:s)
        if(q!=Z){
          gadha=1;
          Z=q;break;
        }
      if(gadha==0)break;
    }
    else s.erase(Z);
    if(a[Z]==X)s.erase(X);
    work(X,Y,Z);
    // if(s.size()<=1){
    //   break;
    // }
  }
  if(is_sorted(a+1,a+1+n)==0 or c>m){cout<<-1<<"\n";return;}
  cout<<c<<"\n";
  for (int i = 1; i <= c; ++i)
  {
    cout<<x[i-1]<<" "<<y[i-1]<<" "<<z[i-1]<<"\n";
  }
}
int32_t main()
{
    ibs;cti;
    int t;cin>>t;
    while(t--){
      solve();
      // cout<<"\n";
    }
    return 0;
}