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
const ll maxN = 1e5;
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

void solve(ll n, ll b)
{
    if(n==1)
    {
        cout<<"Impossible to divide"<<endl;
        return;
    }
    int fmin = INT_MAX;
    ll x = b;
    for(int i= 0; primes[i]<=x && i<primes.size(); i++)
    {
        int cnt = 0;
        while(x%primes[i] == 0)
        {
            x = x/primes[i];
            cnt ++;
        }
        if(cnt>0)
        {
            int t = total(n,primes[i])/cnt;
            fmin = (fmin>t)?t:fmin;
            // cout<<primes[i]<<cnt;
        }
    }
    if(fmin == 0)
        cout<<"Impossible to divide"<<endl;
    else
        cout<<fmin<<endl;
}

int main()
{
    sieve();
    ll n, b;
    int t;
    cin>>t;
    loop(i,1,t+1)
    {
        cin>>b>>n;
        cout<<"Case "<<i<<":\n";
        solve(n,b);
    }
}