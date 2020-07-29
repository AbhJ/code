#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl
ll countSetBits(ll n) 
{ 
    // base case 
    if (n == 0) 
        return 0; 
    else
        return 1 + countSetBits(n & (n - 1)); 
}
int main(){
    int t,n,x;
    cin>>t;
    while(t--){
        cin>>n;
        ll x[n];string s[n];
        for (int i = 0; i < n; ++i)
        {
            long long num;
            int decimalNum, ii, rem;
            cin >> num;

            decimalNum = 0;
            ii = 0;

           //converting binary to decimal
            while (num != 0)
            {    
              rem = num % 10;
              num /= 10;
              decimalNum += rem * pow(2, ii);
              ++ii;
            }
            x[i]=decimalNum;
            if (i)
            {
                x[i]=x[i]^x[i-1];
            }
        }
        cout<<countSetBits(x[n-1])<<"\n";
       
        /*return 0;*/

    }
    return 0;
}