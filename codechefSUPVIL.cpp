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
        // cout<<"\n";     
        while(T--){
            string s;int n;cin>>n;int sup=0,vill=0;bool x=0,v=0,s1=0;
            for (int i = 0; i < n; ++i)
            {
                cin>>s;x=0;
                if((s.length()>2)){
                if((s.substr(s.length()-3,3)=="man"))
                sup++;else vill++;}else vill++;
                if ((vill-sup==3)and s1==0)
                {
                    x=1;v=1;
                }
                if ((sup-vill==2)and v==0)
                {
                    x=1;s1=1;
                }
            }
            if (x==0 and v==0 and s1==0)
            {
                cout<<"draw\n";
            }
            if(s1==1)
                cout<<"superheroes\n";
            if(v==1)
                cout<<"villains\n";
            }
        return 0;
    }
    