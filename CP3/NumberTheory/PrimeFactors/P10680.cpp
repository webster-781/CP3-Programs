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
const ll maxN = 1e6 + 200;
const int MOD = 10;
vl primes;

ld logb(ll n, ll b)
{
    return log(n)/log(b);
}

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

ll power(ll x, ll y)
{
    if(y==0)
        return 1;
    if(y==1)
        return x%10;
    ll t = (ll)pow(power(x,y/2),2);
    t = t%10;
    if(y%2)
        return (x*t)%10;
    return t;
}

void solve(ll n)
{
    ll ans = 1;
    ll up = (ll)(upper_bound(primes.begin(),primes.end(),n) - primes.begin());
    ll cnt2 = floorl(logb(n,2));
    ll cnt5 = floorl(logb(n,5));
    ll rest = cnt2-cnt5;
    // cout<<2<<" "<<rest<<endl;
    loop(i,0,up)
    {
        if(primes[i]==5)
            continue;
        if(primes[i]==2)
            ans = (ans * power(2,rest))%10;
        else
        {
        ll p = primes[i]%10;
        ll exp = floorl(logb(n,primes[i]));
        ans = (ans*power(p,exp))%10;
        // cout<<p<<" "<<exp<<endl;
        }
    }
    cout<<ans<<endl;
}

int main()
{
    sieve();
    ll n;
    while(cin>>n)
    {
        if(n==0)
            break;
        solve(n);
    }
}