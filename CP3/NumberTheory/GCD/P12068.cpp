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
const long maxN = 500;

int nump[maxN+1];

ll gcd(ll a, ll b)
{
    return (b==0)?abs(a):gcd(abs(b),abs(a)%abs(b));
}

ll lcm(ll a, ll b)
{
    return a*(b/gcd(a,b));
}

ll lcm_all(vl v, int i) // lcm of v[i],v[i+1]...end.
{
    if(i == v.size()-1)
        return v[i];
    return lcm(v[i],lcm_all(v,i+1));
}


ll sum_all(vl v)
{
    ll pd = lcm_all(v,0);
    ll s = 0;
    for(ll x: v)
        s += (pd/x);
    return s;
}

void solve(int ca)
{
    int n;
    cin>>n;
    vl v(n,0);
    loop(i,0,n)
        cin>>v[i];
    ll den = sum_all(v);
    ll num = n * lcm_all(v,0);

    ll g = gcd(den,num);
    cout<<"Case "<<ca<<": "<<(num/g)<<"/"<<(den/g)<<endl;
}

int main()
{
    int t;
    cin>>t;
    loop(i,1,t+1)
    {
        solve(i);
    }
}