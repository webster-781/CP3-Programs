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


void findPair(long n)
{
    auto t = lower_bound(primes.begin(), primes.end(), n);
    int x = t - primes.begin();
    for(auto i: primes)
    {
        if(isPrime[n-i])
        {
            cout<<i<<" "<<(n-i)<<endl;
            return;
        }
    }
}

void solve(long n)
{
    if(n<8)
    {
        cout<<"Impossible.\n";
        return;
    }
    if(n%2==0)
    {
        cout<<"2 2 ";
        findPair(n-4);
    }
    else
    {
        cout<<"2 3 ";
        findPair(n-5);
    }
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