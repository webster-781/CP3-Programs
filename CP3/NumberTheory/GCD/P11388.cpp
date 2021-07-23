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
const long maxN = 5e4;

ll gcd(ll a, ll b)
{
    return (b==0)?abs(a):gcd(abs(b),abs(a)%abs(b));
}

void solve()
{
    ll g, l;
    cin>>g>>l;
    if(l%g)
        cout<<-1<<endl;
    else
        cout<<g<<" "<<l<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}