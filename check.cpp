#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm> 
#include <cmath>
#include <cstdlib>
using namespace std;
#define ll long long 
#define gc getchar_unlocked
const ll int INF = 1e18;
#define MOD 100000000
bool check3(ll int a,ll int b,ll int c,ll int p,ll int q,ll int r)
{
	if(((a-p)==(b-q)) && ((b-q)==(c-r)))
		return true;
	if((p == 0) || (q == 0) || (r == 0))
	    return false;
	if((a%p == 0) && (b%q == 0) && (c%r == 0))
	{
		if(((a/p)==(b/q)) && ((c/r)==(b/q)))
			return true;
		return false;
	}
	return false;
}
bool check2(ll int x2,ll int y2,ll int x1,ll int y1)
{
	if((x2-x1)==(y2-y1))
		return true;
	if(x1 == 0 || y1 == 0)
	    return false;
	if((x2%x1 == 0) && (y2%y1 == 0))
	{
		if((x2/x1) == (y2/y1))
			return true; 
		return false;
	}
	return false;
}
bool f1(ll int a,ll int b,ll int c,ll int p,ll int q,ll int r,int num)
{
    if(num == 1)
    {
        if(p == (a-b-c+q+r))
            return true; 
        ll int p1 = p+b-q;
        if((p1 != 0 && r != 0) && ((a%p1==0)&&(c%r==0)) && ((a/p1) == (c/r)))
            return true; 
        if((q != 0) && (b%q == 0))
        {
            p1 = p*(b/q); 
            if((a-p1) == (c-r))
                return true;
            if((p1 != 0 && r != 0) && ((a%p1==0)&&(c%r==0)) && ((a/p1) == (c/r)))
                return true; 
        }
    }
    else
    {
        if(q == b-a-c+p+r)
            return true;  
        ll int q1 = q+a-p;
        if((q1 != 0 && r != 0) && ((b%q1==0)&&(c%r==0)) && ((b/q1) == (c/r)))
            return true;
        if((p != 0) && (a%p == 0))
        {
            q1 = q*(a/p);
            if((b-q1) == (c-r))
                return true; 
            if((q1 != 0 && r != 0) && ((b%q1==0)&&(c%r==0)) && ((b/q1) == (c/r)))
                return true;
        }
    }
    return false;
}
bool f2(ll int a,ll int b,ll int c,ll int p,ll int q,ll int r)
{
    ll int p1,q1; 
    p1 = a-(c-r);
    q1 = b-(c-r);
    if((p1-p) == (q1-q)) 
        return true; 
    if((p!=0 && q!=0) && ((p1%p == 0)&&(q1%q == 0)) && ((p1/p == q1/q)))
        return true;
    if((r != 0) && (c%r == 0))
    {
        ll int d = c/r;
        if(d != 0)
        {
            p1 = a/d; q1 = b/d;
            if((p1-p) == (q1-q)) 
                return true;
            if((p!=0 && q!=0) && ((p1%p == 0)&&(q1%q == 0)) && ((p1/p == q1/q)))
                return true;
        }
        return false;
    }
    return false;
}
bool f3(ll int a,ll int b,ll int c,ll int p,ll int q,ll int r,int num1,int num2)
{
    ll int p1,q1,r1;
    if(num1 == 1 && num2 == 2)
    {
        p1 = p+c-r; q1 = q+c-r;
        if((a-p1 == b-q1)) 
            return true; 
        if((p1!=0 && q1!=0) && ((a%p1 == 0)&&(b%q1 == 0)) && ((a/p1 == b/q1)))
            return true;
        if((r != 0) && (c%r) == 0)
        {
            p1 = p*(c/r); q1 = q*(c/r);
            if((a-p1 == b-q1)) 
                return true; 
            if((p1!=0 && q1!=0) && ((a%p1 == 0)&&(b%q1 == 0)) && ((a/p1 == b/q1)))
                return true;
        }
    }
    else if(num1 == 1 && num2 == 3)
    {
        p1 = p+(b-q); r1 = r+(b-q); 
        if((a-p1 == c-r1)) 
            return true; 
        if((p1!=0 && r1!=0) && ((a%p1 == 0)&&(c%r1 == 0)) && ((a/p1 == c/r1)))
            return true;
        if((q != 0) && (b%q) == 0)
        {
            p1 = p*(b/q); r1 = r*(b/q);
            if((a-p1 == c-r1)) 
                return true; 
            if((p1!=0 && r1!=0) && ((a%p1 == 0)&&(c%r1 == 0)) && ((a/p1 == c/r1)))
                return true;
        }
    }
    else 
    {
        q1 = q+(a-p); r1 = r+(a-p);
        if((b-q1 == c-r1)) 
            return true; 
        if((q1!=0 && r1!=0) && ((b%q1 == 0)&&(c%r1 == 0)) && ((b/q1 == c/r1)))
            return true;
        if((p != 0) && (a%p) == 0)
        {
            q1 = q*(a/p); r1 = r*(a/p);
            if((b-q1 == c-r1)) 
                return true; 
            if((q1!=0 && r1!=0) && ((b%q1 == 0)&&(c%r1 == 0)) && ((b/q1 == c/r1)))
                return true;
        }
    }
    return false;
}
bool f4(ll int a,ll int b,ll int c,ll int p,ll int q,ll int r)
{
    //unordered_map<pair<pair<ll int,ll int>,ll int>,int> mp;
    set<pair<pair<ll int,ll int>,ll int> > s;
    set<pair<pair<ll int,ll int>,ll int> > :: iterator itr;
    vector<pair<pair<ll int,ll int>,ll int> > lines;
    s.insert(make_pair(make_pair(p,1),a));
    s.insert(make_pair(make_pair(q,1),b));
    s.insert(make_pair(make_pair(r,1),c));
    for(auto x : s)
    {
        lines.push_back(x);
    }
    if(lines.size() == 1)
        return true; 
    else if(lines.size() == 2)
    {
        ll int a1 = lines[0].first.first; ll int a2 = lines[1].first.first;
        ll int b1 = lines[0].first.second; ll int b2 = lines[1].first.second;
        ll int c1 = lines[0].second; ll int c2 = lines[1].second;
        if((a1*b2-a2*b1) != 0)
        {
            ll int det = (a1*b2-a2*b1);
            if(((c1*b2-c2*b1)%det)==0 && ((a1*c2-a2*c1)%det)==0) 
                return true;
        }
        return false;
    }
    else
    {
        int i,j; int cnt = 0; ll int x,y;
        for(i=0;i<3;i++)
        {
            for(j=i+1;j<3;j++)
            {
                ll int a1 = lines[i].first.first; ll int a2 = lines[j].first.first;
                ll int b1 = lines[i].first.second; ll int b2 = lines[j].first.second;
                ll int c1 = lines[i].second; ll int c2 = lines[j].second; 
                ll int det = (a1*b2-a2*b1);
                if(det == 0)
                    return false;
                else 
                {
                    if(((c1*b2-c2*b1)%det)==0 && ((a1*c2-a2*c1)%det)==0) 
                    {
                        if(cnt == 0)
                        {
                            x = (c1*b2-c2*b1)/det; y = (a1*c2-a2*c1)/det; cnt += 1;
                        }
                        else 
                        {
                            if((((c1*b2-c2*b1)/det) != x) || (((a1*c2-a2*c1)/det) != y))
                                return false; 
                        }
                    }
                    else 
                        return false;
                }
            }
        }
        return true;
    }
}
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
    	ll int p,q,r;
    	cin>>p>>q>>r;
    	ll int a,b,c;
    	cin>>a>>b>>c;
    	vector<pair<ll int,ll int> > not_ok;
    	if(p != a)
    		not_ok.push_back(make_pair(p,a));
    	if(q != b)
    		not_ok.push_back(make_pair(q,b));
    	if(r != c)
    		not_ok.push_back(make_pair(r,c));
    	if(not_ok.size() == 0)
    	{
    		cout<<"0\n"; continue;
    	}
    	if(not_ok.size() == 1)
    	{
    		cout<<"1\n"; continue;
    	}
    	if(not_ok.size() == 2)
    	{
    		bool flag = check2(not_ok[0].second,not_ok[1].second,not_ok[0].first,not_ok[1].first);
    		if(flag)
    		{
    			cout<<"1\n"; continue;
    		}
    		cout<<"2\n"; continue;
    	}
    	if(not_ok.size() == 3)
    	{
    		bool flag = check3(a,b,c,p,q,r);
    		if(flag)
    		{
    			cout<<"1\n"; continue;
    		}
    		bool flag1 = check2(a,b,p,q);
    		bool flag2 = check2(a,c,p,r); 
    		bool flag3 = check2(b,c,q,r);
    		if(flag1 || flag2 || flag3)
    		{
    			cout<<"2\n"; continue;
    		}
            bool flag4,flag5,flag6;
            flag1 = f1(a,b,c,p,q,r,1); flag2 = f1(a,b,c,p,q,r,2);
            flag3 = f1(b,c,a,q,r,p,1); flag4 = f1(b,c,a,q,r,p,2);
            flag5 = f1(a,c,b,p,r,q,1); flag6 = f1(a,c,b,p,r,q,2); 
            if(flag1 || flag2 || flag3 || flag4 || flag5 || flag6)
            {
                cout<<"2\n"; continue;
            }
            flag1 = f2(a,b,c,p,q,r); flag2 = f2(b,c,a,q,r,p); flag3 = f2(a,c,b,p,r,q);
            if(flag1 || flag2 || flag3)
            {
                cout<<"2\n"; continue;
            }
            flag1 = f3(a,b,c,p,q,r,1,2); flag2 = f3(a,b,c,p,q,r,2,3); flag3 = f3(a,b,c,p,q,r,1,3);
            if(flag1 || flag2 || flag3)
            {
                cout<<"2\n"; continue;
            }
            flag1 = f4(a,b,c,p,q,r);
            if(flag1)
            {
                cout<<"2\n"; continue;
            }
    		cout<<"3\n";
    		continue;
    	}
    }
}