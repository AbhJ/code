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
const int N=5e3+10;
const int inf = /*0x3f3f3f3f*/1e15;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
#define F first
#define S second
int dp[N][N],open[N],close[N],quest[N],o,c,q,l,h,n,ans;string s;
void solve(){
  cin>>s;n=s.length();s='#'+s;
  for(int i=1;i<=n;i++){
    open[i]=open[i-1];
    close[i]=close[i-1];
    quest[i]=quest[i-1];
    if(s[i]=='(')open[i]++;
    if(s[i]==')')close[i]++;
    if(s[i]=='?')quest[i]++;
  }
  // for(int i=1;i<=n;i++){
  //   for(int l=2;l<=n;l+=2){
  //     int j=i+l-1;
  //     if(j>n)break;
  //     o=open[j]-open[i-1];
  //     c=close[j]-close[i-1];
  //     q=quest[j]-quest[i-1];
  //     if(o+q>=c and q+c>=o)cout<<i<<" "<<j<<" ",ans++;
  //   }
  // }
  for(int i=1;i<=n;i++){
    l=h=0LL;
    for(int j=i;j<=n;j++){
      if(s[j]=='(')l++,h++;
      if(s[j]==')')l--,h--;
      if(s[j]=='?')l--,h++;
      l=max(0LL,l);
      if(h<0LL)//too much of closure
        break;
      if((j-i)&1)if(l==0LL)ans++;
    }
  }
  // for(int i=1;i<=n;i++){
  //   for(int j=1;j<=n;j++)
  //     cout<<dp[i][j];
  //   cout<<"\n";
  // }
  //  for(int i=1;i<=n;i++){
  //   for(int j=i+1;j<=n;j+=2)
  //     ans+=dp[i][j];
  //     // cout<<dp[i][j];
  //   // cout<<"\n";
  // }
  cout<<ans;
}
int32_t main()
{
  ibs;cti;
  solve(),cout<<"\n";
  // int t;cin>>t;
  // int x=0;
  // while(t--){solve();cout<<"\n";}
  return 0;
}