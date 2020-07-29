#include <bits/stdc++.h>
#include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=2e6+3;
const ll M =  998244353; // modulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
int b[N];
void solve(){
 int n,k;cin>>n>>k;std::vector<string> v(n);
 for (int i = 0; i < n; ++i)
 {
   cin>>v[i];
 }
 sort(v.begin(), v.end());int ans=0,c;
 for (int i = 0; i < n-k+1; i+=k)
 {
  string s1=v[i];if(i%k==0)c=-1;
   for (int j = 0; j < k; ++j)
   {
     // if(i+j==n){ans+=c;break;}
     string s=v[i+j];int l=0;
     for (int h = 0; h < min(s.length(),s1.length()); ++h)
     {
       if(s[h]==s1[h])l++;
     }
     if(c+1)c=min(l,c);else c=l;
   }
   // cout<<c;
   ans+=c;
 }
 cout<<ans;
}
int main()
{   
    ibs;cti;
    int t;cin>>t;
    for(int i=0;i<t;i++){
      cout<<"Case #"<<i+1<<": ";
      solve();cout<<"\n";
    }
    return 0;
}