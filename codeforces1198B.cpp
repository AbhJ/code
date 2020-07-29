#include <bits/stdc++.h>
// #include <xeric>QC
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=2e5+10;
// const ll M = 1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
int A[N][2],B[N];
int n,t,T;
void a(){
  int p,x;cin>>p>>x;
  A[p-1][0]=x;A[p-1][1]=t;
}
void b(){
  cin>>B[t];
}
void solve(){
  cin>>n;
  for (int i = 0; i < n; ++i)
  {
    cin>>A[i][0];A[i][1]=0;
  }
  int za;cin>>za;
  while(za--){
    t++;
    int zb;cin>>zb;
    if(zb==1)a();
    else b();
  }
  for (int i = t; i >-1; --i)
  {
    B[i]=max(B[i],B[i+1]);
  }
  for (int i = 0; i < n; ++i)
  {
    int time=A[i][1];
    cout<<max(A[i][0],B[time])<<" ";
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