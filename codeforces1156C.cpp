#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <numeric>
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
#define double long double
#define int long long int
#define ll int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=1e6+10;
const int inf = /*0x3f3f3f3f*/1e9;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n,m,a,A[N],j=1,ans;multiset<int>s;
void solve(){
  cin>>n>>m;
  // if(n<1e5)
  // {for(int i=1;i<=n;i++)cin>>a,s.insert(a);
  //   for(auto i:s){
  //     if(s.lower_bound(i+m)!=s.end())
  //       ans++,s.erase(s.lower_bound(i+m));
  //   }}
  // else{
    for(int i=1;i<=n;i++)cin>>A[i];
    sort(A+1,A+1+n);
    for(int i=2;i<=n;i++)
      if(A[i]-A[j]>=m)j++,ans++;
  // }
  cout<<min(ans,n/2);
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