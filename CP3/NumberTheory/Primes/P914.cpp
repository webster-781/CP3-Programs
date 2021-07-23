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


void solve()
{
    long l, u;
    cin>>l>>u;
    // cout<<l<<" "<<u<<endl;
    auto x = lower_bound(primes.begin(),primes.end(),l);
    int i = x - primes.begin();
    // cout<<i<<" "<<primes.size()-1<<endl;
    if(i>=primes.size()-1)
    {
        cout<<"No jumping champion\n";
        return;
    }
    vector<long> v;
    map<long,int> m;
    // cout<<(u)<<endl;
    while((i<primes.size()-1) && (primes[i+1] <= u))
    {
        // cout<<primes[i]<<" "<<primes[i+1]<<endl;
        int diff = primes[i+1]-primes[i];
        if(m.count(diff) == 0)
        {
            v.pb(diff);
            m[diff] = 1;
        }
        else
            m[diff]++;
        i++;
    }
    if(v.size()==0)
    {
        cout<<"No jumping champion\n";
        return;
    }

    // for(int i: v)
    // {
    //     cout<<i<<" "<<m[i]<<endl;
    // }
    int mcnt = v[0];
    bool collide = false;
    loop(i,1,v.size())
    {
        if(m[v[i]]==m[mcnt])
            collide = true;
        else if(m[v[i]]>m[mcnt])
        {
            mcnt = v[i];
            collide = false;
        }
    }
    if(collide)
        cout<<"No jumping champion\n";
    else
        cout<<"The jumping champion is "<<mcnt<<endl;
}


int main()
{
    auto x = sieve();
    primes = x.second;
    isPrime = x.first;
    int t;
    cin>>t;
    while(t--)
    {
        solve(); 
    }
}