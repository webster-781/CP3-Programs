//MAKER CODE

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
vl out;
void solve()
{
    int n;
    cin>>n;
    vl v(n,0);
    loop(i,0,n)
        cin>>v[i];
    sort(v.begin(),v.end());
    out.push_back((v.back() - v[0])*2);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
    for(auto u : out)
        cout<<u<<endl;
}