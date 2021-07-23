//MAKER CODE

#include<bits/stdc++.h>
#define loop(x,i,n) for(int x = i; x < n; ++ x)
#define looprev(x,i,n) for(int x = i;x>=n;x--)
#define lloop(x,i,n) for(ll x = i; x < n; ++ x)
#define pb push_back
using namespace std;
typedef long double ld;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair <int,int> pii;
typedef map<int,int> mi;
const ll maxN = 100;
vl primes;

void sieve()
{
    vector<bool> isp(maxN+1,true);
    lloop(i,2,maxN+1)
    {
        if(isp[i])
        {
            primes.pb(i);
            for(ll j = i*i; j<=maxN; j+= i)
                isp[j] = false;
        }
    }
}

ll total(ll n, int x)    // return (# of x in n!)
{
    ll t = 0;
    for(ll i = x; i<=n; i*=x)
        t += (ll)(n/i);
    return t;
}

void solve(ll n, ll d)
{
    if(n==0)
        n = 1;
    map<int,int> n1, d1;
    ll x = d;
    for(int y: primes)
    {
        int cnt = 0;
        d1[y] = 0;
        while(x%y == 0)
        {
            x = x/y;
            d1[y] ++;
        }
    }
    if(x>1)
    {
        cout<<0<<endl;
        return;
    }

    ll prod = 1;
    for(int y: primes)
    {
        int cnt = 0;
        n1[y] = total(n,y);
        if(n1[y]<d1[y])
        {
            cout<<0<<endl;
            return;
        }
        prod *= (n1[y] - d1[y] + 1);
    }
    cout<<prod<<endl;
}

int main()
{
    sieve();
    ll m,n;
    while(cin>>n>>m)
    {
        if(n==0 && m==0)
            return 0;
        solve(n,m);
    }
}