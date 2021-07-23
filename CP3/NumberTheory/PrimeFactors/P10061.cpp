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
const ll maxN = pow(2,25);
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

ld logb(ll n, int b)
{
    return((double)log(n)/(double)log(b));
}

ll total(ll n, int x)    // return (# of x in n!)
{
    ll t = 0;
    for(ll i = x; i<=n; i*=x)
        t += (ll)(n/i);
    return t;
}

ll answer(ld dig)
{
    ld x = ceill(dig);
    // cout<<x<<endl<<abs(x-dig)<<endl;
    // cout<<"\n"<<((abs(x-dig)<1e-7)?"True":"False")<<endl;
    if(abs(x-dig)<1e-7)
        return x + 1;
    return ceill(dig);
}

ld space(ll n, int b, int x)    // return (# of x in n!)
{
    ld ans = ((ld)(total(n,x)))*(logb(x,b));
    return ans;
}

void solve(ll n, int b)
{
    if(n<=1)
    {
        cout<<0<<" "<<1<<endl;
        return;
    }
    ll x = abs(n);
    //  Find the frequency of the largest prime factor of n = freq
    int fmin = INT_MAX; // no. of tailing zeros
    int z = b;
    for(int y : primes)
    {
        if(z%y == 0)
        {
            // cout<<y<<": ";
            ll cnt= 0;
            while(z%y == 0)
            {
                z = z/y;
                cnt ++;
            }
            ll t = total(n,y)/(cnt);
            fmin = (fmin>t)?t:fmin;
            // cout<<cnt<<" "<<total(n,y)<<" "<<fmin<<endl;
        }
    }
    ld dig = 0;
    // for(int y = 0; primes[y]<=n && y<primes.size();y++)
    //     dig += space(n,b,primes[y]);

    for(ll y = 2; y<=n; y++)
        dig += logb(y,b);
    cout.precision(20);
    answer(dig);
    cout<<fmin<<" "<<answer(dig)<<endl;
}

int main()
{
    sieve();
    ll n;
    int b;
    while(cin>>n>>b)
    {
        solve(n,b);
    }
}