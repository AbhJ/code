#include <bits/stdc++.h>
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
using namespace std;//coded by abhijay mitra
void solve(){
    int n,m;cin>>n>>m;string s[n];
    bool a[n][m];//whether work done on that cell or not
    for (int i = 0; i < n; ++i)
        cin>>s[i];
    for (int i = 0; i < n; ++i)
    {
        for(int j=0;j<m;j++){
            if(s[i][j]=='.')
                a[i][j]=0;
            else a[i][j]=1;
        }
    }
    for(int i=0;i<n-2;i++)
        for(int j=0;j<m-2;j++)
        {
            if( (s[i][j]=='#') and (s[i][j+1]=='#')
                and (s[i][j+2]=='#') and (s[i+1][j]=='#')
                and (s[i+1][j+2]=='#') and (s[i+2][j]=='#')
                and (s[i+2][j+1]=='#') and (s[i+2][j+2]=='#') )
              {a[i][j]=0;a[i][j+1]=0;a[i][j+2]=0;
                a[i+1][j]=0;a[i+1][j+2]=0;a[i+2][j]=0;
                a[i+2][j+1]=0;a[i+2][j+2]=0;}
        }
    for (int i = 0; i < n; ++i)
        for(int j=0;j<m;j++)
            if(a[i][j]==1)
                {cout<<"NO";return;}
    cout<<"YES";
    }
int main()
{   
    ibs;cti;
    solve();cout<<"\n";
    return 0;
}