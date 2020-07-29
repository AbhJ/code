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
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=1e5+10;
const int inf = 0x3f3f3f3f;
// const ll M = 998244353 ; // Mulo
const ll M = 1e9+7 ; // Mulo
#define F first
#define S second
int n, t[4*N];
//building the tree
void build(int a[],int v=1, int tl=1, int tr=n) {
    if (tl == tr) {
        t[v]=a[tl];
    } else {
        int tm = (tl + tr) / 2;
        /*if(pos<=tm)*/build(a,v*2, tl, tm);
        /*else*/ build(a,v*2+1, tm+1, tr);
        //
        // for (int i = 0; i <26; ++i){
        //     t[v][i]=t[v*2+1][i]+t[v*2][i];
        // }
        t[v]=__gcd(t[2*v],t[2*v+1]);
        // cout<<"F";
    }
}
//queries
int sum(int l,int r, int v=1,int tl=1, int tr=n ) {
    if(l>r)return 0;
    if(l==tl and r==tr)return t[v];
    int tm = (tl + tr) / 2;
    // cout<<"F";
    return __gcd( sum( l, min(r,tm),v*2, tl,tm),sum(max(l,tm+1), r,v*2+1,tm+1, tr ));
}
//update
// void update(int pos, char c,char old,int v=1, int tl=1, int tr=n ) {
//     if(pos<tl or pos>tr)return;
//     if (tl == tr) {//node
//         t[pos][c-'a'] ++;
//         t[pos][old-'a']--;
//         return;
//     } else {
//         int tm = (tl + tr) / 2;
//         if (pos <= tm)
//             update(pos,c,old,v*2, tl, tm);
//         else
//             update(pos,c,old,v*2+1, tm+1, tr);
//         t[pos][c-'a'] ++;//lineage of node
//         t[pos][old-'a']--;
//         return;
//     }
// }
int m,p,v,l,r,a[N];pair<int,int>A[N];
void solve(){
  cin>>n;
  for (int i = 1; i <= n; ++i)cin>>a[i],A[i]={a[i],i};
  sort(A+1,A+1+n);
  cin>>m;
  build(a);
  while(m-- and cout<<"\n"){
    cin>>l>>r;
    // cout<<"F";
    int g=sum(l,r);
    // cout<<g;
    int c=upper_bound(A+1,A+n+1,make_pair(g,r))-lower_bound(A+1,A+1+n,make_pair(g,l));
    cout<<r-l-c+1;
  }
}
int main()
{
  // ibs;cti;
  solve(),cout<<"\n";
  // int t;cin>>t;
  // while(t--){solve();cout<<"\n";}
  return 0;
}