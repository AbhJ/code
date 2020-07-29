#include <bits/stdc++.h>
// #include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=2e5+10;
const ll M = 1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
int a[N];set<int>s;
int b[N];
void add(){
  int i,v;cin>>i>>v;
  while(1){
    auto j=s.lower_bound(i);
    if(j==s.end())break;
    if(b[*j]+v<=a[*j]){b[*j]+=v;break;}
    v-=a[*j]-b[*j];b[*j]=a[*j];
    i=*(j);s.erase(*j);
  }  
}
void ask(){
  int i;cin>>i;cout<<b[i]<<"\n";
}
void solve(){
  int n;cin>>n;
  for (int i = 1; i <= n; ++i)
  {
    cin>>a[i];s.insert(i);
  }
  int q;cin>>q;
  while(q--){
    int x;cin>>x;if(x==1)add();
    else ask();
  }
}
int main()
{
    // ibs;cti;
    // int t;cin>>t;
    // while(t--){
      solve();
      // cout<<len;
      // cout<<"\n";
    // }
    return 0;
}