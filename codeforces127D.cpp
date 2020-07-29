#include <bits/stdc++.h>
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
using namespace std;//coded by abhijay mitra
const int N=3e6+3;
void solve(){
   string s;cin>>s;int n=s.length();std::vector<int> f(N,0);
   int j=0;
   for (int i=1;i<n;i++){
       while(j and s[i]!=s[j])j=f[j];
       if(s[i]==s[j])j++;f[i+1]=j;       
   }
   if(!f[n]){cout<<"Just a legend";return;}
   if(*max_element(f.begin(),f.begin()+n)>=f[n]){cout<<s.substr(0,f[n]);return;}
   if(!f[f[n]]){cout<<"Just a legend";return;}
   cout<<s.substr(0,f[f[n]]);
}
int main()
{   
    ibs;cti;
    solve(),cout<<"\n";
    return 0;
}