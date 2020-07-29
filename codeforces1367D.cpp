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
void solve(){
    string s;cin>>s;
    int m;cin>>m;vector<char>v(m,'#');
    vi b(m),f(26,0),pos;
    rep(i,0,m-1){
        cin>>b[i];
        if(b[i]==0)pos.pb(i);
    }
    for(auto i:s)f[i-'a']++;
    while(1){
        per(c,25,0){
            char ch='a'+c;
            if(f[c]<pos.size())continue;
            f[c]-=pos.size();
            rep(j,0,m-1){
                if(b[j]>0){for(auto i:pos)b[j]-=abs(i-j);}
                else if(b[j]==0)v[j]=ch,b[j]=-1;
            }
            pos.clear();
            rep(j,0,m-1)if(b[j]==0)pos.pb(j);
            bool ok=0;
            rep(j,0,m-1)if(v[j]=='#')ok=1;
            if(ok==0)break;
        }
        if(pos.empty()==1)break;
    }
    for(auto i:v)cout<<i;
}
int32_t main()
{
  // ibs;cti;
  // solve()
  /*,cout<<"\n"*/;
  // cout<<"\n";
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();cout<<"\n";}
  return 0;
}