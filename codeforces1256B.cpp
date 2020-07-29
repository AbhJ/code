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
        ibs;cti;ll q,n;cin>>q;
        while(q--){cin>>n;std::vector<int> v(n);
            for (int i = 0; i < n; ++i){
                cin>>v[i];
            }
                int pos=0,pos_min=0;//we search all elements from pos to end to get minimum element and shift it to approporiate posiiton
                while(pos<n){
                    pos_min=min_element(v.begin()+pos, v.end())-v.begin();
                    int temp=v[pos_min];v.erase(v.begin()+pos_min);
                    v.insert(v.begin()+pos,temp);if(pos==pos_min)pos++;
                    else pos=pos_min;
                }
            for (int i = 0; i < n; ++i)
                cout<<v[i]<<" ";
            cout<<"\n";
        }
        return 0;   
    }