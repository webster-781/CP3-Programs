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
    if(n==1)
    {
        cout<<"2"<<endl;
        return;
    }
    ll x = n;
    ll ans = 0;
    int totcount = 0;
    for(int i= 0; primes[i]<= sqrt(x) && i<primes.size(); i++)
    {
        int cnt = 0;
        ll add = 1;
        if(x%primes[i]==0)
            totcount++;
        while(x%primes[i] == 0)
        {
            x = x/primes[i];
            cnt ++;
            add *= primes[i];
        }
        if(cnt>0)
            ans += add; 
        // cout<<primes[i]<<" "<<cnt<<endl;
    }
    if(x>1)
    {
        totcount ++;
        ans += x;
    }
    if(totcount == 1)
        cout<<1+ans<<endl;
    else
        cout<<ans<<endl;
}

int main()
{
    sieve();
    ll n;
    int i =1;
    while(cin>>n)
    {
        if(n==0)
            break;
        cout<<"Case "<<i<<": ";
        solve(n);
        i++;
    }
}