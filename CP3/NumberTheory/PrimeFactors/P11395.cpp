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

ld logb(ll n, ll b)
{
    return log(n)/log(b);
}

void solve(ll n)
{
    ld x = n;
    ll pow2 = 1;
    ll odd = 0;
    while(pow2<=n)
    {
        ld p2 = pow2;
        ll t = (ll)sqrt(x/pow2);
        // cout<<pow2<<" "<<t<<endl;
        odd += (t+1)/2;
        pow2 *= 2;
    }
    cout<<n-odd<<endl;
}

int main()
{
    ll n;
    while(cin>>n)
    {
        if(n==0)
            break;
        solve(n);
    }
}