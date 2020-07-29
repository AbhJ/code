#include <bits/stdc++.h>
// #include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=1e5+10;
const ll M = 1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
bool b[N];
set<int>s[N];
vector<int> fact(int n)
{
    vector<int> v;
    for(int i=2;i<=sqrt(n);++i)
    {
        if(n%i==0)
        {
            v.push_back(i);
            if(i*i!=n)
                v.push_back(n/i);
        }
    }
    if(n!=1)v.pb(n);
    return v;
}
int n,m;
void del(){
  int x;cin>>x;
  if(b[x]==0){cout<<"Already off";return;}
  auto v=fact(x);
  b[x]=0;
  for(auto i:v)s[i].erase(x);
  cout<<"Success";
}
void add(){
  int x;cin>>x;
  if(b[x]){cout<<"Already on";return;}
  auto v=fact(x);
  for(auto i:v)if(s[i].empty()==0){cout<<"Conflict with "<<*s[i].begin();return;}
  b[x]=1;
  for(auto i:v)s[i].insert(x);
  cout<<"Success";
}
void solve(){
  cin>>n>>m;
  while(m--){
    char c;cin>>c;
    if(c=='-')del();
    else add();
    if(m)cout<<"\n";
  }
}
int main()
{
    ibs;cti;
    // int t;cin>>t;
    // while(t--){
      solve();
      // cout<<len;
      cout<<"\n";
    // }
    return 0;
}