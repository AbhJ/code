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
    #define cot cout.tie(0)//solved by abhijay mitra
    using namespace std;
    #define watch(x) cout << (#x) << " is " << (x) << endl
    int main(){
        ibs;cti; 
        int T;
        cin>>T;
        while(T--){
                int n;ll x;cin>>n;std::vector<ll> v[n];
                for (int i = 0; i < n; ++i)
                {
                    for (int j = 0; j < n; ++j)
                    {
                       cin>>x; v[i].pb(x);
                    }
                    sort(v[i].begin(), v[i].end());
                }
                std::vector<ll> e(n);
                e[n-1]=v[n-1][n-1];ll sum=e[n-1];
                for (int i = n-2; i >-1; --i)
                {
                    int j=n-1;
                    while((v[i][j]>=e[i+1])&&(j>=0))
                        j--;
                    if (j<0)
                    {
                        sum=-1;break;
                    }
                    e[i]=v[i][j];sum+=e[i];
                }
                cout<<sum<<"\n";
            }
        return 0;
    }