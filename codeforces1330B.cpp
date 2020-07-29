#include <bits/stdc++.h>
// #include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=3e5+10;
const ll M =  1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
bool c(int* A,int n){
    set<int>s;
    for (int i = 1; i <=n; ++i)s.insert(i);
    for (int i = 0; i < n; ++i)
    {
        if(s.count(A[i]))s.erase(A[i]);
        else return 0;
    }
    if(s.empty())return 1;
    return 0;
}
void solve(){
  int n;cin>>n;
  int A[n];int ma=0;
  std::vector<pair<int,int>> v;
  for (int i = 0; i < n; ++i)cin>>A[i],ma=max(A[i],ma);
  if(c(A,ma) and c(A+ma,n-ma))v.pb({ma,n-ma});
  if(c(A+n-ma,ma) and c(A,n-ma))if(n!=2*ma)v.pb({n-ma,ma});
  cout<<v.size()<<"\n";
  for (auto i:v) cout<<i.F<<" "<<i.S<<"\n";
}
int main()
{
    ibs;cti;
    int t;cin>>t;
    while(t--){
      solve();
      cout<<"\n";
    }
    return 0;
}