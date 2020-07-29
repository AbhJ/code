#include <bits/stdc++.h>
#include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=2e6+10;
const ll M =  998244353; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
void solve(){
  int n;cin>>n;string s;cin>>s;
  string a,b;
  if(s[0]=='1')a+='0',b+='1';
  if(s[0]=='2')a+='1',b+='1';
  if(s[0]=='0')a+='0',b+='0';
  for (int i = 1; i < s.length(); ++i)
  {
    if(s[i]=='0'){
      a+='0';b+='0';
    }
    if(s[i]=='1'){
      if(a>b)a+='0',b+='1';
      else a+='1',b+='0';
    }
    if(s[i]=='2'){
      if(a>b)a+='0',b+='2';
      else if(a==b)a+='1',b+='1';
      else a+='2',b+='0';
    }
  }
  cout<<a<<"\n"<<b;
}
int main()
{   
    ibs;cti;
    int t;cin>>t;
    while(t--)
      solve(),
      cout<<"\n";
    return 0;
}