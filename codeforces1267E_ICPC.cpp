#include <bits/stdc++.h>
#define ll long long
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define pb push_back
#define N 200015
struct table{
    int val,id;
}a[101][101];
bool cmp(table a,table b)
{
    return a.val>b.val;
}
using namespace std;//coded by abhijay mitra
#define watch(x) cout << (#x) << " is " << (x) << endl
int main()
{
    ibs;cti;int n,m;cin>>n>>m;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j){
            cin>>a[j][i].val;
            a[j][i].id=i;
        }
    }
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n-1; ++j)
            a[j][i].val-=a[n-1][i].val;
    }
    int ans=0,pos=1,i;
    for (int j = 0; j < n-1; ++j)
    {
       sort(a[j],a[j]+m,cmp);
       int sum=a[j][0].val;
       for (i = 0; i < m and sum>=0; ++i)
           sum+=a[j][i+1].val;
       if(i>ans)
        ans=i,pos=j;
    }
    cout<<m-ans<<"\n";
    for(int i=ans;i<m;i++)
        cout<<a[pos][i].id+1<<" ";
    return 0;   
}