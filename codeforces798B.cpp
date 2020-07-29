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
const int N=1e2+10;
const int inf = /*0x3f3f3f3f*/1e15;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
#define F first
#define S second
string s[N],temp[N];
bool c(int n){
  string S=temp[1];
  for(int i=2;i<=n;i++){if(temp[i]!=S)return 0;}
  return 1;
}
int a[N],n,l,ans=1e9;
void check(){
  string S=temp[1];
  int ok=a[1];
  for(int i=2;i<=n;i++){ok+=a[i];if(temp[i]!=S)return;}
  ans=min(ans,ok);
}
void f(int i){
  if(i==n+1){check();return;}
  temp[i]=s[i];
  a[i]=0;
  if(c(i-1)==0)return;
  int x=0;
  for(int j=1;j<=i;j++)
    x+=a[j];
  if(x>ans)return;
  f(i+1);//don't rotate this
  for(int j=1;j<=l;j++){
    rotate(temp[i].begin(),temp[i].begin()+1,temp[i].end());
    a[i]++;
    f(i+1);
  }
}
void solve(){
  cin>>n;
  for(int i=1;i<=n;i++)cin>>s[i];
  l=s[1].length();
  f(1);
  // for(int i=1;i<=n;i++)cout<<a[i]<<" ";
  if(ans==1e9)cout<<-1;else
  cout<<ans;
}
int32_t main()
{
  // ibs;cti;
  solve(),cout<<"\n";
  // int t;cin>>t;
  // int x=0;
  // while(t--){solve();cout<<"\n";}
  return 0;
}