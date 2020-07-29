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
struct F{
  int ok=0,r=0,l=0;
};
int n,m,x,y;F t[4*N];string s;
//building the tree
void build(int v=1, int tl=1, int tr=n) {
    if (tl == tr) {
        t[v].l=t[v].r=t[v].ok=0;
        if(s[tl]=='(')t[v].r++;
        if(s[tl]==')')t[v].l++;
        return;
    }
    int tm = (tl + tr) / 2;
    build( v*2, tl, tm);
    build(v*2+1, tm+1, tr);
    t[v].ok = t[v*2].ok + t[v*2+1].ok+2*min(t[v*2+1].l,t[v*2].r);
    t[v].l=t[v*2].l+t[v*2+1].l-min(t[v*2+1].l,t[v*2].r);
    t[v].r=t[v*2].r+t[v*2+1].r-min(t[v*2+1].l,t[v*2].r);
}
//queries
F sum(int l, int r,int v=1, int tl=1, int tr=n ) {
    F z;z.l=z.r=z.ok=0;
    if (l > r) 
        return z;
    if (l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    F final,left=sum( l, min(r, tm),v*2, tl, tm),right=sum(max(l, tm+1), r,v*2+1, tm+1, tr );
    final.ok=left.ok+right.ok+2*min(left.r,right.l);
    final.l=left.l+right.l-min(left.r,right.l);
    final.r=right.r+left.r-min(left.r,right.l);
    return final;
}
// //
// void update(int pos, int new_val,int v=1, int tl=0, int tr=n-1 ) {
//     if (tl == tr) {
//         t[v] = new_val;
//     } else {
//         int tm = (tl + tr) / 2;
//         if (pos <= tm)
//             update(pos,new_val,v*2, tl, tm);
//         else
//             update(pos,new_val,v*2+1, tm+1, tr);
//         t[v] = t[v*2] + t[v*2+1];
    // }
// }
void solve(){
  cin>>s>>m;n=s.length();s='#'+s;build();
  rep(i,1,m){
    cin>>x>>y;
    cout<<sum(x,y).ok<<"\n";
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