#include <bits/stdc++.h>
#include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
// const int N=2e6+3;
const ll M =  998244353; // modulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
int S[2];
void solve(){
 map<string,int>m;set<int>s[2];S[1]=S[0]=0;int n;
 cin>>n;string x;
 for (int i = 0; i < n; ++i)
 {
   cin>>x;int N=x.length();
   if(x[0]==x[N-1])//no need of reversal
   {
    S[x[0]-'0']++;continue;
   }
   //there may be need of reversal
   string r=x;reverse(x.begin(), x.end());
   m[x]=i+1;
   if(m[r])//if its reverse already exists
    s[r[0]-'0'].erase(m[r]);//we remove previous occurrence
   else s[x[0]-'0'].insert(i+1);
 }
 if(S[0]+S[1]==n)if(S[0]and S[1]){cout<<-1;return;}
 int pos;if(s[1].size()>s[0].size())pos=1;else pos=0;
 int ans=s[pos].size()-s[pos^1].size(),c=1;
 ans/=2;cout<<ans<<"\n";
 for(int i:s[pos])if(c<=ans)
  cout<<i<<" ",c++;
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