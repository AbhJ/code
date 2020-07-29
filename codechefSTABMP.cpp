#include <bits/stdc++.h>
// #include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=5e2+10;
const ll M = 1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
int a[2][N][N];//women 0 man 1
int w[N]; 
void solve(){
  memset(w,0,sizeof(w));
  int n;cin>>n;
  for(int k=0;k<2;k++)  
    for (int i = 0; i < n; ++i){
      int x;cin>>x;
      for(int j=1;j<=n;j++)
        cin>>a[k][x][j];
    }
  queue<int>q;
  for(int i=1;i<=n;i++)q.push(i);
  while(!q.empty()){
    int x=q.front();q.pop();//q is woman
    for(int i=1;i<=n;i++){
      int m=a[0][x][i];//chosen man
      if(w[m]==0){w[m]=x;break;}//man is unmarried
      bool f=0;
      for(int j=1;j<=n;j++){
        if(a[1][m][j]==w[m])break;//the wife of man is higher than other woman ie marriage is ok
        if(a[1][m][j]==x){//chosen woman ranks higher in man m
          f=1;
          q.push(w[m]);//the man lost its wife
          w[m]=x;
        }
      }
      if(f)break;
    }
  }
  for (int i = 1; i <= n; ++i)
  {
    cout<<i<<" "<<w[i]<<"\n";
  }
}
int main()
{
    ibs;cti;
    int t;cin>>t;
    while(t--){
      solve();
      // cout<<"\n";
    }
    return 0;
}