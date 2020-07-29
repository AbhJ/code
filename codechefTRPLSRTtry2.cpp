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
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
// const ll M = 998244353 ; // Mulo
const ll M = 1e9+7 ; // Mulo
#define F first
#define S second
int a[N],b[N],x[N],y[N],z[N];vector<int>s;
void solve(){
  int n,k;cin>>n>>k;
  for(int i=1;i<=n;i++){cin>>a[i];b[a[i]]=i;if(a[i]!=i)s.pb(i);}
  int c=0;
  for (int i=0;i<s.size()-2;i+=3)
  {
    // if(a[*i]==*i){s.erase(i),i--;}
    // if(s.count(a[*i]) and b[*i]==a[*i])x[c]=*i,y[c]=a[*i],z[c]=a[a[*i]],s.erase(i),a[a[a[*i]]]=a[a[*i]],a[a[*i]]=a[*i],i--;
    if(!(a[s[i+2]]<a[s[i+1]] and a[s[i+2]]<a[s[i]]))continue;
    vector<pair<int,int> >A={{a[s[i]],s[i]},{a[s[i+1]],s[i+1]},{a[s[i+2]],s[i+2]}};
    sort(A.begin(), A.end());
    x[c]=A[1].S,y[c]=A[2].S,z[c]=A[0].S;
    swap(a[x[c]],a[z[c]]),swap(a[z[c]],a[y[c]]);
    c++;
  }
  // for (int i = 1; i <= n; ++i)
  // {
  //   cout<<a[i];
  // }
  if(is_sorted(a+1,a+1+n) and c<=k)cout<<c<<"\n";else {cout<<-1;return;}
  for (int i = 0; i < c; ++i)
  {
    cout<<x[i]<<" "<<y[i]<<" "<<z[i]<<"\n";
  }
}
int main()
{
  ibs;cti;
  // solve(),cout<<"\n";
  int t;cin>>t;
  while(t--){solve();cout<<"\n";}
  return 0;
}