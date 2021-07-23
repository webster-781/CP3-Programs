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
typedef pair <ll,ll> pll;
typedef map<int,int> mi;
const long maxN = 32500;
vl primes;
vector<bool> isPrime;
map<int,int> m;
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
            m[i] = cnt++;
        }
    }
    isPrime =isp;
    return;
}

void print(int index, int count, int l, int u)
{
    if(count <= 2 || primes[index-count+1]<l || primes[index] > u)
        return;
    loop(i,index - count + 1,index)
        cout<<primes[i]<<" ";
    cout<<primes[index]<<endl;
}

void solve(int l, int u)
{
    if(l>u)
    {
        swap(l,u);
    }
    auto it = upper_bound(primes.begin(),primes.end(),l);
    int count = 1;
    int i = it - primes.begin();
    if(i<2 || primes[i-1] - primes[i-2] == primes[i] - primes[i-1])
        count = -1;
    for(i = it - primes.begin(); primes[i] <= u; i++)
    {
        if(i>=2 && primes[i] - primes[i-1] == primes[i-1] - primes[i-2])
        {
            if(count >= 0)
                count ++;
        }
        else
        {
            print(i-1,count,l,u);
            count = 2;
        }
    }
    if(i>2 && primes[i] - primes[i-1] != primes[i-1] - primes[i-2])
        print(i-1,count,l,u);
}

int main()
{
    sieve();
    int l,u;
    while(cin>>l>>u)
    {
        if(l==0 && u==0)
            break;
        solve(l,u);
    }
}