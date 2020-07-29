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
string s,t,tmp;int n,cnt,sum;
void solve(){
  cin>>s;n=s.length();
  rep(i,0,n-1)sum+=s[i]-'0';
  set<int>S[3];
  //mod,index
  if((sum%3)==0)t=s;
  rep(i,0,n-1)S[(s[i]-'0')%3].insert(i);
  if((sum%3)==1){
    tmp=s;
    //remove one 1 or two 2
    if(S[1].size()){
        tmp.erase(*S[1].rbegin(),1);
        cnt=0;
        rep(i,0,tmp.length()-1){
          if(tmp[i]=='0')cnt++;
          else break;
        }
        if(tmp.length()!=cnt)
        tmp.erase(0,cnt);
        if(tmp.length()>t.length())t=tmp;
    }
    if(S[2].size()>1){
        tmp=s;        
        tmp.erase(*S[2].rbegin(),1);
        S[2].erase(*S[2].rbegin());
        tmp.erase(*S[2].rbegin(),1);
        cnt=0;
        rep(i,0,tmp.length()-1){
          if(tmp[i]=='0')cnt++;
          else break;
        }
        if(tmp.length()!=cnt)
        tmp.erase(0,cnt);
        if(tmp.length()>t.length())t=tmp;
    }
  }
  if((sum%3)==2){
    tmp=s;
    //remove one 1 or two 2
    if(S[2].size()){
        tmp.erase(*S[2].rbegin(),1);
        cnt=0;
        rep(i,0,tmp.length()-1){
          if(tmp[i]=='0')cnt++;
          else break;
        }
        if(tmp.length()!=cnt)
        tmp.erase(0,cnt);
        if(tmp.length()>t.length())t=tmp;
    }
    if(S[1].size()>1){
        tmp=s;
        tmp.erase(*S[1].rbegin(),1);
        S[1].erase(*S[1].rbegin());
        tmp.erase(*S[1].rbegin(),1);
        cnt=0;
        rep(i,0,tmp.length()-1){
          if(tmp[i]=='0')cnt++;
          else break;
        }
        if(tmp.length()!=cnt)
        tmp.erase(0,cnt);
        // cout<<tmp;
        if(tmp.length()>t.length())t=tmp;
    }
  }
  if(t.empty())cout<<"-1",exit(0);
  cnt=0;
  rep(i,0,t.length()-1){
    if(t[i]=='0')cnt++;
    else break;
  }
  t.erase(0,cnt);
  sum=0;
  if(t=="")t="0";
  for(auto i:t)sum+=i-'0';
  if(sum%3)cout<<"-1",exit(0);
  cout<<t;
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  /*,cout<<"\n"*/;
  // cout<<"\n";
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();cout<<"\n";}
  return 0;
}