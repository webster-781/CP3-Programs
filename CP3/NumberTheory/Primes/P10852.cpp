//MAKER CODE

#include<bits/stdc++.h>
#define loop(x,i,n) for(int x = i; x < n; ++ x)
#define looprev(x,i,n) for(int x = i;x>=n;x--)
#define lloop(x,i,n) for(ll x = i; x < n; ++ x)
#define pb push_back
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair <int,int> pii;
typedef pair <ll,ll> pll;
typedef map<int,int> mi;
const long maxN = 32500;
vl primes;
vector<bool> isPrime;
void sieve()
{
    vector<bool> isp(maxN+1,true);
    isp[0] = false;
    isp[1] = false;
    int cnt = 0;
    for(ll i=2; i<=maxN; i++)
    {
        if(isp[i])
        {
            for(ll j = i*i; j<=maxN; j+=i)
                isp[j] =false;
            primes.pb(i);
        }
    }
    isPrime =isp;
    return;
}

void solve()
{
    int n;
    cin>>n;
    auto x = upper_bound(primes.begin(),primes.end(),n/2);
    cout<<(*x)<<endl;
}

int main()
{
    sieve();
    int t;
    cin>>t;
    while(t--)
        solve();
}