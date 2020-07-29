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
    #define cot cout.tie(0)//solved by abhijay mitra
    using namespace std;int v[N];
    #define watch(x) cout << (#x) << " is " << (x) << endl
    int main(){
        ibs;cti; 
        int T;
        cin>>T;
        while(T--){
                int n,k,emp=0,max_con=0;cin>>n;int x;
                std::vector<int> v(n);
                string s;cin>>s;
                for (int i = 0; i < n; ++i){
                    x=s[i]-'0';if (x==0)
                    emp++;v[i]=x;
                }
                bool check=0;
                for (int i = 0; i < n; ++i)
                {
                    if ((v[i]==0)and(v[(i+n-1)%n]==1)){
                        int len = 1;
                    while(v[(i+1)%n] == 0) {
                        ++len;
                        ++i;
                    }
                    max_con = max(max_con, len);
                    }
                }
                cout<<"\n"<<emp-max_con;
            }
        return 0;
    }