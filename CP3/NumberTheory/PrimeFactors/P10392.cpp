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
const ll maxN = pow(2,25);
vl primes;

ll conv(string s, int j) // returns number of s[0..j]
{
    int c = (int)(s[j]-48);
    return (j==0)?c:(c*10 + conv(s,j+1));
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
    ll t = n;

    for(int y = 0; primes[y]<=sqrt(t);y++)
    {
        ll x = primes[y];
        while(t%x==0)
        {
            t = t/x;
            cout<<setw(4)<<left<<" ";
            cout<<x<<endl;
        }
    }
    if(t>1)
    {
        cout<<setw(4)<<left<<" ";
        cout<<t<<endl;
    }
    cout<<endl;
}

int main()
{
    sieve(); 
    ll n;
    while(cin>>n)
    {
        if(n<0)
            break;
        solve(n);
    }
}