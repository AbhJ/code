#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
using namespace std;//coded by abhijay mitra
#define N 100000 
#define M 1000000007
int main()
{   
    ibs;cti;
    int t;cin>>t;
    while(t--){
        int n;cin>>n;std::vector<int> v;
        for (int i=2; i<=sqrt(n); i++) 
        { 
            std::vector<int> temp,temper;
            if (n%i == 0) 
            { 
                temp.pb(i);temper.pb(n/i);bool c1=0,c2=0;
                for (int j = i+1; j < sqrt(n/i); ++j)
                {
                    if(((n/i)%j) == 0 and j!=temp[0] and (n/j)!=temp[0]){
                        temp.pb(j);temp.pb(n/(i*j));c1=1;break;
                    }
                }
                if(c1){v=temp;break;}
            }
        }
        if(v.empty())cout<<"NO\n";
        else {
            cout<<"YES\n";
            for (int i = 0; i < 3; ++i)
            {
                cout<<v[i]<<" ";
            }cout<<"\n";
        }
    }
    return 0;
}