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
    #define cot cout.tie(0)//solved by abhijay mitra
    using namespace std;bool a[26];int num[10];int counter;
    #define watch(x) cout << (#x) << " is " << (x) << endl
    bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){
        return (a.second < b.second);
    }
    int capture(pair<int,int> k,std::vector<pair<int,int>> v){
        int x =k.first,y=k.second;
        if((x>N) or (x<1) or (y>N) /*or y<1*/)
            return 0;
        int c_1=capture({x-2,y+1},v),c_2=capture({x+2,y+1},v),
        c_3=capture({x-1,y+2},v),c_4=capture({x+1,y+2},v);
        for (int i = 0; i < v.size(); ++i){
            if(k==v[i]) return 1+ max(c_1,max(c_2,max(c_3,c_4)));
        }
        return max(c_1,max(c_2,max(c_3,c_4)));
    }
    int main(){
        ibs;cti; 
        int T;
        cin>>T;
        while(T--){
                int n;counter=0;cin>>n;char temp;pair<int,int> index_knight;
                std::vector<pair<int,int>> v;//index of pawn
                for (int i = 1; i <= n; ++i)
                {
                    for (int j = 1; j <= n; ++j)
                    {
                        cin>>temp;
                        if (temp=='K')
                            index_knight=make_pair(i,j);
                        if (temp=='P')
                            v.pb({i,j});
                    }
                }
                sort(v.begin(), v.end(), sortbysec);
                cout<< capture(index_knight,v)<<"\n";
            }
        return 0;
    }