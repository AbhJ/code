#include <bits/stdc++.h>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
using namespace std;//coded by abhijay mitra
void solve(){
     int n,m;cin>>n>>m;
     int a[n];int x,j=0;set<int>p;
     for (int i = 0; i < n; ++i)cin>>a[i];
     for (int i = 0; i < m; ++i)cin>>x,p.insert(x);
     for (int i = 1; i <= n; ++i)
       if(!p.count(i))sort(a+j,a+i),j=i;
     if(is_sorted(a,a+n))cout<<"YES\n";else cout<<"NO\n";
}
int main()
{   
    ibs;cti;
    int t;cin>>t;
    while(t--)
    solve(),cout<<"\n";
    return 0;
}