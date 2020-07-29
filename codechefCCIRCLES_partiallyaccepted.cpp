#include <bits/stdc++.h>
#define ll long long int
#define N 1000
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
using namespace std;int a[N];
#define watch(x) cout << (#x) << " is " << (x) << endl
int main(){
    ibs;cti;
    for (int i = 0; i < N; ++i)
    {
        a[i]=0;
    }
    int n,q;cin>>n>>q;pair<pair<double,double>,double> set;
    std::vector<pair<pair<double,double>,double>> v;
    for(int i=0;i<n;i++){
        cin>>set.first.first>>set.first.second>>set.second;
        for (int j = 0; j < i; ++j)
        {
            if (set==v[j])
            {
                a[i]++;
            }
        }
        if (a[i]==0)
        {
            v.pb(set);
        }
    }//create another array to remember how many times we have identical circles
    while(q--){
        int k,num=0;cin>>k;
        for (int i = 0; i < v.size(); ++i)
        {
            for(int j=i+1;j<v.size();j++){
                double dist=dis(v[i].first.first,v[i].first.second,v[j].first.first,v[j].first.second);
                double r1=v[i].second,r2=v[j].second;
                if (r2>r1)
                    swap(r1,r2);
                if (v[i]==v[j])
                {
                   continue;
                }
                if (dist>=(r1+r2))
                {
                    if (dist-r1-r2>k)
                        continue;
                    if(k>r1+r2+dist)
                        continue;
                    num+=(a[i]+1)*(a[j]+1); continue;
                }
                if (dist<=(r1-r2))
                {
                    if (k>dist+r2+r1)
                        continue;
                    if (k<r1-dist-r2)
                        continue;
                    num+=(a[i]+1)*(a[j]+1);continue;
                }
                if (k>r1+r2+dist)
                    continue;
                num+=(a[i]+1)*(a[j]+1);
            }
        }
    cout<<num<<"\n";
    }
    return 0;
}