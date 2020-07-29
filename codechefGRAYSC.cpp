#include <bits/stdc++.h>
#define ll long long
using namespace std;//coded by abhijay mitra
int main()
{
    int n;cin>>n;
    std::vector<unsigned ll> v(n+20,0);bool c=0;
    for (int i = 0; i < n; ++i)
        cin>>v[i];
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j<n; ++j)
            for (int k = j+1;k<n ; ++k)
                for (int z = k+1; z < n; ++z)
                    if(v[i]^v[j]^v[k]^v[z]==0){
                        cout<<"Yes";return 0;
                    }
    cout<<"No"; return 0;
}