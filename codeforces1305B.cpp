#include <bits/stdc++.h>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define pb push_back
#define bp __builtin_popcount
using namespace std;//coded by abhijay mitra
void solve(){
     string s;cin>>s;
     int o=0,c=0,n=s.length();
     // std::vector<int> op,cl;
     // for (int i = 0; i < s.length(); ++i)
     // {
     //   if(s[i]=='(')o++,op.pb(i+1);else c++,op.pb(i+1);
     // }
     int count=0,i,j;
     std::vector<int> ans;
     for (i=0,j=n-1; i < n and j>i;)
     {
        if(s[i]=='(' and s[j]==')'){
          ans.pb(i+1);ans.pb(j+1);i++;j--;count+=2;
       }
       // cout<<i<<j;
       while(s[j]=='(')j--;
       while(s[i]==')')i++;
       // cout<<i<<" "<<j;
     }
     if(count)cout<<1<<"\n";
     cout<<count<<"\n";
     sort(ans.begin(), ans.end());
     for (int i = 0; i < ans.size(); ++i)
     {
       cout<<ans[i]<<" ";
     }
}
int main()
{   
    ibs;cti;
    // int t;cin>>t;
    // while(t--)
    solve(),cout<<"\n";
    return 0;
}