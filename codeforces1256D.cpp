    #include <bits/stdc++.h>
    #define ll long long
    #define ibs ios_base::sync_with_stdio(false)
    #define cti cin.tie(0)
    #define pb push_back
    #define N 200015
    using namespace std;//coded by abhijay mitra
    ll a[1009];
    #define watch(x) cout << (#x) << " is " << (x) << endl
    int main()
    {
        ibs;cti;ll q,n,k;cin>>q;
        while(q--){
            string s,sol;cin>>n>>k>>s;int num=0,sum=0;bool c=0;
            for (int i = 0; i < n; ++i)
            {
                if(s[i]=='0'){
                    if(sum<k+1)//we increase sol as we can operate further
                        k-=sum,sol+='0';
                    else{
                        sol+=string(sum-k,'1');//we cannot operate further
                        sol+='0';sol+=string(k,'1');sol+=s.substr(i+1);
                        cout<<sol<<"\n";
                        c=1;
                        break;
                    }
                }
                else sum++;
            }
            if(!c){
                sol+=string(sum,'1');
                cout<<sol<<"\n";
            }
        }
        return 0;   
    }