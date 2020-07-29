    #include <bits/stdc++.h>
    #define ll long long
    #define ibs ios_base::sync_with_stdio(false)
    #define cti cin.tie(0)
    #define pb push_back
    using namespace std;//coded by abhijay mitra
    #define watch(x) cout << (#x) << " is " << (x) << endl
    main()
    {
        ibs;cti;int n,m; cin>>n>>m;std::vector<int> v(n),a(n);string x;cin>>x;
        for (int i = 0; i < n; ++i){
            v[i]=x[i]-'0';a[i]=v[i];
        }
        for (int i = m; i<n; ++i){
                if(v[i]>v[i%m]){//then we rectify the first m numbers ofcourse, there is some non nine number below m here
                    a[m-1]++;int pos=m-1;
                    while(a[pos]==10){
                        a[pos]=0;a[pos-1]++;
                        pos--;
                    }
                }
                 if(v[i]!=v[i%m])break;
            }
            cout<<n<<"\n";
            for (int i = 0; i < n; ++i)
                cout<<a[i%m];
        }
