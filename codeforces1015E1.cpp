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
// #include <bits/stdc++.h>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=1e2+10;
const int inf = 0x3f3f3f3f;
// const ll M = 998244353 ; // Mulo
const ll M = 1e9+7 ; // Mulo
#define F first
#define S second
string a[N];int num[N][N];bool cov[N][N];
void solve(){
  int n,m;cin>>n>>m;
  for (int i = 0; i < m+2; ++i)
  {
    a[0]+='#',a[n+1]+='#';
  }
  for (int i = 1; i <= n; ++i)
  {
    cin>>a[i];
    a[i]='#'+a[i]+'#';
  }
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      if(a[i][j]=='*')for(int s=1;;s++){
        int x=i-s,X=i+s,Y=j+s,y=j-s;
        if(x<1 or X>n or y<1 or Y>m)break;
        if(a[x][j]!='*')break;
        if(a[X][j]!='*')break;
        if(a[i][y]!='*')break;
        if(a[i][Y]!='*')break;
        cov[i][j]=cov[x][j]=cov[X][j]=cov[i][y]=cov[i][Y]=1;
        num[i][j]=s;
      }
  int cnt=0;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
      if(!cov[i][j] and a[i][j]=='*'){cout<<"-1\n";return;}
      if(num[i][j]!=0)cnt++;
    }
  cout<<cnt<<"\n";
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      if(num[i][j]!=0){
        cout<<i<<" "<<j<<" "<<num[i][j]<<"\n";
      }
}
int main()
{
  ibs;cti;
  solve()/*,cout<<"\n"*/;
  // int t;cin>>t;
  // while(t--){solve();cout<<"\n";}
  return 0;
}