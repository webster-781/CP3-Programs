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
const long maxN = 5e4;

vl primes;

ll gcd(ll a, ll b)
{
    return (b==0)?abs(a):gcd(abs(b),abs(a)%abs(b));
}

ll gcd_all(vl a, int i , int j, ll sub)
{
    if(i==j)
        return a[i]-sub;
    if(j-i == 1)
        return gcd(a[i]-sub,a[j]-sub);
    return gcd(gcd_all(a,i,(i+j)/2,sub),gcd_all(a,((i+j)/2) + 1,j,sub));
}

void sieve()
{
    vector<bool> isp(maxN+1,true);
    lloop(i,2,maxN+1)
    {
        if(isp[i])
        {
            for(ll j = i*i; j<=maxN;j+=i)
                isp[j] = false;
            primes.pb(i);
        }
    }
}

void solve(ll x)
{
    ll n = x;
    ll ans = 1;
    for(ll i : primes)
    {
        int cnt = 0;
        while(n%i == 0)
        {
            cnt ++;
            n = n/i;
        }
        ans *=(2*cnt + 1);
    }
    if(n>1)
        ans *= 3;
    cout<<x<<" "<<(ans+1)/2<<endl;
}

int main()
{
    sieve();
    ll x;
    while(cin>>x)
    {
        if(x==0)
            break;
        solve(x);
    }
    return 0;
}