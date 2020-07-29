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
const int N=2e6+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
string s;int n,a,b,c;
void solve(){
	cin>>s;
	n=s.length();
	//masha eats 1st set bit
	//petya eats 1st unset bit
	for(auto i:s){
		if(i=='0')a++;
		if(i=='1')b++;
		if(i=='?')c++;
	}
	if(c==0){
		if(a>b)cout<<"00\n";
		if(a==b-(n&1)){
			if(s.back()=='1')cout<<"01\n";
			if(s.back()=='0')cout<<"10\n";
		}
		if(b>a+1)cout<<"11\n";
		return;
	}
	if(a+c>b)cout<<"00\n";
	rep(x,0,c){
		if(a+x==b+c-x-(n&1)){
			if(s.back()=='1')cout<<"01\n";
			if(s.back()=='0')cout<<"10\n";
			break;
		}
	}
	int C=c,A=a,B=b;
	if(s.back()=='?'){
		c--;b++;
		rep(x,0,c)
			if(a+x==b+c-x-(n&1)){
				cout<<"01\n";break;
			}
		c=C;a=A;b=B;
		c--;a++;
		//we made last digit 0
		rep(x,0,c)
			if(a+x==b+c-x-(n&1)){
				cout<<"10\n";break;
			}
	}
	c=C,a=A,b=B;
	if(b+c>a+1)cout<<"11\n";
}
int32_t main()
{
  ibs;cti;
  solve()
  /*,cout<<"\n"*/;
  // cout<<"\n";
  int xx=0;
  // int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();cout<<"\n";}
  return 0;
}