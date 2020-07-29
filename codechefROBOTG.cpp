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
    #define cot cout.tie(0)//solved by abhijay mitra in time O(nms)
    using namespace std;int v[N];
    #define watch(x) cout << (#x) << " is " << (x) << endl
    int main()
    {
        ibs,cti;
        int t;cin>>t;ll n,m;string s;ll x=0,y=0;bool chekc=0;
        while(t--){
            cin>>n>>m>>s;ll up=0,down=0,left=0,right=0;
                for (int j = 0; j < n; ++j)
                {
                    for (int k = 0; k < m; ++k)
                    {
                        y=j;x=k;chekc=0;
                        for (int i = 0; i < s.length(); ++i){
                            if (s[i]=='L')
                                x--;
                            if (s[i]=='R')
                                x++;
                            if (s[i]=='U')
                                y--;
                            if (s[i]=='D')
                                y++;
                            if (x==m or y==n or x+1==0 or y+1==0)
                                break;
                        }
                        if (x<m and y<n and x+1>0 and y+1>0)
                        {
                            chekc=1; cout<<"safe\n";break;
                        }
                    }
                    if (chekc==1)
                    {
                        break;
                    }
                }
                if (chekc==0)
                {
                    cout<<"unsafe\n";
                }
                
        }
        return 0;
    }