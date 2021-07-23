//MAKER CODE

#include<bits/stdc++.h>
#define loop(x,i,n) for(int x = i; x < n; ++ x)
#define looprev(x,i,n) for(int x = i;x>=n;x--)
#define lloop(x,i,n) for(ll x = i; x < n; ++ x)
#define pb push_back
using namespace std;
typedef long double ld;
typedef unsigned long long LLU;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair <int,int> pii;
typedef map<int,int> mi;
const ll maxN = 1000;
ll prmsize;
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
    prmsize = primes.size();
}

map<int,int> factors(ll x)
{
    map<int,int> mx;
    for(int i : primes)
    {
        int cnt = 0;
        while(x%i == 0)
        {
            x = x/i;
            cnt++;
        }
        mx[i] = cnt;
    }
    return mx;
}

void solve(ll n, ll k)
{
    ll x = n;
    map<int,int> m;
    for(int i: primes)
            m[i] = 0;
    while(x>0)
    {
        auto mn = factors(x);
        for(int i: primes)
            m[i] = m[i] + mn[i];
        x = x-k;
    }
    ll prod = 1;
    for(int i : primes)
    {
        prod = prod*(m[i]+1);
        if(prod > 1e18)
            prod = 0;
    }
    if(prod == 0)
        cout<<"Infinity\n";
    else
        cout<<prod<<endl;
}

int main()
{
    sieve();
    int t;
    cin>>t;
    int i =1;
    while(i<=t)
    {
        string s;
        cin>>s;
        int j = s.length()-1;
        while(j>=0 && s[j] == '!')
            j--;
        string num = s.substr(0,j+1);
        stringstream ss(num);
        ll n;
        ss>>n;
        int k = s.length()-j-1;
        cout<<"Case "<<i<<": ";
        solve(n,k);
        i++;
    }
}