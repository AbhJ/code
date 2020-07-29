#include <bits/stdc++.h>
#define ll long long int
#define N 1000000
#define M 1000000007
#define f(i,a,b) for(ll i=(ll)a;i<=(ll)b;i++)
#define rf(i,a,b) for(ll i=(ll)a;i>=(ll)b;i--)
#define po pop_back
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define cot cout.tie(0)
using namespace std;int n=0;
#define watch(x) cout << (#x) << " is " << (x) << endl
int main()
{
    ibs,cti;
    int t;cin>>t;
    while(t--){
        int n;cin>>n;int len=0,k=0,index=0,diff,min_diff=INT_MAX;
        string s;cin>>s;std::vector<int> val;
        for (int i = 0; i < n; ++i)
        {
            bool check=0;diff=0;index=0;
            if(count(val.begin(),val.end(),s[i])>0)
                    continue;
            if(count(s.begin(),s.end(),s[i])>1){
                val.pb(s[i]);
                for (int j = 0; j < n; ++j)
                {
                    if (s[j]==s[i])
                    {
                        if (check==1)
                        {
                            diff=j-index;
                        }
                        if (diff<min_diff and check==1)
                        {
                            min_diff=diff;
                        }
                        check=1;
                        index=j;
                    }
                }
            }
        }
        if (min_diff==INT_MAX)
        {
            cout<<0<<"\n";continue;
        }
        cout<<n-min_diff<<"\n";
    }
    return 0;
}