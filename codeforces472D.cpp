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
#define int long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=2e3+10;
const int inf = /*0x3f3f3f3f*/1e15;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
#define F first
#define S second
int n,a[N][N];
void solve(){
  cin>>n;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
      cin>>a[i][j];
  for(int i=1;i<=n;i++){
    int neighbour=(i%n)+1;
    for(int j=1;j<=n;j++)
      if(i!=j and a[i][neighbour]>a[i][j])neighbour=j;
    for(int j=1;j<=n;j++)
      if(i!=j and a[i][neighbour]!=abs(a[i][j]-a[j][neighbour]))
        cout<<"NO",exit(0);
    //check for neighbour condiiton
    if(a[i][i]!=0)cout<<"NO",exit(0);
    for(int j=1;j<=n;j++)
      if(a[i][j]!=a[j][i] or (i!=j and a[i][j]==0))cout<<"NO",exit(0);
  }
  cout<<"YES";
}
int32_t main()
{
  ibs;cti;
  solve()/*,cout<<"\n"*/;
  int x=0;
  // int t;cin>>t;while(t--){/*x++;cout<<"Case #"<<x<<": ";*/solve();cout<<"\n";}
  return 0;
}