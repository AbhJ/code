//Coded by Abhijay Mitra
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <numeric>
#include <vector>
#include <iterator> 
#include <map>
#include <set>
#include <climits>
#include <queue>
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
#define koto_memory(a) cout<<(sizeof(a)/1048576.0)<<" MB";
#define res(v) v.resize(unique(v.begin(), v.end()) - v.begin());
#define cnt_res(v) std::distance(v.begin(),std::unique(v.begin(), v.end())); 
#define timer cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
using vi = std::vector<int>;
using vvi = std::vector<vi>;
using pii = std::pair<int,int>;
using vpii = std::vector<pii>;
using vvpii = std::vector<vpii>;
#define mp         make_pair
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define per(i,b,a) for (int i = b; i >= a; i--)
#define all(x)     x.begin(), x.end()
using namespace std;
const int N=2e6+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n,m,cost;pii a[N];int f[N],A[N];
void solve(){
  cin>>n>>m;cost=0;
  rep(i,1,m)cin>>a[i].F>>a[i].S;
  f[m+1]=0;
  sort(a+1,a+1+m);
  per(i,m,1){
    A[i]=a[i].F;
    f[i]=f[i+1]+a[i].F;
  }
  rep(i,1,m){
    int pos=upper_bound(A+1,A+1+m,a[i].S)-A;
    int ans=f[pos];
    if(pos==m+1)ans=0;
    int koto_baar=n-(m-pos+1);
    if(a[i].F<=a[i].S){
      ans+=a[i].F;
      koto_baar--;
    }
    if(koto_baar<=0)cost=max(cost,f[m-n+1]);
    else 
      cost=max(cost,ans+koto_baar*(a[i].S));
  }
  cout<<cost;
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