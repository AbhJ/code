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
    #define cot cout.tie(0)//solved in time complexity o[pow(n,2)]
    using namespace std;/*ll c[N];*/
    #define watch(x) cout << (#x) << " is " << (x) << endl
    int main(){
        ibs;cti; 
        int T;
        cin>>T;
        while(T--){
                int n,k;ll m;/*bool check=0;*/
                priority_queue<int>pq;
                for (int i = 0; i < n; ++i)
                {
                    cin>>c;if(c)pq.push(c);
                }
                int days =(z-b-1)/y;//-1 as this this the last day before b reeaches z
                a+=days*x;b+=days*y;ll j=0;
                while(a<z && pq.size()!=0){
                    j++;
                    ll foo=pq.top();pq.pop();
                    a+=foo;if(foo)pq.push(foo/2);
                }
                if (a<z)
                    cout<<"RIP";
                else cout<<j;
                cout<<"\n";
            }
        return 0;
    }