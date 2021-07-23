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
typedef map<int,int> mi;
const long maxN = 1e8;
vl primes;
vector<bool> isPrime;

void solve(long n)
{
    if(n<4)
    {
        cout<<n<<" is not the sum of two primes!\n";
        return;
    }
    if(n%2==1)
    {
        if(!isPrime[n-2])
            cout<<n<<" is not the sum of two primes!\n";
        else
            cout<<n<<" is the sum of 2 and "<<(n-2)<<".\n";
        return;
    }
    auto t = lower_bound(primes.begin(), primes.end(), n/2);
    int x = t - primes.begin();
    if(primes[x] >= n/2)
        x--;
    if(x<0)
    {
        cout<<n<<" is not the sum of two primes!\n";
        return;
    }
    for(long i = x; i>=0; i--)
    {
        if(isPrime[n - primes[i]])
        {
            cout<<n<<" is the sum of "<<(primes[i])<<" and "<<(n-primes[i])<<".\n";
            return;
        }
    }
    cout<<n<<" is not the sum of two primes!\n";
}

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

int main()
{
    sieve();
    long n;
    while(cin>>n)
    {
        solve(n);
    }
}