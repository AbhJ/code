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
#define ll 
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
bool f0(vi a,vi b){
  return a==b;
}
bool check_for_aa_mm(int x,int y,int z,int X,int Y,int Z){
  if((X-x==Y-y or X*y==Y*x) and z!=Z){return 1;}
  if(X-x+Z-z==Y-y){return 1;}//a,a
  if(x!=0 and y!=0 and z!=0 and (X%x)==0 and (Z%z)==0 and (Y%y)==0)if((X/x)*(Z/z)==(Y/y)){return 1;}//m,m
  if(x==X)return 1;
  return 0;
}
vi add(vi ad,int pos,vi a,vi b){
  int ch=b[pos]-a[pos];
  rep(i,0,2)
    if(ad[i]==1)
      a[i]+=ch;
  return a;
}
vvi adder(vvi v,vi ad,vi a,vi b){
  rep(i,0,2){
    if(ad[i]==1){
      v.pb(add(ad,i,a,b));
    }
  }
  return v;
}
bool mul(vi ad,int pos,vi a,vi b){
  int ch=b[pos]/a[pos];
  rep(i,0,2)
    if(ad[i]==1)
      a[i]*=ch;
  if(a==b)return 1;
  return 0;
}
bool muller(vi ad,vi a,vi b){
  rep(i,0,2)
    if(ad[i]==1 and a[i]!=0 and (abs(b[i])%abs(a[i]))==0)
      if(mul(ad,i,a,b))return 1;
  return 0;
}
bool fam(vi a,vi b){
  vi ad={-1,-1,-1};
  vvi v;
  rep(i,0,2)
    rep(j,0,2)
      rep(k,0,2){
        ad[i]=ad[j]=ad[k]=1;
        v=adder(v,ad,a,b);
        ad[i]=ad[j]=ad[k]=-1;
      }
  rep(i,0,2)
    rep(j,0,2)
      rep(k,0,2)
        for(auto vec:v){
          ad[i]=ad[j]=ad[k]=1;
          if(muller(ad,vec,b))return 1;
          ad[i]=ad[j]=ad[k]=-1;
      }
  return 0;
}
vi multo(vi ad,int pos,vi a,vi b){
  int ch=b[pos]/a[pos];
  rep(i,0,2)
    if(ad[i]==1)
      a[i]*=ch;
  return a;
}
vvi multi(vvi v,vi ad,vi a,vi b){
  rep(i,0,2){
    if(ad[i]==1 and a[i]!=0 and (abs(b[i])%abs(a[i]))==0){
      v.pb(multo(ad,i,a,b));
    }
  }
  return v;
}
bool add_ch(vi ad,int pos,vi a,vi b){
  int ch=b[pos]-a[pos];
  rep(i,0,2)
    if(ad[i]==1)
      a[i]+=ch;
  return (b==a);
}
bool addo(vi ad,vi a,vi b){
  rep(i,0,2)
    if(ad[i]==1)
      if(add_ch(ad,i,a,b))return 1;
  return 0;
}
bool fma(vi a,vi b){
  vi ad={-1,-1,-1};
  vvi v;
  rep(i,0,2)
    rep(j,0,2)
      rep(k,0,2){
        ad[i]=ad[j]=ad[k]=1;
        v=multi(v,ad,a,b);
        ad[i]=ad[j]=ad[k]=-1;
      }
  rep(i,0,2)
    rep(j,0,2)
      rep(k,0,2)
        for(auto vec:v){
          ad[i]=ad[j]=ad[k]=1;
          if(addo(ad,vec,b))return 1;
          ad[i]=ad[j]=ad[k]=-1;
      }
  return 0;
}
bool f1(vi a,vi b){
  int c=0;vi ad={-1,-1,-1};
  rep(i,0,2)
    if(a[i]!=b[i])c++;
  if(c==1)return 1;
  rep(i,0,2)
    rep(j,0,2)
      rep(k,0,2)
        {
          ad[i]=ad[j]=ad[k]=1;
          if(addo(ad,a,b))return 1;
          ad[i]=ad[j]=ad[k]=-1;
      }
  rep(i,0,2)
    rep(j,0,2)
      rep(k,0,2)
        {
          ad[i]=ad[j]=ad[k]=1;
          if(muller(ad,a,b))return 1;
          ad[i]=ad[j]=ad[k]=-1;
      }
  return 0;
}
bool det(int a,int b,int c,int d,int e,int f,int g, int h,int i){
  return ((a*(e*i-f*h))-(b*(d*i-g*f))+(c*(d*h-e*g))==0);
}
bool check_if_concurrent1(vi ad,vi mul, vi a,vi b){
  rep(i,0,2)
    if(mul[i]==-1)
      b[i]-=a[i];
  vi first_col(3,0),second_col(3,0),third_col(3,0);
  rep(i,0,2)
    if(mul[i]==1)
      first_col[i]=a[i];
  rep(i,0,2)
    if(ad[i]==1)
      second_col[i]=1;
  rep(i,0,2)
    third_col[i]=-b[i];
  if (det(first_col[0],second_col[0],third_col[0],
    first_col[1],second_col[1],third_col[1],
    first_col[2],second_col[2],third_col[2])==0)return 0;
  int d=first_col[0]*second_col[1]-first_col[1]*second_col[0];
  if(d==0)return 0;
  int x=third_col[0]*second_col[1]-second_col[0]*third_col[1];
  x/=d;
  int y=third_col[0]*first_col[1]-first_col[0]*third_col[1];
  y/=d;
  if((x*d==third_col[0]*second_col[1]-second_col[0]*third_col[1])
    and (y*d==third_col[0]*first_col[1]-first_col[0]*third_col[1]))
    return 1;
  return 0;
}
bool solve_eq(vi a,vi b){
  vi ad={-1,-1,-1};
  vvi v;
  rep(i,0,2)
    rep(j,0,2)
      rep(k,0,2){
        ad[i]=ad[j]=ad[k]=1;
        v.pb(ad);//multiply
        ad[i]=ad[j]=ad[k]=-1;
      }
  rep(i,0,2)
    rep(j,0,2)
      rep(k,0,2)
        for(auto vec:v){
          ad[i]=ad[j]=ad[k]=1;
          if(check_if_concurrent1(ad,vec,a,b))return 1;
          ad[i]=ad[j]=ad[k]=-1;
      }
  return 0;
}
int pm1( int p, int q, int r, int a, int b, int c)//done
{
    if(q!=0&&r==c&&b%q==0)
        return 1;
    else if(b==0&&q==0&&r==c)
        return 1;
    else
        return 0;
}
int pm2( int p, int q, int r, int a, int b, int c)
{
    if(q!=0&&r==c&&b%q==0&&b!=0&&(a*q)%b==0)
        return 1;
    else if(r==c&&b==0&&a==0)
        return 1;
    else if(q==0&&b==0&&r==c)
        return 1;
    else if(r==c&&b!=0&&q==0)
        return 0;
    else
        return 0;
}
int pm4( int p, int q, int r, int a, int b, int c)
{
    if(r!=0&&q!=0&&c%r==0&&b%q==0&&b/q==c/r&&c!=0&&(a*r)%c==0&&b!=0&&c!=0)
        return 1;
    else if(q==0&&r!=0&&b==0&&c%r==0&&c!=0&&(a*r)%c==0)
        return 1;
    else if(q!=0&&b%q==0&&r==0&&c!=0)
        return 1;
    else
        return 0;

}
int pm3( int p, int q, int r, int a, int b, int c)
{
    if(q!=0&&r!=0&&b%q==0&&c%r==0&&b/q==c/r&&p!=a)
        return 1;
    else
        return 0;
}
int mf1( int p, int q, int r, int a, int b, int c)
{
    int m=b-q;
    if(p+m!=0&&a%(p+m)==0&&r==c)
        return 1;
    else if(p+m==0&&r==c&&a==0)
        return 1;
    else
        return 0;
}
int mf2( int p, int q, int r, int a, int b, int c)
{
    if(r!=0&&c%r==0&&b-q==a-p)
        return 1;
    else
        return 0;
}
int mf3( int p, int q, int r, int a, int b, int c)//doubt
{
    if(b!=a&&q!=p&&r==c&&(a*q-b*p)%(b-a)==0&&(b-a)%(q-p)==0)
        return 1;
    else if(b==a&&r==c&& q==p)
        return 1;
    else
        return 0;
}
int mf4( int p, int q, int r, int a, int b, int c)
{
    if(r!=0&&c%r==0&&p+b!=q&&c*p+c*b==c*q+a*r)
        return 1;
    else if(r!=0&&a==0&&p+b-q==0&&c%r==0&&c*p+c*b==c*q+a*r&&c==0)
        return 1;
    else if(r==0&&c==0&&p+b-q!=0&&a%(p+b-q)==0)
        return 1;
    else
        return 0;
}
int mf5( int p, int q, int r, int a, int b, int c)
{
    if(r!=0&&c!=0&&c%r==0&&(a*r)%c==0&&(b*r)%c==0&&b*r/c-q==a*r/c-p)
        return 1;
    else
        return 0;
}
int mp1( int p, int q, int r, int a, int b, int c)
{
    if(b-q==c-r&&(p+b-q)!=0&&a%(p+b-q)==0)
        return 1;
    else if(b-q==c-r&&p+b-q==0&&a==0)
        return 1;
    else
        return 0;
}
int mp2( int p, int q, int r, int a, int b, int c)
{
    if(p+c!=r&&q+c!=r&&a%(p+c-r)==0&&b%(q+c-r)==0&&(a*q+a*c-a*r==b*p+b*c-b*r))
        return 1;
    else if(p+c-r==0&&a==0&&b!=0&&q+c-r!=0&&b%(q+c-r)==0&&(a*q+a*c-a*r==b*p+b*c-b*r))
        return 1;
    else if(q+c-r==0&&b==0&&a!=0&&p+c-r!=0&&a%(p+c-r)==0&&a*q+a*c-a*r==b*p+b*c-b*r)
        return 1;
    else if(q+c-r==0&&a==0&&p+c-r==0&&b==0&&a*q+a*c-a*r==b*p+b*c-b*r)
        return 1;
    else
        return 0;
}
int mp3( int p, int q, int r, int a, int b, int c)//doubt
{
    if(-b*c*p-a*b*q+b*b*p==b*b*r-b*c*q-a*b*r&&b*c*r-c*c*q+a*c*q==a*c*r-c*c*p+b*c*p&&b!=a&&b!=c&&c!=a&&r!=p&&p!=q&&q!=r&&(a*q-b*p)%(b-a)==0&&(b*r-c*q)%(c-b)==0&&(a*r-c*p)%(c-a)==0&&(b-a)%(q-p)==0&&(c-b)%(r-q)==0&&(a-c)%(p-r)==0&&b*r-a*r+a*q==c*q-p*c+p*b&&a*r-a*q+c*q==p*c-p*b+r*b)
        return 1;
    else if(-b*c*p-a*b*q+b*b*p==b*b*r-b*c*q-a*b*r&&b*c*r-c*c*q+a*c*q==a*c*r-c*c*p+b*c*p&&b==a&&p==q&&a!=c&&c!=b&&r!=q&&p!=r&&(b*r-c*q)%(c-b)==0&&(a*r-c*p)%(c-a)==0&&(c-b)%(r-q)==0&&(a-c)%(p-r)==0&&b*r-a*r+a*q==c*q-p*c+p*b&&a*r-a*q+c*q==p*c-p*b+r*b)
        return 1;
    else if(-b*c*p-a*b*q+b*b*p==b*b*r-b*c*q-a*b*r&&b*c*r-c*c*q+a*c*q==a*c*r-c*c*p+b*c*p&&b==c&&q==r&&a!=b&&c!=a&&p!=r&&p!=q&&(a*q-b*p)%(b-a)==0&&(a*r-c*p)%(c-a)==0&&(b-a)%(q-p)==0&&(a-c)%(p-r)==0&&b*r-a*r+a*q==c*q-p*c+p*b&&a*r-a*q+c*q==p*c-p*b+r*b)
        return 1;
    else if(-b*c*p-a*b*q+b*b*p==b*b*r-b*c*q-a*b*r&&b*c*r-c*c*q+a*c*q==a*c*r-c*c*p+b*c*p&&a==c&&p==r&&b!=c&&b!=a&&q!=p&&q!=r&&(a*q-b*p)%(b-a)==0&&(b*r-c*q)%(c-b)==0&&(b-a)%(q-p)==0&&(c-b)%(r-q)==0&&b*r-a*r+a*q==c*q-p*c+p*b&&a*r-a*q+c*q==p*c-p*b+r*b)
        return 1;
    else
        return 0;
}
bool solver(vi A,vi B){
  int p=A[0],q=A[1],r=A[2],a=B[0],b=B[1],c=B[2];
  vi x;vvi cases{{p,q,r,a,b,c},{p,r,q,a,c,b},{q,p,r,b,a,c},{q,r,p,b,c,a},{r,p,q,c,a,b},{r,q,p,c,b,a}};
  for(auto v:cases){
    p=v[0],q=v[1],r=v[2],a=v[3],b=v[4],c=v[5];
    x.pb(pm1(p,q,r,a,b,c));
    x.pb(pm2(p,q,r,a,b,c));
    x.pb(pm3(p,q,r,a,b,c));
    x.pb(pm4(p,q,r,a,b,c));
    x.pb(mp1(p,q,r,a,b,c));
    x.pb(mp2(p,q,r,a,b,c));
    x.pb(mp3(p,q,r,a,b,c));
    x.pb(mf1(p,q,r,a,b,c));
    x.pb(mf2(p,q,r,a,b,c));
    x.pb(mf3(p,q,r,a,b,c));
    x.pb(mf4(p,q,r,a,b,c));
    x.pb(mf5(p,q,r,a,b,c));
  }
  for(auto i:x)if(i)return 1;
  return 0;
}
bool f2(vi a,vi b){
  int x=a[0],y=a[1],z=a[2],X=b[0],Y=b[1],Z=b[2];
  bool ok=0;
  ok|=(check_for_aa_mm(x,y,z,X,Y,Z)|check_for_aa_mm(y,z,x,Y,Z,X)|check_for_aa_mm(z,x,y,Z,X,Y));
  if(ok==1){/*cout<<"f";*/return 1;}
  //a,m
  if(fam(a,b)){return 1;}
  if(fma(a,b)){return 1;}
  if(solve_eq(a,b)){return 1;}
  if(solver(a,b)){return 1;}
  return 0;
}
void solve(){
  vi x(3),y(3);
  rep(i,0,2)cin>>x[i];rep(i,0,2)cin>>y[i];
  //case of 0
  if(f0(x,y)){cout<<0;return;}
  //case of 1
  if(f1(x,y)){cout<<1;return;}
  //case of 2
  if(f2(x,y)){cout<<2;return;}
  //case of 3
  cout<<3;
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