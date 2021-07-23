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
const ll maxN = 4e2;
vl primes;
vl cnt(1e5+1,0);
vl sum(1e5+1,0);


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


void div(ll n)
{

    ll x = n;
    ll ans1 = 1;
    ll ans2 = 1;
    for(int i = 0; i< primes.size() && primes[i] <= sqrt(x); i++)
    {
        int cnt = 0;
        while(x%primes[i]==0)
        {
            x = x/primes[i];
            cnt++;
        }
        ans1 *= (cnt+1);
        ans2 *= ((pow(primes[i],cnt+1) - 1)/(primes[i] - 1));
    }
    if(x>1)
    {
        ans1 *= 2;
        ans2 *= (x+1);
    }
    cnt[n] = ans1;
    sum[n] = ans2;
}

void solve(int a, int b, int k)
{
    int in = ceil((double)a/(double)k);
    in *= k;
    ll d = 0, sig = 0;
    ll sum1=0,sum2=0;
    for(int i = in; i<=b; i+=k)
    {
        if(cnt[i] == 0) 
            div(i);
        // cout<<i<<" "<<cnt[i]<<" "<<sum[i]<<endl;
        sum1 += cnt[i];
        sum2 += sum[i];
    }
    cout<<sum1<<" "<<sum2<<endl;
}

int main()
{
    sieve();
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,k;
        cin>>a>>b>>k;
        solve(a,b,k);
    }
}