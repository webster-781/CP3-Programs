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
const ll maxN = pow(2,18);
vl primes;

int gcd(int a, int b)
{
    return (b==0)?(a):(gcd(b,a%b));
}

int gcd_all(vi x, int i, int j) // gcd of x[i..j]
{
    if(i==j)
        return x[i];
    if(i==j-1)
        return gcd(x[i],x[j]);
    return gcd(gcd_all(x,i,(i+j)/2),gcd_all(x,((i+j)/2)+1,j));
}

int odd(int n)
{
    if(n%2)
        return n;
    return odd(n/2);
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

void solve(ll n)
{
    vi freq;
    ll x = abs(n);
    for(int y = 0; y < primes.size() && primes[y] <= sqrt(x); y++)
    {
        int cnt = 0;
        while(x%primes[y]==0)
        {
            x = x/primes[y];
            cnt++;
        }
        if(cnt)
            freq.pb(cnt);
    }
    if(x>1)
        freq.pb(1);
    if(n<0)
        cout<<odd(gcd_all(freq,0,freq.size()-1))<<endl;
    else
        cout<<gcd_all(freq,0,freq.size()-1)<<endl;
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