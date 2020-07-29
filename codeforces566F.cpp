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
const int N=2e6+10;
const int inf = /*0x3f3f3f3f*/1e15;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
#define F first
#define S second
int n,x,a[N],c[N],b[N];
void solve(){
  cin>>n;
  for(int i=1;i<=n;i++){cin>>a[i];}
  int ma=-1;
  sort(a+1,a+1+n);
  for(int i=1;i<=n;i++){
    b[a[i]]++;
    for(int j=a[i];j<=a[n];j+=a[i]){
      //all bigger number can atleast take b[a[i]]elements
      b[j]=max(b[j],b[a[i]]);
    }
  }
  ma=*max_element(b,b+N);
  cout<<ma;
}
int32_t main()
{
  ibs;cti;
  solve(),cout<<"\n";
  int x=0;
  // int t;cin>>t;while(t--){/*x++;cout<<"Case #"<<x<<": ";*/solve();cout<<"\n";}
  return 0;
}