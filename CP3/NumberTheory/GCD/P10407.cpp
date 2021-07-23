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
const long maxN = 1e8;

ll gcd(ll a, ll b)
{
    return (b==0)?abs(a):gcd(abs(b),abs(a)%abs(b));
}

ll gcd_all(vl a, int i , int j, ll sub)
{
    if(i==j)
        return a[i]-sub;
    if(j-i == 1)
        return gcd(a[i]-sub,a[j]-sub);
    return gcd(gcd_all(a,i,(i+j)/2,sub),gcd_all(a,((i+j)/2) + 1,j,sub));
}

void solve(vl a)
{
    sort(a.begin(),a.end());
    vl diff;
    loop(i,0,a.size()-1)
    {
        diff.pb(a[i+1]-a[i]);
    }
    cout<<gcd_all(diff,0,diff.size()-1,0)<<endl;
}

int main()
{
    ll i;
    vl x;
    while(cin>>i)
    {
        if(i==0)
            break;
        x.pb(i);
        while(cin>>i)
        {
            if(i==0)
                break;
            x.pb(i);
        }
        solve(x);
        x.clear();
    }
}