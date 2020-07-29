#include <bits/stdc++.h>
#include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=2e5+10;
const ll M =  998244353; // modulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
int C[N][26];
void solve(){
  string s;cin>>s;memset(C,0,sizeof(C));
  int n=s.length();int l,r;
  for (int i=1;i<=n;i++)
  {
    for (int j=0;j<26;j++)
    {
      C[i][j]=C[i-1][j];
    }
    C[i][s[i-1]-'a']++;
  }
  cin>>n;
  while(n--)
  {
    cin>>l>>r;l--,r--;
    if(l==r){cout<<"Yes\n";continue;}
    if(s[l]!=s[r]){cout<<"Yes\n";continue;}
    int c=0;r++,l++;
    for (int i = 0; i < 26; ++i)
    {
      if(C[r][i]>C[l-1][i])c++;
    }
    if(c>2)cout<<"Yes\n";else cout<<"No\n";
  }
}
int main()
{   
    ibs;cti;
      solve();
      cout<<"\n";
    return 0;
}