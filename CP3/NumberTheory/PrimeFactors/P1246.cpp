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
const ll maxN = 1e4;
vl primes;
vector<bool> isPrime;
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
    isPrime = isp;
}

void solve(ll l, ll u)
{
    vl v;
    for(int i: primes)
    {
        ll p = pow(i,1);
        int e = 1;
        while(p<=u)
        {
            if(p>=l && isPrime[e+1])
                v.pb(p);
            p *= i;
            e++;
        }
    }
    sort(v.begin(),v.end());
    if(v.size() == 0)
    {
        cout<<-1<<endl;
        return;
    }
    loop(i,0,v.size()-1)
        cout<<v[i]<<" ";
    cout<<v.back()<<endl;
}

int main()
{
    sieve();
    ll L,H;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>L>>H;
        solve(L,H);
    }
}