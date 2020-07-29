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
int a[N][2];
// bool cmp(int A[2],int B[2]){
//   return A[0]-A[1]>B[0]-B[1];
// }
void solve(){
  int n,x;cin>>n>>x;
  int ma=-1e9-1,X,Y,md=-1e9-1;
  for (int i = 0; i < n; ++i)
  {
    cin>>a[i][0]>>a[i][1];md=max(md,a[i][0]);
    if(ma<a[i][0]-a[i][1])ma=a[i][0]-a[i][1],X=a[i][0],Y=a[i][1];
  }
  // sort(a,a+n,cmp);
  if(x>md and ma<=0){cout<<-1;return;}
  int t=0;
  if(x<=md){cout<<1;return;}
  t=(x-md+ma-1)/ma+1;
  cout<<t;
}
int main()
{
    ibs;cti;
    int t;cin>>t;
    while(t--){
      solve();
      // cout<<len;
      cout<<"\n";
    }
    return 0;
}