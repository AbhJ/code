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
#include <bits/stdc++.h>
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
const int N=3e2+10;
const double inf = /*0x3f3f3f3f*/-1.0;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
double dp[N][N][N],d[N][N][N];int n,A[N];
double f(int i,int j,int k){
  if(d[i][j][k]!=inf)return d[i][j][k];
  if((i||j||k)==0)return 0;
  d[i][j][k]=n;
  //F(x,y,z) = 1 + p0F(x,y,z) + p1F(x-1,y,z) + p2F(x+1,y-1,z) + p3F(x,y+1,z-1)
  //p's are probabilitites
  //p0 for picking a dish with 0 sushi
  //p1 for picking a dish with 1 sushi
  //p2 for picking a dish with 2 sushi
  //p3 for picking a dish with 3 sushi
  //F(x,y,z) = (1+p1F(x-1,y,z) + p2F(x+1,y-1,z) + p3*F(x,y+1,z-1))/(1-p0)
  double p0=(double)(n-i-j-k)/(double)n;
  if(i!=0)d[i][j][k]+=(double)i*(f(i-1,j,k));
  if(j!=0)d[i][j][k]+=(double)j*(f(i+1,j-1,k));
  if(k!=0)d[i][j][k]+=(double)k*(f(i,j+1,k-1));
  d[i][j][k]=d[i][j][k]/(double)(i+j+k);
  return d[i][j][k];
}
int a,b,c;
void solve(){
  cin>>n;rep(i,1,n)cin>>A[i];
  rep(i,1,n){
    if(A[i]==1)a++;
    if(A[i]==2)b++;
    if(A[i]==3)c++;
  }
  dp[a][b][c]=1;
  per(k,n,0)
    per(j,n,0)
      per(i,n,0){
        d[i][j][k]=inf;
        // if((i==0 and j==0) or (j==0 and k==0) or (i==0 and k==0))continue;
        if(i!=0){dp[i-1][j][k]+=dp[i][j][k]*(double)i/(i+j+k);}
        if(j!=0){dp[i+1][j-1][k]+=dp[i][j][k]*(double)j/(i+j+k);}
        if(k!=0){dp[i][j+1][k-1]+=dp[i][j][k]*(double)k/(i+j+k);}
      }
  //dp[i][j][k] is the probability of reaching the i j k state
  cout<<setprecision(20)<<f(a,b,c);
        // cout<<d[i][j][k];
}
int32_t main()
{
  // ibs;cti; 
  solve()
  /*,cout<<"\n"*/;
  // cout<<"\n";
  int xx=0;
  // int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();cout<<"\n";}
  return 0;
}