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
const int N=2e5+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n,ans;set<int> s;
void solve(){
  cin>>n;s.clear();ans=0;vi a(n);
  rep(i,0,n-1)cin>>a[i],s.insert(a[i]);
  sort(all(a));
  res(a);
  n=cnt_res(a);
  //no need to use multiset as all numbers in the triple are distinct
  int ma=*s.rbegin();
  if((ma%30)==0 and s.count(ma/2)==1 and s.count(ma/3)==1 and s.count(ma/5)==1)
    ans=max(ans,(ma/2)+(ma/3)+(ma/5));
  vi v;
  while(n!=0){
    ma=a[--n];
    bool ok=0;
    for(auto i:v)if((i%ma)==0)ok=1;
    if(ok==0)v.pb(ma);
    if(v.size()==3)break;
  }
  int sum=0;
  for(auto i:v)sum+=i;
  cout<<max(ans,sum);
}
int32_t main()
{
  ibs;cti;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();cout<<"\n";}
  return 0;
}