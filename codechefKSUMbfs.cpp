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
        int n,k;cin>>n>>k;std::vector<ll> A(n);
        priority_queue<ll> B;
        for (int i = 0; i < n; ++i)
            cin>>A[i];
        for (int i = 0; i < n; ++i)
        {
            ll s=0;
            for (int j = i; j < n; ++j)
            {
                s+=A[j];B.push(s);

            }
        }
        for (int i = 0; i < k; ++i)
        {
            cout<<B.top()<<" ";B.pop();
        }
        return 0;
    }