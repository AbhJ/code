#include <bits/stdc++.h>
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
using namespace std;//coded by abhijay mitra
void solve(){
     int n,x=0;cin>>n;
     string s;cin>>s;
     for(char a='z';a>='a';a--)for(int c=0;c<100;c++)for (int i = 0; i < s.size(); ++i)
     {
         if((s[i]==a)and((s[i+1]==a-1)or s[i-1]==a-1))
            x++,s.erase(i,1),i--;
     }
     cout<<x;
}
int main()
{   
    ibs;cti;
    solve();cout<<"\n";
    return 0;
}