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
const long maxN = 2e7;
vl primes;
vector<bool> isPrime;
int last ; // the last index of primes[] that we looked at.
vector<pll> twins;
void sieve()
{
    vector<bool> isp(maxN+1,true);
    isp[0] = false;
    isp[1] = false;
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

void find(int s)
{
    if(s<=twins.size())
    {
        printf("(%lld, %lld)\n", twins[s-1].first, twins[s-1].second);
    }
    else{
        while(twins.size()<s)
        {
            if(primes[last+1] - primes[last] == 2)
                twins.pb(pll(primes[last],primes[last+1]));
            last ++;
        }
        find(s);
    }
}

int main()
{
    sieve();
    long n;
    last = 0;
    while(cin>>n)
    {
        find(n);
    }
}