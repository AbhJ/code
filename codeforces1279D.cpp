    #include <bits/stdc++.h>
    #define ll long long
    #define ibs ios_base::sync_with_stdio(false)
    #define cti cin.tie(0)
    #define pb push_back
    using namespace std;//coded by abhijay mitra
    #define watch(x) cout << (#x) << " is " << (x) << endl
    #define M 998244353
    std::vector<int> v[1000000],p[1000000];
    ll pw(int a, int n) {
        int res = 1;
        while (n > 0) {
            if (n & 1) res = 1LL * res * a % M;
            a = 1LL * a * a % M;
            n >>= 1;
        }
        return res;
    }
    int main()
    {
        ibs;cti;int n;cin>>n;
        int k;
        for (int i = 0; i < n; ++i)
        {
            cin>>k;v[i].resize(k);
            for (int j = 0; j < k; ++j)
            {
                cin>>v[i][j];//stores the jth choice of ith kid
                v[i][j]--;
                p[v[i][j]].pb(i);//stores indces of kids taking the ith present where i<n
            }
        }
        //let's implement the algorithm
        int ans=0;
        for (int i = 0; i < 1000000; ++i)//choosing a gift at a time
        {
            for (int j = 0; j < p[i].size(); ++j)//p[i].size()is number of kids wanting the ith gift
            {
                int g=v[p[i][j]].size();//p[i][j] is the index of the jth kid wanting the ith gift
                //g stores the k of each kid wanting the ith gift
                ans+=1LL*p[i].size()*pw(g,M-2)%M;
                if(ans>=M)ans-=M;
            }
        }
        ans=1LL*ans*pw(n,M-2)%M*pw(n,M-2)%M;
        cout<<ans<<"\n";
        return 0;
    }