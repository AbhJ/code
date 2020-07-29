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
int a[N],F[N],n,k,x;
int sum(int f,int l){
    return F[l]-F[f-1];
}
int f(int l){
    // cout<<sum(l+1,x)+l<<" "<<k*(x-l)<<"  ";
    return k*(x-l)<=sum(l,x-1)+l;
}
void solve(){
    int M;cin>>n>>M;
    rep(i,1,n)cin>>a[i];
    sort(a+1,a+1+n);
    F[0]=a[1];
    rep(i,1,n-1)F[i]=F[i-1]+a[i+1];
    // build(a);
    rep(i,1,M){
        cin>>k;
        x=lower_bound(a+1,a+1+n,k)-a-1;
        int L=0,R=x;
        while(L<R){
            int m=L+R>>1;
            if(f(m)==0)L=m+1;
            else R=m;
        }
        cout<<n-L<<"\n";
        // cout<<f(k);
    }
}
int32_t main()
{
  ibs;cti;
  // solve()
  /*,cout<<"\n"*/;
  // cout<<"\n";
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();}
  return 0;
}