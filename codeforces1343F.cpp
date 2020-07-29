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
#define res(vector) v.resize(unique(v.begin(), v.end()) - v.begin());
#define timer cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
using namespace std;
const int N=2e3+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n;vector<set<int>>a,b;
int cnt=0;
vector<int> solver(int first){
  // if(cnt==n)return "";
  int num_hav_f=0,num_hav_one_ele=0;
    for(int i=0;i<n-1;i++){
      if(b[i].count(first))b[i].erase(first),num_hav_f++;
    }
    int next=-1;
    for(int i=0;i<n-1;i++){
      if(b[i].size()==1)num_hav_one_ele++,next=*b[i].begin();
    }
    if(num_hav_one_ele!=1)return {-1};
    // char fi=first+'0';
    // cnt++;
    vector<int> ans={first};auto z=solver(next);
    for(auto i:z)ans.pb(i);
    return ans;
}
void clean(){
  b=a;
}
bool check(vector<int> s){
  clean();set<set<int>>removed;
  // assert(s.length()==n);
  for(int i=1;i<n;i++){
    bool c=0;
    for(int j=0;j<i;j++){
      set<int>S;
      for(int ele=j;ele<=i;ele++)
        S.insert(s[ele]);
      if(count(b.begin(),b.end(),S)==1 and removed.count(S)==0)c=1,removed.insert(S);
    }
    if(c!=1){return 0;}
  }
  return 1;
}
void solve(){
  cin>>n;cnt=0;a=b=vector<set<int>>(n-1);
  for(int i=0;i<n-1;i++){
    int x,y;cin>>x;
    while(x--)cin>>y,a[i].insert(y);
    b[i]=a[i];
  }
  for(int f=n;f>=1;f--){
    clean();cnt=0;
    auto s=solver(f);
    if(s.size()!=n)continue;
    // cout<<s<<"\n";
    for(int i=1;i<=n;i++){
      bool ch=0;
      for(int j=0;j<n;j++){
        if(s[j]==i){ch=1;break;}
      }
      if(ch==0){s[n-1]=i;break;}
    }
    // cout<<s<<"\n";
    if(s.size()==n)if(check(s)==1){
      for(int i=0;i<n;i++)cout<<s[i]<<" ";
      return;}
  }
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