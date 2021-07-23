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
const ll maxN = 1e4;
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

void solve(ll a, ll c)
{
    if(c%a)
    {
        cout<<"NO SOLUTION\n";
        return;
    }

    ll x = c/a;
    ll b = 1;
    for(int i = 0; i<primes.size() && primes[i]<=sqrt(c); i++)
    {
        ll p = primes[i];
        if(x%p==0)
        {
            while(c%p == 0)
            {
                c /= p;
                b *= p;
            }
            while(x%p == 0)
                x /= p;
        }
    }
    b *= x;
    cout<<b<<endl;
}

int main()
{
    sieve();
    ll A,C;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>A>>C;
        solve(A,C);
    }
}