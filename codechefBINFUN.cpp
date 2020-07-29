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
#define pb emplace_back
#define koto_memory(a) cout<<(sizeof(a)/1048576.0)<<" MB";
#define res(v) sort(all(v)),v.erase(unique(all(v)), v.end());
#define timer cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
#define deb(x) cout<<"\n["<<#x<<" = "<<x<<"]\n";
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
int n,a[N];
int f(int a,int b){
  string s1=bitset<70>(a).to_string(),s2=bitset<70>(b).to_string(),s3,s4;
  int cnt=0;
  for(auto i:s1){
    if(i!='0'){
      s1.erase(0,cnt);
      break;
    }
    cnt++;
  }
  cnt=0;
  for(auto i:s2){
    if(i!='0'){
      s2.erase(0,cnt);
      break;
    }
    cnt++;
  }
  s3=s1+s2;
  s4=s2+s1;
  return bitset<200>(s3).to_ullong()-bitset<200>(s4).to_ullong();
}
void solve(){
  cin>>n;vpii v={{0,0}};
  rep(i,1,n)cin>>a[i];
  int ans=-1;sort(a+1,a+1+n);
  // rep(i,1,n)
  //   rep(j,1,n){
  //     if(ans==-1)ans=f(a[i],a[j]);else
  //     ans=max(ans,f(a[i],a[j]));
  //   }
  rep(i,1,n){
    v.pb(a[i],1+(int)log2(a[i]));
  }
  sort(all(v));
  // sort(a+1,a+1+n);
  rep(i,1,n){
    int last=0;
    per(j,n,i+1){
      int ch=v[i].F*((1<<v[j].S)-1)-v[j].F*((1<<v[i].S)-1);
      ch=abs(ch);
      if(ch<last)break;
      last=ch,ans=max(last,ans);
    }
  }
  cout<<ans;
  // cout<<s1<<"\n"<<s2;
}
int32_t main()
{
  ibs;cti;
  // solve();return 0;
  /*,cout<<"\n"*/;
  // cout<<"\n";
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();cout<<"\n";}
  return 0;
}