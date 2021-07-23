//MAKER CODE

#include <bits/stdc++.h>
#define loop(x,i,n) for(int x = i; x < n; ++ x)
#define looprev(x,i,n) for(int x = i;x>=n;x--)
#define lloop(x,i,n) for(ll x = i; x < n; ++ x)
#define pb push_back
using namespace std;
typedef unsigned long long LLU;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair <int,int> pii;
typedef pair <ll,ll> pll;
typedef map<int,int> mi;
const long maxN = 100;
vl primes;
vector<bool> isPrime;
vi composite;

LLU power(LLU x, int y)
{
    if(y==0)
        return 1;
    if(y&1)
        return x*power(x*x,y>>1);
    return power(x*x,y>>1);
}

void comp()
{
    int i = 6; int previ = 4;
    composite.pb(4);
    while(i<=64)
    {
        if(!isPrime[i])
        {
            composite.pb(i);
            previ = i;
        }
        i++;
    }
}

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
    set<LLU> out;
    out.insert(1);
    LLU mx = power(2,16);
    LLU x;
    for(x = 2; x < mx; x++)
    {
        int i = 1;
        out.insert(power(x,4));
        while(log2(x) * composite[i] < 64)
        {
            out.insert(power(x,composite[i]));
            i++;
        }
    }
    for(LLU t: out)
        cout<<t<<endl;
}

int main()
{
    cout.precision(20);
    sieve();
    comp();
    solve();
    // for(int i : composite)
    // {
    //     cout<<i<<endl;
    // }
    // cout<<composite.size();
    // cout<<endl;
    // cout<<pow(2,61)<<endl;
    // cout<<pow(2,62)<<endl;
    // cout<<pow(2,63)<<endl;
    // cout<<pow(2,64)<<endl;
    // cout<<(1L<<64);
}