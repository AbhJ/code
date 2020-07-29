#include <bits/stdc++.h>
// #include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=5e2+10;
const ll M =  1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
int a[N][N];
void solve(){
  int n,m;cin>>n>>m;
  int x=0;
  for (int i = 0; i < n; ++i)
  {
    for(int j=0;j<m;j++){
      cin>>a[i][j];
    }
    x^=a[i][0];
  }
  if(x){
    cout<<"TAK\n";
    for (int i = 0; i < n; ++i)
    {
      cout<<"1 ";
    }
    return;
  }
  for (int i = 0; i < n; ++i)
  {
    for(int j=0;j<m;j++)
      if(a[i][j]!=a[i][0]){
        cout<<"TAK\n";
        for (int I = 0; I < n; ++I)
        {
          if(I==i)cout<<j+1<<" ";
          else cout<<"1 ";
        }
        return;
      }
  }
  cout<<"NIE";
}
int main()
{
    ibs;cti;
    // int t;cin>>t;
    // while(t--){
      solve();
      cout<<"\n";
    // }
    return 0;
}