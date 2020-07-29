#include <bits/stdc++.h>
#include <numeric> 
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define pb push_back
using namespace std;//coded by abhijay mitra
void solve(){
    int n;cin>>n;string s;cin>>s;std::vector<int> v,g,ans,an;
    for (int i = 0,j=n-1; i < n and j>-1; ++i,j--){
        if(s[i]=='>'){
            v.pb(i+1);
            g.pb(j+1);
            while(!g.empty())
                ans.pb(g.back()),g.pop_back();
        }
        else{
            g.pb(j+1);
            v.pb(i+1);
            while(!v.empty())
                an.pb(v.back()),v.pop_back();
        }
    }
    while(!v.empty()) an.pb(v.back()),v.pop_back();
    while(!g.empty()) ans.pb(g.back()),g.pop_back();
    for (int i = 0; i < n; ++i) cout<<ans[i]<<" ";cout<<"\n";
    for (int i = 0; i < n; ++i) cout<<an[i]<<" ";
}
int main()
{   
    ibs;cti;
    int t;cin>>t;
    while(t--)
    solve(),cout<<"\n";
    return 0;
}