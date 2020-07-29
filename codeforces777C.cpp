#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstring>
#include <cstdio>
// #include <numeric>
#include <vector>
// #include <iterator> 
// #include <map>
#include <set>
// #include <climits>
// #include <queue>
// #include <iomanip>
// #include <cmath>
// #include <stack>
#include <cctype>
// #include <bits/stdc++.h>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=1e5+10;
const int inf = 0x3f3f3f3f;
const ll M = 998244353 ; // Mulo
// const ll M = 1e9+7 ; // Mulo
#define F first
#define S second
int n,m,asc[N],l[N];
//asc[j] is a dynamic array having the last i since which its been sorted
//l[r] for any row r is the l for which ans(l,r)is true
void solve(){
  cin>>n>>m;int a[n+1][m+1];memset(a,0,sizeof(a));
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      cin>>a[i][j];
  memset(l,inf,sizeof(l));
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
      if(a[i][j]<a[i-1][j])asc[j]=i;
      l[i]=min(asc[j],l[i]);//we find minimum asc across all j for given i
    }
  int k,L,r;cin>>k;
  while(k--){
    cin>>L>>r;
    if(l[r]<=L)cout<<"Yes";
    else cout<<"No";
    cout<<"\n";
  }
}
int main()
{
  ibs;cti;
  solve(),cout<<"\n";
  // int t;cin>>t;
  // while(t--){solve();cout<<"\n";}
  return 0;
}