        #include <bits/stdc++.h>
        #define ll long long int
        #define N 100009
        #define M 1000000007
        #define rf(i,a,b) for(ll i=(ll)a;i>=(ll)b;i--)
        #define po pop_back
        #define pb push_back
        #define lb lower_bound
        #define ub upper_bound
        #define ibs ios_base::sync_with_stdio(false)
        #define cti cin.tie(0)
        #define cot cout.tie(0)
        using namespace std;//coded by abhijay mitra
        #define watch(x) cout << (#x) << " is " << (x) << endl
        int main()
        {
            ibs;cti;int n;cin>>n;std::vector<int> v(n+1,0);std::vector<bool> b(n+1,0);
            std::vector<int> c;
            for (int i = 1; i <=n; ++i)
            {
                cin>>v[i];b[v[i]]=1;
            }
            for (int i = 1; i < n+1; ++i)
            {
                if(b[i]==0)c.pb(i);
            }
            for (int i = 1; i < n+1; ++i)
            {
                if(v[i]!=0)cout<<v[i];
                else{
                    if(c.back()!=i){cout<<c.back();c.pop_back();}
                    else{cout<<c[0];c.erase(c.begin());}
                }
                cout<<" ";
            }
            return 0;   
        }