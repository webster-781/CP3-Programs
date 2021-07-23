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
const ll maxN = 120;
vl primes;

int total(int a, int n)
{
    int cnt = 0;
    for(int x = a; x <= n; x*=a)
        cnt += (int)(n/x);
    return cnt;
}

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
    ll t = abs(n);
    int cnt = 1;
    cout<<setw(3)<<right<<n;
    cout<<"! =";
    for(int y = 0; primes[y]<=n;y++)
    {
        int t = total(primes[y],n);
        if(cnt == 16)
            cout<<endl<<setw(6)<<right<<" ";
        cout<<setw(3)<<right<<t;
        cnt++;
    }
    cout<<endl;
}

int main()
{
    sieve(); 
    ll n;
    while(cin>>n)
    {
        if(n==0)
            break;
        solve(n);
    }
}