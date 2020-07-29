#include <bits/stdc++.h>
#define ll long long int
#define N 100000
#define M 1000000007
#define f(i,a,b) for(ll i=(ll)a;i<=(ll)b;i++)
#define rf(i,a,b) for(ll i=(ll)a;i>=(ll)b;i--)
#define po pop_back
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define cot cout.tie(0)//solved in time complexity o[pow(n,2)]
using namespace std;ll c[N];
#define watch(x) cout << (#x) << " is " << (x) << endl
int main(){
    ibs;cti; 
    int T;
    cin>>T;
    while(T--){
            int n;ll a,b,x,y,z;cin>>n>>a>>b>>x>>y>>z;bool check=0;
            for (int i = 0; i < n; ++i)
                cin>>c[i];
            for (int i = 1; ; ++i)
            {
                for(int j=0;j<n;j++)
                {
                    sort(c,c+n);
                    if (c[n-1]==0)
                    {
                        cout<<"RIP"<<"\n";check=1;break;;
                    }
                    a+=c[n-1];c[n-1]/=2;
                }
                if (check)
                    {
                        check=0;break;
                    }
                if (a>=z&&b<z)
                {
                    cout<<i<<"\n";break;
                }
                a+=x;b+=y;
            }

        }
    return 0;
}