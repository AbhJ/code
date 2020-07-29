//Coded by Abhijay Mitra
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
using namespace std;
const int N=2e6+10;
const int inf = /*0x3f3f3f3f*/1e9+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n,a[N],spf[N+1],l[N];
// spf is smallest prime factor
void f()
{
    for(int i=1;i<=N;i++)
        spf[i]=i;
    for(int i=2;i<=sqrt(N);i++)
        if(spf[i]==i)
        {
            for(int j=i*i;j<=N;j+=i)
                if(spf[j]==j)
                    spf[j]=i;
        }
}
void solve(){
  cin>>n;memset(l,-1,sizeof l);
  int last=0,ans=0;
  for(int i=0;i<n;i++)cin>>a[i];
  for(int i=0;i<n;i++){
    int x=a[i];
    while(x>1){
      int s=spf[x];
      while((x%s)==0)x/=s;//remove highest power of spf
      last=max(last,l[s]+1);
      //l[i] is leftmost index such that a[l[i]] ain't coprime with a[i]
      l[s]=i;
    }
    ans=max(ans,i-last+1);
  }
  if(ans==1)ans=-1;
  cout<<ans;
}
int32_t main()
{
  ibs;cti;
  f();
  // solve()
  /*,cout<<"\n"*/;
  // cout<<"\n";
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();cout<<"\n";}
  return 0;
}