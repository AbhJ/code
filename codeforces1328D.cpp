#include <bits/stdc++.h>
#include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=2e6+10;
const ll M =  998244353; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
void solve(){
  int n;cin>>n;
  std::vector<int> v(n);bool b=1,c=0;int ind=-1;
  for (int i = 0; i < n; ++i)
  {
    cin>>v[i];
    if(!i)continue;
    if(v[i]==v[i-1])c=1,ind=i-1;else b=0;
  }
  if(v[0]==v[n-1])c=1,ind=n-1;else b=0;
  if(b){cout<<"1\n";for(int i=0;i<n;i++)cout<<"1 ";return;}
  if(!(n%2)){cout<<"2\n";for(int i=0;i<n;i++){if(i%2)cout<<" 1 ";else cout<<"2";}return;}
  if(c){cout<<"2\n";int c=1;for(int i=0;i<n;i++){cout<<c<<" ";if(i!=ind)c%=2,c++;}return;}
  cout<<"3\n3 ";for(int i=0;i<n-1;i++){if(i%2)cout<<" 1 ";else cout<<"2";}
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