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

void find_pairs() // finds number of pairs with gcd = 1
{
    nump[1] = 0;
    loop(i,2,maxN+1)
    {
        nump[i] = nump[i-1];
        loop(j,1,i)
        {
            if(gcd(i,j) == 1)
                nump[i] ++;
        }
        // cout<<i<<" "<<nump[i]<<endl;
    }
}

void solve(int n)
{
    ll ans = 0;
    loop(x,1,n+1)
    {
        int t= n/x;
        ans += x*nump[t];
    }

    // loop(i,1,n+1)
    // {

    // }
    cout<<ans<<endl;
}

int main()
{
    find_pairs();
    int t;
    while(cin>>t)
    {
        if(!t)
            return 0;
        solve(t);
    }
}