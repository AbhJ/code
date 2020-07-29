//Coded by Abhijay Mitra
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <numeric>
#include <vector>
#include <iterator> 
#include <map>
#include <set>
#include <climits>
#include <queue>
#include <cmath>
#include <stack>
#include <cctype>
#include <bitset>
// #include <bits/stdc++.h>
#define double long double
#define int long long int
#define ll int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
#define koto_memory(a) cout<<(sizeof(a)/1048576.0)<<" MB";
#define res(v) v.resize(unique(v.begin(), v.end()) - v.begin());
#define cnt_res(v) std::distance(v.begin(),std::unique(v.begin(), v.end())); 
#define timer cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
using vi = std::vector<int>;
using vvi = std::vector<vi>;
using pii = std::pair<int,int>;
using vpii = std::vector<pii>;
using vvpii = std::vector<vpii>;
#define mp         make_pair
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define per(i,b,a) for (int i = b; i >= a; i--)
#define all(x)     x.begin(), x.end()
using namespace std;
const int N=2e6+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int t[110][110][110],z,y,x,i,j,k,T,X,Y,Z,cnt,v,n,q;
int sum(int x, int y, int z) {
        int ret = 0;
            for(i = x; i>0; i -= (i& -i))
              for(j = y; j>0; j -= (j & -j))
                for(k = z; k>0; k -= (k & -k))
                    ret += t[i][j][k];
        return ret;
}
void add(int x, int y, int z, int delta) {
    for(i = x; i<=n; i += (i & -i))
        for(j = y; j <= n; j += (j& -j))
            for(k = z; k <= n; k += (k& -k))
                t[i][j][k] += delta;
}
int f(int x, int y, int z, int X, int Y, int Z){
    return 
          sum(X,Y,Z) 
          - sum(x,Y,Z) - sum(X,y,Z) - sum(X,Y,z) 
          + sum(x,y,Z) + sum(x,Y,z) + sum(X,y,z)
          - sum(x,y,z)
    ;
}
void solve(){
  cin>>n>>q;n++;
  rep(i,1,q){
    cin>>T;
    if(T==1){
      cin>>x>>y>>z>>v;cnt+=v;
      add(x+1,y+1,z+1,v);
    }
    if(T==2){
      cin>>x>>y>>z>>X>>Y>>Z;  
      cout<<cnt-f(x,y,z,X+1,Y+1,Z+1)<<"\n";
    }
  }
}
int32_t main()
{
  ibs;cti;
  solve()
  /*,cout<<"\n"*/;
  // cout<<"\n";
  int xx=0;
  // int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();cout<<"\n";}
  return 0;
}