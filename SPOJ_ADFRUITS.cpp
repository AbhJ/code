#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
using namespace std;//coded by abhijay mitra
// const int N=2e7+3;
const int N=300;
const int M = 1000000007; // modulo
// ll dp[1000][1000];
ll powM(ll b, int p) {
  ll r=1;
  for(; p; b=b*b%M, p/=2)
    if(p&1)
      r=r*b%M;
  return r;
}
vector<int> fact(int n)
{
    vector<int> v;
    for(int i=1;i<=sqrt(n);++i)
    {
        if(n%i==0)
        {
            v.push_back(i);
            if(i*i!=n)
                v.push_back(n/i);
        }
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    return v;
}
void solve(){
          char a[1010],b[1010];
          while(scanf("%s %s", a,b)==2){
              int n=strlen(a),m=strlen(b);
              int dp[m+1][n+1];
              memset(dp,0,(n+1)*(m+1)*sizeof(int));
              int check[m+1][n+1];memset(check,0,(n+1)*(m+1)*sizeof(int));
              for (int i = 0; i <= m; i++){ 
                     for (int j = 0; j <= n; j++){
                     if (!i)dp[i][j] = j; 
                     else if (!j) dp[i][j] = i; 
                     else if (b[i-1] == a[j-1])dp[i][j] = 1 + dp[i-1][j-1],check[i][j]=0;
                     else{ dp[i][j] = 1 + min(dp[i-1][j],dp[i][j-1]);if(dp[i-1][j]>dp[i][j-1])check[i][j]=1;else check[i][j]=2;//take a or b}
                     } 
                 }
             }
             string s;int x=n,y=m;
             for (;;){
                 if(check[y][x]==0)
                     s+=a[x-1],x--,y--;
                 else if(check[y][x]==1)
                     s+=a[x-1],x--;
                 else if(check[y][x]==2)s+=b[y-1],y--;
                 if(!x)s+=b[y-1],y--;
                 else if(!y)s+=a[x-1],x--;
                 if(y<1 and x<1)break;
             }
             reverse(s.begin(), s.end());
             cout<<s<<"\n";
         }
}
char a[1010],b[1010];int dp[1010][1010];int check[1010][1010];
int main()
{   
    // ibs;cti;
    // int t;cin>>t;
    // while(t--)
      while(scanf("%s %s", a,b)==2){
          int n=strlen(a),m=strlen(b);
          memset(dp,0,(n+1)*(m+1)*sizeof(int));memset(check,0,(n+1)*(m+1)*sizeof(int));
          for (int i = 0; i <= m; i++){ 
                 for (int j = 0; j <= n; j++){
                 if (!i)dp[i][j] = j; 
                 else if (!j) dp[i][j] = i; 
                 else if (b[i-1] == a[j-1])dp[i][j] = 1 + dp[i-1][j-1],check[i][j]=0;
                 else{ dp[i][j] = 1 + min(dp[i-1][j],dp[i][j-1]);if(dp[i-1][j]>dp[i][j-1])check[i][j]=1;else check[i][j]=2;//take a or b}
                 } 
             }
         }
         string s;int x=n,y=m;
         for (;;){
             if(check[y][x]==0)
                 s+=a[x-1],x--,y--;
             else if(check[y][x]==1)
                 s+=a[x-1],x--;
             else if(check[y][x]==2)s+=b[y-1],y--;
             if(!x)s+=b[y-1],y--;
             else if(!y)s+=a[x-1],x--;
             if(y<1 and x<1)break;
         }
         reverse(s.begin(), s.end());
         cout<<"\n"<<s<<"\n";
     }
    cout<<"\n";
    return 0;
}