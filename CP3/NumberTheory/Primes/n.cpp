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

vl primes;
vector<bool> isPrime;
long maxN = 1e3 + 100;
void sieve()
{
    vector<bool> isp(maxN,true);
    for(long i=2; i<maxN; i++)
    {
        if(isp[i])
        {
            for(long j = i*i; j< maxN; j+=i)
                isp[j] =false;
            primes.pb(i);
        }
    }
    isPrime = isp;
}

int fastmod(int x, int e, int p)
{
    if(e==0)
        return 1;
    int t = fastmod(x,e/2,p);
    t = (t*t)%p;
    if(e&1)
        return (t*x)%p;
    return t;
}


int main()
{
    sieve();
    for(int p : primes)
    {
        cout<<p<<": ";
        int n= p-2;
        loop(a,3,p)
        {
            int ans = fastmod(2,n,p)*a;
            ans%=p;
            if(ans>3)
            {
                cout<<a<<" "<<a<<" "<<ans<<endl;
                // break;
            }
        }
    }
}