#include <bits/stdc++.h>
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
using namespace std;//coded by abhijay mitra
void solve(){
  int r,c;cin>>r>>c;string x[r];bool h=0;
  for (int i = 0; i < r; ++i)cin>>x[i];
  int ans=-1;bool y=0;
  for (int i = 0; i < r; ++i){
    for(int j=0;j<c;j++)if(x[i][j]=='P')y=1;else h=1;
  }
  if(!h){cout<<"MORTAL";return;}
  if(!y){cout<<0;return;}y=0;
  for(int i = 0; i < c; ++i)if(x[0][i]=='P')y=1;
  if(!y){cout<<1;return;}y=0;
  for(int i = 0; i < c; ++i)if(x[r-1][i]=='P')y=1;
  if(!y){cout<<1;return;}y=0;
  for(int i = 0; i < r; ++i)if(x[i][c-1]=='P')y=1;
  if(!y){cout<<1;return;}y=0;
  for(int i = 0; i < r; ++i)if(x[i][0]=='P')y=1;
  if(!y){cout<<1;return;}y=0;
  if((x[0][c-1]=='A')){cout<<2;return;}
  if((x[0][0]=='A')){cout<<2;return;}
  if((x[r-1][c-1]=='A')){cout<<2;return;}
  if((x[r-1][0]=='A')){cout<<2;return;}
  for (int i = 0; i < r; ++i){
    bool y=0;if(x[i][0]=='P')continue;
    for(int j=1;j<c;j++)
      if(x[i][j]!=x[i][j-1])y=1;
    if(y==0){ans=2;break;}
  }
  for (int i = 0; i < c; ++i){
    bool y=0;if(x[0][i]=='P')continue;
    for(int j=1;j<r;j++)
      if(x[j][i]!=x[j-1][i])y=1;
    if(y==0){ans=2;break;}
  }
  if(ans==2){cout<<2;return;}y=0;
  for(int i = 1; i < c; ++i)if(x[0][i]=='A')y=1;
  for(int i = 1; i < c; ++i)if(x[r-1][i]=='A')y=1;
  for(int i = 1; i < r; ++i)if(x[i][c-1]=='A')y=1;
  for(int i = 1; i < r; ++i)if(x[i][0]=='A')y=1;
  if(y){cout<<3;return;}
  cout<<4;return;
}
int main()
{   
    ibs;cti;
    int t;cin>>t;
    while(t--)
    solve(),cout<<"\n";
    return 0;
}