#include <bits/stdc++.h>
// #include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=2e5+10;
const ll M = 1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
map<int ,string>m;  
int a[N],n;
void f(int x){
  if(x<=0)return;
  // cout<<m.count(a[x]);
  string s=m[a[x]];
  f(x-s.length());
  cout<<s<<" ";
}
void solve(){
  cin>>n;
  string s;cin>>s;
  int x;cin>>x;
  for (int i = 0; i < x; ++i)
  {
    string y;cin>>y;/*reverse(y.begin(), y.end());*/
    ll k=0;
    for(int j=0;j<y.length();j++)k=(k*31)+tolower(y[j]);
    m[k]=y;
  }
  memset(a,-1,sizeof(a));a[0]=0;
  for(int i=0;i<n;i++){
    ll k=0;
    for(int j=i;j>=0;j--){
      k=(k*31)+s[j];
      if((a[j]!=-1) and (m.count(k))){
        a[i+1]=k;break;
      }
    }
  }
  f(n);
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
//the following piece of code 
// #include <bits/stdc++.h>
// // #include <numeric>
// #define ll long long int
// #define ibs ios_base::sync_with_stdio(false)
// #define cti cin.tie(0)
// #define bp __builtin_popcount
// #define pb push_back
// using namespace std;//coded by abhijay mitra
// const int N=5e3+10;
// const ll M = 1e9+7; // Mulo
// #define F first
// #define S second
// #define MAX 100 
// #define MAX_CHAR 26
// int n;
// map<string,int>S;
// std::vector<string> z;
// void solve(){
//   cin>>n;
//   string s;cin>>s;
//   int x;cin>>x;
//   std::vector<string> inp(x);
//   for (int i = 0; i < x; ++i)
//   {
    // string y;cin>>y;/*reverse(y.begin(), y.end());*/
//     inp[i]=y;
//     for (auto c=y.begin();c!=y.end();c++)
//     {
//       *c=tolower(*c);
//     }
//     // cout<<y;
//     S[y]=i;
//   }
//   reverse(s.begin(), s.end());
//   int j=0;
//   for (int i = n; i >=1; --i)
//   {
//     if(j>=n)break;
//     string t=s.substr(j,i);

//     if(S.count(t)){z.pb(inp[S[t]]),j+=i,i=n;}
//   }
//   reverse(z.begin(), z.end());
//   for (int i = 0; i < z.size(); ++i)
//   {
//     cout<<z[i]<<" ";
//   }
// }
// int main()
// {
//     // ibs;cti;
//     // int t;cin>>t;
//     // while(t--){
//       solve();
//       // cout<<len;
//       cout<<"\n";
//     // }
//     return 0;
//   }