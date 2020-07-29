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
int n,k,a[N];
void solve(){
    cin>>n>>k;set<int>B;map<int,int>A;
    rep(i,1,n)cin>>a[i];
    rep(i,1,k){
        A[a[i]]++;
    }
    for(auto i:A)if(i.S==1)B.insert(i.F);
    if(B.empty())cout<<"Nothing";
    else cout<<*B.rbegin();
    cout<<"\n";
    rep(i,k+1,n){
        if(a[i]!=a[i-k]){
            //we remove a[i-k] and insert a[i]
            if(A[a[i-k]]==2){
                A[a[i-k]]=1;
                B.insert(a[i-k]);
            }
            else if(A[a[i-k]]==1){
                A[a[i-k]]=0;
                B.erase(a[i-k]);
            }
            else{
                A[a[i-k]]--;
            }
            if(A[a[i]]==0){
                A[a[i]]=1;
                B.insert(a[i]);
            }
            else if(A[a[i]]==1){
                A[a[i]]=2;
                B.erase(a[i]);
            }
            else{
                A[a[i]]++;
            }
        }
        if(B.empty())cout<<"Nothing";
        else cout<<*B.rbegin();
        cout<<"\n";
    }
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