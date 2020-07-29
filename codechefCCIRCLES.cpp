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
double dis(double x1, double y1, double x2, double y2)
{
    double x = x1 - x2; //calculating number to square in next step
    double y = y1 - y2;
    double dist;

    dist = pow(x, 2) + pow(y, 2);       //calculating Euclidean distance
    dist = sqrt(dist);                  

    return dist;
}
using namespace std;int a[N+1];
#define watch(x) cout << (#x) << " is " << (x) << endl
int main(){
    ibs;cti;
    for (int i = 0; i < N+1; ++i)
    {
    	a[i]=0;
    }
    int n,q;cin>>n>>q;pair<pair<double,double>,double> set;
    std::vector<pair<pair<double,double>,double>> v;
    for(int i=0;i<n;i++){
        cin>>set.first.first>>set.first.second>>set.second;v.pb(set);
    }
    double maxd,mind;int low,high;
    for (int i = 0; i < n-1; ++i)
    {
    	for (int j = i+1; j < n; ++j)
    	{
    			double dist=dis(v[i].first.first,v[i].first.second,v[j].first.first,v[j].first.second);
                double r1=v[i].second,r2=v[j].second;
                if (r2>r1)swap(r1,r2);
                if (dist>=(r1+r2))
                {
                    mind=dist-r1-r2;
                    maxd=r1+r2+dist;
                    low=ceil(mind);high=floor(maxd);if (maxd>N) high=N;
                    a[low]++;a[high+1]--;
                    continue;
                    // num+=(a[i]+1)*(a[j]+1); continue;
                }
                if (dist<=(r1-r2))
                {
                    maxd=dist+r2+r1;
                    mind=r1-dist-r2;
					low=ceil(mind);high=floor(maxd);if (maxd>N) high=N;
					a[low]++;a[high+1]--;
                    continue;
                    // num+=(a[i]+1)*(a[j]+1);continue;
                }
                maxd=r1+r2+dist;
                mind=0;
                low=ceil(mind);high=floor(maxd);if (maxd>N) high=N;
                a[low]++;a[high+1]--;
                // num+=(a[i]+1)*(a[j]+1);
    	}
    }
    for (int i = 1; i < N+2; ++i)
    {
    	a[i]+=a[i-1];
    }
    while(q--){
        int k,num=0;cin>>k;
        cout<<a[k]<<"\n";
}
return 0;}