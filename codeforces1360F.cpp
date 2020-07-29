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
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=2e5+10;
const int inf = /*0x3f3f3f3f*/1e9;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
string s[N],S;int n,m;
bool ch(int j){
  for(int i=1;i<=n;i++){
    int dif=0;
    for(int pos=1;pos<=j;pos++)
      if(s[i][pos]!=S[pos])dif++;
    if(dif>1)return 0;
  }
  return 1;
}
bool F=0;
void f(int j=1){
  if(F==1)return;
  if(j==m+1){cout<<S.substr(1);F=1;return;}
  for(char c='a';c<='z';c++){
    S[j]=c;if(ch(j)==1)f(j+1);
  }
}
void solve(){
  cin>>n>>m;F=0;
  for(int i=1;i<=n;i++){cin>>s[i];s[i]='#'+s[i];}
  S="";
  for(int i=1;i<=m+1;i++)S+="a";
  f();
  if(F==0)cout<<"-1";
}
int32_t main()
{
  ibs;cti;
  // solve()
  /*,cout<<"\n"*/;
  // cout<<"\n";
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();cout<<"\n";}
  return 0;
}