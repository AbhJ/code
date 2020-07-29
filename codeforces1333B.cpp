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
// int i,a[10],ans;
void solve(){
  int n;cin>>n;std::vector<int> v(n),A(n);int a=-1,b=-1;
  for (int i = 0; i < n; ++i)
  {
    cin>>v[i];if(a==-1 and v[i]==-1)a=i;
    if(b==-1 and v[i]==1)b=i;
  }
  bool c=0;
  for (int i = 0; i < n; ++i)
  {
    cin>>A[i];
    if(A[i]>v[i]){
      if(b>=i or b==-1)c=1;
    }
    if(A[i]<v[i]){
      if(a>=i or a==-1)c=1;
    }
  }
  if(c)cout<<"NO";
  else cout<<"YES";
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