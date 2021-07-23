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
const ll maxN = 5 * 1e4;
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

ll eulerphi(ll n)
{
    ll x = n;
    ll ans = n;
    for(int i = 0; i<primes.size() && primes[i]<=sqrt(x); i++)
    {
        if(x%primes[i] == 0)
        {
            while(x%primes[i]==0)
                x/=primes[i];
            ans -= ans/primes[i];
        }
    }
    if(x>1)
        ans -= ans/x;
    return ans;
}

ll solve(ll n)
{
    ll ans = 1;
    loop(i,2,n+1)
        ans += 2*eulerphi(i);
    return ans;
}

int main()
{
    sieve();
    ll n;
    while(cin>>n)
    {
        if(n==0)
            break;
        cout<<solve(n)<<endl;
    }
}