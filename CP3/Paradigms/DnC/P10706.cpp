//MAKER CODE

#include<bits/stdc++.h>
#define loop(x,i,n) for(int x = i; x < n; ++ x)
#define looprev(x,i,n) for(int x = i;x>=n;x--)
#define lloop(x,i,n) for(ll x = i; x < n; ++ x)
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair <int,int> pii;
typedef map<int,int> mi;
typedef pair<long,long> pll;
vl l,s;

int dig(ll n)
{
    return ceil((double)log(n+1)/(double)log(10));
}

void call()
{
    l.pb(0);
    s.pb(0);
    ll i = 1;
    while(s.back()<=2147483647)
    {
        l.pb(l.back() + dig(i));
        s.pb(s.back()+l.back());
        // cout<<i<<" "<<l.back()<<" "<<s.back()<<endl;
        i++;
    }
}

int idig(ll n, int i)   // find i-th digit from left of n
{
    string s;
    while(n>0)
    {
        s += n%10 + 48;
        n /= 10;
    }
    reverse(s.begin(),s.end());
    return s[i-1] - 48;
}

int main()
{
    call();
    int t;
    cin>>t;
    while(t--)
    {
        ll x;
        cin>>x;
        int i = distance(s.begin(),lower_bound(s.begin(),s.end(),x));
        ll d1 = x - s[i-1];
        int j = distance(l.begin(),lower_bound(l.begin(),l.end(),d1));
        ll d2 = d1 - l[j-1];
        // cout<<i<<" "<<s[i-1]<<" "<<d1<<" "<<j<<" "<<l[j-1]<<" "<<d2<<" "<<idig(j,d2)<<endl;
        cout<<idig(j,d2)<<endl;
    }
}