#include <bits/stdc++.h>//CHFDORA
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
using namespace std;//coded by abhijay mitra
#define watch(x) cout << (#x) << " is " << (x) << endl
// int a[10000][10000];
int main()
{
    int t;cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        std::vector<std::vector<int>> a;
        for(int i=0;i<n;i++)
        {
            std::vector<int> x(m);
            for(int j=0;j<m;j++)
            {
                cin>>x[j];
            }
            a.pb(x);
        }
        ll pair=0;
        int length,width,dim;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                length=min(i,n-i-1);
                width=min(j,m-j-1);
                dim=min(length,width);
                for (int i1 = 0; i1 <= dim; ++i1)
                {
                    if (a[i1+i][j]!=a[i-i1][j] or a[i][j+i1]!=a[i][j-i1])
                    {
                        break;
                    }else pair++;
                }
            }
        }
        cout<<pair<<"\n";
    }
    return 0;   
}