#include <bits/stdc++.h>
#include <numeric> 
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=3e6+3;
const ll M = 998244353; // modulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
ll A[N],B[N];
void solve(){
  int n;cin>>n;std::vector<ll> v;
  for (int i = 0; i < n; ++i)
  {
    cin>>A[i];B[i]=1;
    while((!v.empty()) and (A[i]>A[v.back()]))B[i]=max(B[i],B[v.back()]+1),v.pop_back();
    if(v.empty())B[i]=0;v.pb(i);
  }
  cout<<*max_element(B,B+n);
}
int main()
{   
    ibs;cti;
    // int t;cin>>t;
    // while(t--)
    solve(),cout<<"\n";
    return 0;
}