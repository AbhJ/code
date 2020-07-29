#include <bits/stdc++.h>
#define ibs ios_base::sync_with_stdio(false)
#define ll long long int
#define cti cin.tie(0)
using namespace std;
ll a[10][100015];
int main()
{
    ibs;cti;int n,m;cin>>n>>m;string s;cin>>s;s=" "+s;
    for(int j=0;j<=9;j++)//what matters is absolutedifference of al elements before it
        for(int i=1;i<n+1;i++) a[j][i]=a[j][i-1]+abs(j-s[i]+'0');
    while(m--){
        int x;cin>>x;
        cout<<a[s[x]-'0'][x]<<"\n";
    }return 0;
}