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
long maxN = 1e6;
pair<vector<bool>,vl> sieve()
{
    vector<bool> isp(maxN,true);
    vl ans;
    for(long i=2; i<maxN; i++)
    {
        if(isp[i])
        {
            for(long j = i*i; j< maxN; j+=i)
                isp[j] =false;
            ans.pb(i);
        }
    }
    return make_pair(isp,ans);
}
void solve(long n)
{
    for(long x: primes)
    {
        if((n-x)>=2 && isPrime[n-x])
        {
            cout<<n<<" = "<<x<<" + "<<(n-x)<<endl;
            return;
        }
    }
}

int main()
{
    auto x = sieve();
    primes = x.second;
    isPrime = x.first;
    long n;
    while((cin>>n))
    {
        if(n==0)
            break;
        solve(n); 
    }
}