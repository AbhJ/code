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
const int N=5e2+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
//there is a pattern in the three numbers
vvi f{{0,0,0},{1,2,3},{2,3,1},{3,1,2}};
vvi ans;
int a[N];
void brute(){
  if(ans.empty()==0)return;
  rep(i,1,N-1){
    F:;
    rep(x,1,N-1)if(a[x]==0)rep(y,x+1,N-1)if(a[y]==0)rep(z,y+1,N-1)if(a[z]==0)if((x^y^z) ==0){
          a[x]=a[y]=a[z]=1,ans.pb(vi{bitset<10>(x).to_ullong(),bitset<10>(y).to_ullong(),bitset<10>(z).to_ullong()});goto F;}
  }
}
void solve(){
  int n;cin>>n;
  if(n<200){
    brute();
    cout<<ans[((n-1)/3)][(n-1)%3];
    return;
  }
  n--;int nn=n%3;n/=3;n--;
  int cnt=0,x=0;
  stack<int> s;
  rep(i,1,inf){
    if(n<0)break;
    s.push((n/((int)pow(4,cnt)))%4);
    cnt++;
    if(n>=(int)pow(4,cnt))n-=(int)pow(4,cnt);else break;
  }
  s.push(1);
  int A=0,B=0,C=0;
  per(i,inf,0){
    A<<=2;B<<=2;
    if(s.empty()==1)break;
    A|=f[s.top()][0];
    B|=f[s.top()][1];
    s.pop();
  }
  C=A^B;
  if(nn==0)cout<<A/4;
  if(nn==1)cout<<B/4;
  if(nn==2)cout<<C/4;
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