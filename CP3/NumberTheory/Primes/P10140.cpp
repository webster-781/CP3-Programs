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
ll maxN = 46340;

vl getPrimes(ll l, ll u)
{
    vl pr;
    if(l<=2)
    {
        pr.pb(2);
        l = 3;
    }
    if(l%2==0 && l>2)
        l++;
    for(ll i = l; i <=u; i+=2)
    {
        bool f = true;
        for(int j : primes)
        {
            if(i==j)
            {
                break;
            }
            else if(i%j == 0)
            {
                f = false;
                break;
            }
        }
        if(f)
            pr.pb(i);
    }
    return pr;
}

pair<vector<bool>,vl> sieve()
{
    vector<bool> isp(maxN,true);
    vl ans;
    for(ll i=2; i<maxN; i++)
    {
        if(isp[i])
        {
            for(ll j = i*i; j< maxN; j+=i)
                isp[j] =false;
            ans.pb(i);
        }
    }
    return make_pair(isp,ans);
}


void solve(ll l, ll u)
{
    vl luprimes = getPrimes(l,u);
    if(luprimes.size()<2)
    {
        cout<<"There are no adjacent primes.\n";
        return;
    }
    else
    {
        ll x1 = luprimes[0], x2=luprimes[1], n1 = luprimes[0], n2=luprimes[1];
        lloop(i,1,luprimes.size()-1)
        {
            if(x2-x1 < luprimes[i+1]- luprimes[i])
            {
                x1 = luprimes[i];
                x2 = luprimes[i+1];
            }
            if(n2-n1 > luprimes[i+1]- luprimes[i])
            {
                n1 = luprimes[i];
                n2 = luprimes[i+1];
            }
        }
         cout<<n1<<","<<n2<<" are closest, "<<x1<<","<<x2<<" are most distant.\n";
    }
}

int main()
{
    auto x = sieve();
    primes = x.second;
    isPrime = x.first;
    ll l,u;
    while(cin>>l>>u)
    {
        solve(l,u); 
    }
}