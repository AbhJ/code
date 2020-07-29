#include <bits/stdc++.h>
#include <numeric> 
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
vector<int> fa(int n1){
    vector<int> v;
    for(int i=1;i<=sqrt(n1);++i)
    {
        if(n1%i==0)
        {
            v.push_back(i);
            if(i*i!=n1)
                v.push_back(n1/i);
        }
    }
    return v;
}
void solve(){
    int n,m,k;cin>>n>>m>>k;std::vector<int> a(n),b(m);
    for (int i = 0; i < n; ++i)cin>>a[i];
    for (int i = 0; i < m; ++i)cin>>b[i];
    auto f=fa(k);ll ans=0;
    for (int i = 0; i < f.size(); ++i)
    {
        int l1=f[i],l2=k/f[i];int c1=0,c2=0,x=0;
        if((l1>n) or (l2>m))continue;
        for(int j=0;j<l1;j++)
            if(a[j]==1)x++;
        if(x==l1)c1++;
        for(int j=l1;j<n;j++){
            if(a[j-l1]==1)x--;
            if(a[j]==1)x++;
            if(x==l1)c1++;
        }
        x=0;
        for(int j=0;j<l2;j++)
            if(b[j]==1)x++;
        if(x==l2)c2++;
        for(int j=l2;j<m;j++){
            if(b[j-l2]==1)x--;
            if(b[j]==1)x++;
            if(x==l2)c2++;
        }
        // cout<<c1<<" "<<c2<<"\n";
        ans+=1LL*c1*c2;
    }
    cout<<ans;
}
int main()
{   
    ibs;cti;
    // int t;cin>>t;
    // while(t--)
    solve(),cout<<"\n";
    return 0;
}