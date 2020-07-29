#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define cot cout.tie(0)
using namespace std;//coded by abhijay mitra
#define watch(x) cout << (#x) << " is " << (x) << endl
int main()
{
    ibs;cti;
        int n,k;cin>>n>>k;
        std::vector<int> v;cout<<"\n";cout.flush();
        for (int i = 0; i < k+1; ++i)
        {
            cout<<"? ";cout.flush();
            for (int j = 0; j < k+1; ++j)
                if(j!=i)cout<<j+1<<" ";cout.flush();
            int index,val;cin>>index>>val;v.pb(val);cout<<"\n";cout.flush();
        }
        int m=INT_MIN,mc=0;
        for (int i = 0; i < v.size(); ++i)
            m=max(m,v[i]);
        for (int i = 0; i < v.size(); ++i)
            if(m==v[i])mc++;
        cout<<"! "<<mc<<"\n";cout.flush();return 0;   
}