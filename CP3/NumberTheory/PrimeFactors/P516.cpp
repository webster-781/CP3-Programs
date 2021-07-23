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
const long maxN = 65536;
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

void solve(ll n)
{
    if(n<0)
        cout<<n<<" = -1 x";
    else
        cout<<n<<" =";

    ll t = (n<0)?-n:n;
    for(int y = 0; primes[y]<=sqrt(t);y++)
    {
        ll x = primes[y];
        while(t%x==0)
        {
            t = t/x;
            if(t>1)
                cout<<" "<<x<<" x";
            else
            {
                cout<<" "<<x;
                break;
            }
        }
    }
    if(t>1)
        cout<<" "<<t;
    cout<<endl;
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