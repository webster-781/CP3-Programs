#include<bits/stdc++.h>
#define loop(x,i,n) for(int x = i; x < n; ++ x)
#define looprev(x,i,n) for(int x = i;x>=n;x--)
#define lloop(x,i,n) for(ll x = i; x < n; ++ x)
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair <int,int> pii;
typedef map<int,int> mi;
vi out;

void solve()
{
    double a,b;
    cin>>a>>b;
    out.push_back(ceil((a-2.0)/3.0) * ceil((b-2.0)/3.0));
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    for(auto u: out)
        cout<<u<<endl;
}