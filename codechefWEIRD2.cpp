#include <bits/stdc++.h>
#define ll long long int
#define N 1000009
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
    ibs;cti;
    int t;cin>>t;
    while(t--){
        int n;cin>>n;std::vector<int> v(n);std::vector<int> f(N,0);
        // int max1=INT_MIN;
        for (int i = 0; i < n; ++i){
            cin>>v[i];f.at(v[i])++;/*max1=max(v[i],max1);*/
        }
        ll sum=0;
        for (int i = 0; i < n; ++i)
        {
            if(f[i]>=i){//we can take pair having both numbers ==i
                sum++;
                for (int j = i+1; j < n; ++j)//dissimilar pairs smaller number i big j
                {
                    if (f[j]>=i and f[i]>=j and f[i]>0 and f[j]>=0)
                    {
                        sum+=2;
                    }
                }
            }//if v[i]>n it contributes nothing to sum

        }
        cout<<sum-1<<"\n";
    }
    return 0;
}